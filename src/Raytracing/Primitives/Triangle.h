// Copyright © 2015 Mikko Ronkainen <firstname@mikkoronkainen.com>
// License: MIT, see the LICENSE file.

#pragma once

#include "Raytracing/Primitives/Primitive.h"
#include "Math/Vector3.h"
#include "Math/Vector2.h"
#include "Math/Color.h"

namespace Raycer
{
	class Triangle : public Primitive
	{
	public:

		void initialize();
		void intersect(Ray& ray) const;

		Vector3 vertices[3];
		Vector3 normals[3];
		Vector2 texcoords[3];
	};
}