#include <iostream>
using namespace std;

const int n = 1000;

__global__ void find_maximum_kernel(int *array, int *max2, int *mutex, unsigned int n)
{
    unsigned int index = threadIdx.x + blockIdx.x*blockDim.x;
    unsigned int stride = gridDim.x*blockDim.x;

    const unsigned int SHARED_SIZE = 1024;
    __shared__ float cache[SHARED_SIZE];
    for (int i = threadIdx.x; i < SHARED_SIZE; i += blockDim.x) {
        cache[i] = 0;
    }

    __syncthreads();

    unsigned int offset = index;
    int temp = -1.0;

    while(offset < n){
        temp = max(temp, array[offset]);
        offset += stride;
    }

    cache[threadIdx.x] = temp;

    __syncthreads();

    // reduction
    // TODO: Write better code
    for(int i = 0; i < SHARED_SIZE;i++) {
        cache[0] = max(cache[0], cache[i]);
    }

    __syncthreads();

    if(threadIdx.x == 0){
        atomicMax(max2, cache[0]);
    }
}

int main() {
    
    int *a = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n;i++) a[i] = (int)i;

    int *a_d;
    int *device_max;
    int host_max;
    int *mutex;

    cudaMalloc((void**)&a_d, sizeof(int) * n);
    cudaMalloc((void**)&mutex,sizeof(int));
    cudaMalloc((void**)&device_max,sizeof(int));


    cudaMemcpy(a_d, a, sizeof(int)*n, cudaMemcpyHostToDevice);

    find_maximum_kernel<<<5,128>>>(a_d, device_max, mutex,  n);

    cudaMemcpy(&host_max, device_max, sizeof(int), cudaMemcpyDeviceToHost);

    cudaFree(a_d);

    cout << host_max << endl;
    free(a);

    return 0;
}
