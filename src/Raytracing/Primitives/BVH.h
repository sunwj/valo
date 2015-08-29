// Copyright © 2015 Mikko Ronkainen <firstname@mikkoronkainen.com>
// License: MIT, see the LICENSE file.

#pragma once

#include <memory>
#include <random>
#include <vector>

#include "Raytracing/Primitives/Primitive.h"
#include "Raytracing/AABB.h"

namespace Raycer
{
	class Ray;
	struct Intersection;
	struct BVHBuildInfo;
	class Vector3;
	class EulerAngle;

	class BVH : public Primitive
	{
	public:

		void initialize();
		bool intersect(const Ray& ray, std::array<Intersection, 2>& intersections);
		AABB getAABB() const;
		void transform(const Vector3& scale, const EulerAngle& rotate, const Vector3& translate);

		void build(const std::vector<Primitive*>& primitives, const BVHBuildInfo& info);

	private:

		void buildRecursive(const std::vector<Primitive*>& primitives, BVH* node, const BVHBuildInfo& info, std::mt19937& gen, int& nodeCount, int& leafCount, int previousLeftSize, int previousRightSize);
		void calculateSplit(int& axis, double& splitPoint, const std::vector<Primitive*>& primitives, BVH* node, const BVHBuildInfo& info, std::mt19937& gen);
		void calculateSAHSplit(int& axis, double& splitPoint, const std::vector<Primitive*>& primitives, BVH* node, const BVHBuildInfo& info);
		double calculateSAHScore(int axis, double splitPoint, const std::vector<Primitive*>& primitives, BVH* node);
		double calculateMedianPoint(int axis, const std::vector<Primitive*>& primitives);

		AABB aabb;

		std::shared_ptr<Primitive> left;
		std::shared_ptr<Primitive> right;
	};
}
