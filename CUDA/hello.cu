#include <iostream>
using namespace std;

const int n = 100;

__global__ void mult(float *a) {
    for(int i = 0; i <n;i++) a[i] = 2*a[i];
}

int main() {
    
    float *a = (float*)malloc(sizeof(float) * n);
    for(int i = 0; i < n;i++) a[i] = (float)i;

    float *a_d; 
    cudaMalloc((void**)&a_d, sizeof(float) * n);

    cout << a[2] << endl;

    cudaMemcpy(a_d, a, sizeof(float)*n, cudaMemcpyHostToDevice);

    mult<<<1,1>>>(a_d);

    cudaMemcpy(a, a_d, sizeof(float)*n, cudaMemcpyDeviceToHost);

    cudaFree(a_d);

    cout << a[2] << endl;
    free(a);

    return 0;
}
