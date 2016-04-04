// Copyright © 2016 Mikko Ronkainen <firstname@mikkoronkainen.com>
// License: MIT, see the LICENSE file.

#pragma once

#include "Core/Common.h"

namespace Raycer
{
	class Color;
	class Scene;
	class Intersection;
	class Ray;
	class Random;

	class AmbientOcclusionIntegrator
	{
	public:

		CUDA_CALLABLE Color calculateLight(const Scene& scene, const Intersection& intersection, const Ray& ray, Random& random) const;

		float maxDistance = 1.0f;
		bool useReflectance = false;
	};
}
