// Copyright © 2016 Mikko Ronkainen <firstname@mikkoronkainen.com>
// License: MIT, see the LICENSE file.

#pragma once

#define VALO_VERSION "0.1.0"
#define CACHE_LINE_SIZE 64

#ifdef __INTEL_COMPILER
#define DEFAULT_BVH_TYPE BVHType::BVH4
#else
#define DEFAULT_BVH_TYPE BVHType::BVH2
#endif

#ifdef _MSC_VER
#define ALIGN(x) __declspec(align(x))
#elif __GNUC__
#define ALIGN(x) __attribute__ ((aligned(x)))
#endif

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#ifdef USE_CUDA
#include <cuda_runtime.h>
#define CUDA_CALLABLE __host__ __device__
#else
#define CUDA_CALLABLE 
#endif
