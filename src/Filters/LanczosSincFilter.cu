// Copyright © 2016 Mikko Ronkainen <firstname@mikkoronkainen.com>
// License: MIT, see the LICENSE file.

#include "Precompiled.h"

#include "Filters/LanczosSincFilter.h"

using namespace Valo;

namespace
{
	CUDA_CALLABLE float sinc(float x)
	{
		return std::sin(float(M_PI) * x) / (float(M_PI) * x);
	}

	CUDA_CALLABLE float calculateWeight(float s, float size)
	{
		s = std::abs(s);

		if (s == 0.0f)
			return 1.0f;

		if (s > size)
			return 0.0f;

		return sinc(s) * sinc(s / size);
	}
}

CUDA_CALLABLE float LanczosSincFilter::getWeight(float s) const
{
	return calculateWeight(s, radius.x);
}

CUDA_CALLABLE float LanczosSincFilter::getWeight(const Vector2& point) const
{
	return calculateWeight(point.x, radius.x) * calculateWeight(point.y, radius.y);
}

CUDA_CALLABLE Vector2 LanczosSincFilter::getRadius() const
{
	return radius;
}
