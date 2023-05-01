// ***********************************************************************
//
// Demo program for education in subject
// Computer Architectures and Paralel Systems.
// Petr Olivka, dep. of Computer Science, FEI, VSB-TU Ostrava, 2020/11
// email:petr.olivka@vsb.cz
//
// Example of CUDA Technology Usage with unified memory.
//
// Manipulation with prepared image.
//
// ***********************************************************************

#include <cuda_device_runtime_api.h>
#include <cuda_runtime.h>
#include <stdio.h>
#include "cuda_img.h"

__global__ void kernel_flip(CudaImg t_cuda_img, char axis){
    int y = blockDim.y * blockIdx.y + threadIdx.y;
    int x = blockDim.x * blockIdx.x + threadIdx.x;

    int half_x = t_cuda_img.m_size.x / 2;
    int half_y = t_cuda_img.m_size.y / 2;

    if (x >= t_cuda_img.m_size.x) return;
    if (y >= t_cuda_img.m_size.y) return;

    if (axis == 'x'){
        if ((y + half_y) < t_cuda_img.m_size.y){
            uchar3 temp = t_cuda_img.at3(x, y + half_y);
            t_cuda_img.at3(x, y + half_y) = t_cuda_img.at3(x, y);
            t_cuda_img.at3(x, y) = temp;
        }
    }

    if (axis == 'y'){
        if ((x + half_x) < t_cuda_img.m_size.x){
            uchar3 temp = t_cuda_img.at3(x + half_x, y);
            t_cuda_img.at3(x + half_x, y) = t_cuda_img.at3(x, y);
            t_cuda_img.at3(x, y) = temp;
        }
    }

    return;
}

__global__ void kernel_rotate(CudaImg image, CudaImg rotate, char side ){
    int y = blockDim.y * blockIdx.y + threadIdx.y;
    int x = blockDim.x * blockIdx.x + threadIdx.x;

    if (x >= image.m_size.x) return;
    if (y >= image.m_size.y) return;

    if (side == '<'){
        rotate.at3(y, x) = image.at3(x, y);
    }
    
    if (side == '>'){
        rotate.at3(y, x) = image.at3(x, y);
    }

    return;
}

void cu_run_flip(CudaImg t_cuda_img, char axis){
    int block_size = 16;
    dim3 blockamount((t_cuda_img.m_size.x + block_size - 1) / block_size, (t_cuda_img.m_size.y + block_size - 1) / block_size);
    dim3 threadsperblock(block_size, block_size);
    kernel_flip<<<blockamount, threadsperblock>>>(t_cuda_img, axis);
    cudaDeviceSynchronize();
    return;
}

void cu_run_rotate(CudaImg image, CudaImg rotate, char side){
    int block_size = 16;
    dim3 blockamount((image.m_size.x + block_size - 1) / block_size, (image.m_size.y + block_size - 1) / block_size);
    dim3 threadsperblock(block_size, block_size);
    kernel_rotate<<<blockamount, threadsperblock>>>(image, rotate, side);
    cudaDeviceSynchronize();
    printf("%d %d // %d %d ", image.m_size.x, image.m_size.y, rotate.m_size.x, rotate.m_size.y);
    return;
}