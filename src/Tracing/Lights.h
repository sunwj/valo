// Copyright © 2015 Mikko Ronkainen <firstname@mikkoronkainen.com>
// License: MIT, see the LICENSE file.

#pragma once

#include "cereal/cereal.hpp"

#include "Math/Vector3.h"
#include "Rendering/Color.h"
#include "Samplers/Sampler.h"

namespace Raycer
{
	struct Light
	{
		Color color = Color::WHITE;
		double intensity = 0.0;

		template <class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP(color),
				CEREAL_NVP(intensity));
		}
	};

	struct AmbientLight : public Light
	{
		template <class Archive>
		void serialize(Archive& ar)
		{
			ar(cereal::make_nvp("light", cereal::base_class<Light>(this)));
		}
	};

	struct DirectionalLight : public Light
	{
		Vector3 direction;

		template <class Archive>
		void serialize(Archive& ar)
		{
			ar(cereal::make_nvp("light", cereal::base_class<Light>(this)),
				CEREAL_NVP(direction));
		}
	};

	struct PointLight : public Light
	{
		Vector3 position;
		double maxDistance = 1000.0;
		double attenuation = 1.0;
		bool enableAreaLight = false;
		SamplerType areaLightSamplerType = SamplerType::CMJ;
		uint64_t areaLightSampleCountSqrt = 0;
		double areaLightRadius = 1.0;

		template <class Archive>
		void serialize(Archive& ar)
		{
			ar(cereal::make_nvp("light", cereal::base_class<Light>(this)),
				CEREAL_NVP(position),
				CEREAL_NVP(maxDistance),
				CEREAL_NVP(attenuation),
				CEREAL_NVP(enableAreaLight),
				CEREAL_NVP(areaLightSamplerType),
				CEREAL_NVP(areaLightSampleCountSqrt),
				CEREAL_NVP(areaLightRadius));
		}
	};
}