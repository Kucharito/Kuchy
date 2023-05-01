// ***********************************************************************
//
// Demo program for education in subject
// Computer Architectures and Parallel Systems.
// Petr Olivka, dep. of Computer Science, FEI, VSB-TU Ostrava, 2020/11
// email:petr.olivka@vsb.cz
//
// Example of CUDA Technology Usage with unified memory.
//
// Image transformation from RGB to BW schema.
// Image manipulation is performed by OpenCV library.
//
// ***********************************************************************

#include <stdio.h>
#include <iostream>
#include <cuda_device_runtime_api.h>
#include <cuda_runtime.h>
#include <opencv2/opencv.hpp>

#include "uni_mem_allocator.h"
#include "cuda_img.h"

namespace cv
{
}

// Function prototype from .cu file
void cu_run_flip(CudaImg t_bgr_cuda_img, char axis);

void cu_run_rotate(CudaImg image, CudaImg rotate, char side);

int main(int t_numarg, char **t_arg){
    // Uniform Memory allocator for Mat
    UniformAllocator allocator;
    cv::Mat::setDefaultAllocator(&allocator);

    if (t_numarg < 2){
        printf("Enter picture filename!\n");
        return 1;
    }

    // Load image
    cv::Mat bgr_cv_img = cv::imread(t_arg[1], cv::IMREAD_COLOR); // CV_LOAD_IMAGE_COLOR );
    cv::Mat img_rotate( bgr_cv_img.size().width, bgr_cv_img.size().height, CV_8UC3 );      

    if (!bgr_cv_img.data){
        printf("Unable to read file '%s'\n", t_arg[1]);
        return 1;
    }

    // data for CUDA
    CudaImg bgr_cuda_img, bgr_cuda_img_rotate;
    bgr_cuda_img.m_size.x = bgr_cv_img.size().width;
    bgr_cuda_img.m_size.y = bgr_cv_img.size().height;
    bgr_cuda_img.m_p_uchar3 = (uchar3 *)bgr_cv_img.data;

    bgr_cuda_img_rotate.m_size.x = img_rotate.size().width;
    bgr_cuda_img_rotate.m_size.y = img_rotate.size().height;
    bgr_cuda_img_rotate.m_p_uchar3 = (uchar3 *)img_rotate.data;

    // Origo obrázek
    cv::imshow("Hlavní obrázek", bgr_cv_img);

    // Flip podle x
    //cu_run_flip(bgr_cuda_img, 'x');
    //cv::imshow("Rotace podle osy x", bgr_cv_img);

    // Flip podle y
    //cu_run_flip(bgr_cuda_img, 'y');
    //cv::imshow("Rotace podle osy y", bgr_cv_img);

    // Rotace doleva o 90°
    //cu_run_rotate(bgr_cuda_img, bgr_cuda_img_rotate, '<');
    //cv::imshow("Rotace doleva o 90°", img_rotate);

    // Rotace doprava o 90°
    cu_run_rotate(bgr_cuda_img, bgr_cuda_img_rotate, '>');
    cv::imshow("Rotace doprava o 90°", img_rotate);


    cv::waitKey(0);
}