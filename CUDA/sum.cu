#include <iostream>
using namespace std;

const int n = 1000;

__global__ void add(int *array, int n)
{
    int base = blockIdx.x * threadIdx.x + threadIdx.x;
    int offset = blockDim.x * gridDim.x;

    for(int i = base; i < offset;i++) {
        array[i] = array[i] * array[i];
    }
}

int main() {
    int *a = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n;i++) a[i] = (int)i;

    int *cuda_buffer;
    cudaMalloc((void**)&cuda_buffer, sizeof(int) * n);

    cudaMemcpy(cuda_buffer, a, n * sizeof(int), cudaMemcpyHostToDevice);

    add<<<1,128>>>(cuda_buffer, n);

    cudaMemcpy(cuda_buffer, a, sizeof(int)*n, cudaMemcpyDeviceToHost);

    for(int i = 0; i < n;i++) cout << a[i] << endl;

    cudaFree(cuda_buffer);
    free(a);

    return 0;
}
