// Copyright © 2015 Mikko Ronkainen <firstname@mikkoronkainen.com>
// License: MIT, see the LICENSE file.

#pragma once

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/opencl.h>
#endif

#ifdef _MSC_VER
#define ALIGN(x) __declspec(align(x))
#elif __GNUC__
#define ALIGN(x) __attribute__ ((aligned(x)))
#endif

namespace Raycer
{
	namespace OpenCL
	{
		struct State
		{
			cl_float ALIGN(4) imageWidth;
			cl_float ALIGN(4) imageHeight;
			cl_float ALIGN(4) time;
			cl_int ALIGN(4) lightCount;
			cl_int ALIGN(4) planeCount;
			cl_int ALIGN(4) sphereCount;
		};

		struct Camera
		{
			cl_float4 ALIGN(16) position;
			cl_float4 ALIGN(16) up;
			cl_float4 ALIGN(16) right;
			cl_float4 ALIGN(16) imagePlaneCenter;
			cl_float ALIGN(4) imagePlaneWidth;
			cl_float ALIGN(4) imagePlaneHeight;
			cl_float ALIGN(4) aspectRatio;
		};

		struct Light
		{
			cl_float4 ALIGN(16) position;
			cl_float4 ALIGN(16) color;
			cl_float ALIGN(4) intensity;
		};

		struct Plane
		{
			cl_float4 ALIGN(16) position;
			cl_float4 ALIGN(16) normal;
			cl_float4 ALIGN(16) color;
		};

		struct Sphere
		{
			cl_float4 ALIGN(16) position;
			cl_float4 ALIGN(16) color;
			cl_float ALIGN(4) radius;
		};
	}
}
