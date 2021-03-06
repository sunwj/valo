﻿// Copyright © 2016 Mikko Ronkainen <firstname@mikkoronkainen.com>
// License: MIT, see the LICENSE file.

#pragma once

#include <cstdint>
#include <vector>

#include "BVH/BVH2.h"
#include "BVH/BVH4.h"
#include "BVH/BVH8.h"
#include "BVH/Common.h"
#include "Core/Common.h"

namespace Valo
{
	class Scene;
	class Ray;
	class Intersection;

	enum class BVHType { BVH2, BVH4, BVH8 };

	class BVH
	{
	public:

		void build(std::vector<Triangle>& triangles);
		CUDA_CALLABLE bool intersect(const Scene& scene, const Ray& ray, Intersection& intersection) const;

		static BVHSplitOutput calculateSplit(std::vector<BVHBuildTriangle>& buildTriangles, std::vector<BVHSplitCache>& cache, uint32_t start, uint32_t end);

		BVHType type = DEFAULT_BVH_TYPE;

		BVH2 bvh2;
		BVH4 bvh4;
		BVH8 bvh8;
	};
}
