#include <iostream>
using namespace std;

__global__ void add(int *a, int size){

    int start = blockIdx.x * blockDim.x + threadIdx.x;
    int stride = blockDim.x * blockDim.x;

    for(int i = start; i < size;i += stride) {
        atomicAdd(&a[i], 12);
    }
}

int main() {

    const int n= 10000;

    int *a;
    cudaMallocManaged(&a, sizeof(int) * n);
    a[0] = 2;

    cudaStream_t streams[2];

    cudaStreamCreate(&streams[0]);
    cudaStreamCreate(&streams[1]);

    add<<<1,128,0, streams[0]>>>(a, n);
    add<<<1,128,0, streams[1]>>>(a, n);

    cudaDeviceSynchronize();

    cudaStreamDestroy(streams[0]);
    cudaStreamDestroy(streams[1]);

    cout << a[0] << endl;


    return 0;
}