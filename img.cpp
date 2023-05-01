// ***********************************************************************
//
// Demo program for education in subject
// Computer Architectures and Parallel Systems.
// Petr Olivka, dep. of Computer Science, FEI, VSB-TU Ostrava, 2020/11
// email:petr.olivka@vsb.cz
//
// Example of CUDA Technology Usage.
//
// Image interface for CUDA
//
// ***********************************************************************

#pragma once

#include <opencv2/core/mat.hpp>

// Structure definition for exchanging data between Host and Device
class CudaImg {
  public:
    uint3 m_size; // size of picture
    union
    {
      void *m_p_void;     // data of picture
      uchar3 *m_p_uchar3; // data of picture
    };

    __device__ uchar3 &at3(int x, int y)
    {
      return this->m_p_uchar3[y * this->m_size.x + x];
    }
};