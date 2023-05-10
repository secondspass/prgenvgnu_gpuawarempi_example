#include <stdio.h>
#include <hipstuff.h>
#include <hip/hip_runtime.h>
#include <mpi.h>

// Macro for checking errors in CUDA API calls
#define cudaErrorCheck(call)                                                              \
do{                                                                                       \
        hipError_t cuErr = call;                                                             \
        if(hipSuccess != cuErr){                                                             \
                printf("CUDA Error - %s:%d: '%s'\n", __FILE__, __LINE__, hipGetErrorString(cuErr));\
                exit(0);                                                                            \
        }                                                                                     \
}while(0)


void hip_malloc(double** d_A, long int size) {
                cudaErrorCheck( hipMalloc(d_A, size) );
}

void hip_memcpy(double* dest, double* source, long int size) {
                cudaErrorCheck( hipMemcpy(dest, source, size, hipMemcpyHostToDevice) );
}

void hip_free(double* source) {
  cudaErrorCheck(hipFree(source));
}
