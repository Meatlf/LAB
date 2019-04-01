//include,system
#include<iostream>

#include<cuda_runtime.h>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;
#include<time.h>
__global__ void vectorAdd(const float *A,const float *B,float *C,int numElements)
{
int i=blockDim.x*blockIdx.x+threadIdx.x;
if(i<numElements)
{
C[i]=A[i]+B[i];
}
}
int main(void)
{ // Print the vector length to be used, and compute its size
int numElements=5;
size_t size=numElements*sizeof(float);

// Allocate the host input vector A
float *h_A=(float *)malloc(size);
// Allocate the host input vector B
float *h_B = (float *)malloc(size);
// Allocate the host output vector C
float *h_C = (float *)malloc(size);
//Initialize the host input vectors
for(int i=0;i<numElements;++i)
{
h_A[i]=2;
h_B[i]=12;
}
//Allocate the device input vector A
float *d_A=NULL;
cudaMalloc((void **)&d_A,size);
//Allocate the device input vector B
float *d_B=NULL;
cudaMalloc((void **)&d_B,size);
//Allocate the device output vector C
float *d_C=NULL;
cudaMalloc((void **)&d_C,size);
//Copy the host input vector A and B in host memory to
//the device input vectors in device memory

cudaMemcpy(d_A,h_A,size,cudaMemcpyHostToDevice);
cudaMemcpy(d_B,h_B,size,cudaMemcpyHostToDevice);
//Launch the Vector Add CUDA Kernel
int threadsPerBlock=numElements;
int blocksPerGrid=1;

vectorAdd<<<blocksPerGrid,threadsPerBlock>>>(d_A,d_B,d_C,numElements);
//return the output vector d_A in device to the host output vectors in host

cudaMemcpy(h_C, d_C,size,cudaMemcpyDeviceToHost);
for(int i=0;i<numElements;i++)
{
 cout<<h_C[i]<<endl;
}
return 0;
}
