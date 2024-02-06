#include <iostream>
using namespace std;

__global__ void init(int *a, int n) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    int stride = blockDim.x * gridDim.x;
    for(int i = idx; i < n;i += stride) a[i] = 1.0;
}

__global__ void reduce(int *a, int n,int *result) {
    unsigned int size = blockDim.x/2;
    const unsigned int index = threadIdx.x;
    const unsigned int blockIndex = blockIdx.x * blockDim.x;

    __shared__ int array[128];
    a[index + blockIndex] = 1.0;
    array[index] = a[index + blockIndex];

    __syncthreads();

    while(size > 0) {
        // Reduce warp
        if(index < size) {
            array[index] += array[index + size];
        }
        size /= 2;
        __syncthreads();
    }

    if(index == 0) {
        // Atomic add
        atomicAdd(result, array[0]);
    }
}

int main() {

    const int n = 10000 * 128;
    int *a;

    int *result;

    cudaMallocManaged(&result, sizeof(int));
    cudaMalloc(&a, sizeof(int)*n);

    init<<<1,1024>>>(a,n);
    reduce<<<ceil(n / 256),256>>>(a, n, result);

    cudaDeviceSynchronize();

    cout << *result << endl;

    return 0;
}