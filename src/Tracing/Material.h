// Copyright © 2015 Mikko Ronkainen <firstname@mikkoronkainen.com>
// License: MIT, see the LICENSE file.

#pragma once

#include "cereal/cereal.hpp"

#include "Rendering/Color.h"
#include "Math/Vector2.h"

namespace Raycer
{
	class Texture;

	class Material
	{
	public:

		uint64_t id = 0;

		bool emissive = false;
		bool skipLighting = false;
		bool nonShadowing = false;
		bool normalInterpolation = false;
		bool autoInvertNormal = true;
		bool invertNormal = false;
		bool fresnelReflection = false;
		bool attenuating = false;
		double shininess = 2.0;
		double refractiveIndex = 1.0;
		double rayReflectance = 0.0;
		double rayTransmittance = 0.0;
		double attenuationFactor = 1.0;
		Color attenuationColor = Color(0.0, 0.0, 0.0);
		Vector2 texcoordScale = Vector2(1.0, 1.0);

		Color reflectance = Color(0.0, 0.0, 0.0);
		uint64_t reflectanceMapTextureId = 0;
		Texture* reflectanceMapTexture = nullptr;

		Color emittance = Color(0.0, 0.0, 0.0);
		uint64_t emittanceMapTextureId = 0;
		Texture* emittanceMapTexture = nullptr;

		Color ambientReflectance = Color(0.0, 0.0, 0.0);
		uint64_t ambientMapTextureId = 0;
		Texture* ambientMapTexture = nullptr;

		Color diffuseReflectance = Color(0.0, 0.0, 0.0);
		uint64_t diffuseMapTextureId = 0;
		Texture* diffuseMapTexture = nullptr;

		Color specularReflectance = Color(0.0, 0.0, 0.0);
		uint64_t specularMapTextureId = 0;
		Texture* specularMapTexture = nullptr;

		uint64_t normalMapTextureId = 0;
		Texture* normalMapTexture = nullptr;

		uint64_t maskMapTextureId = 0;
		Texture* maskMapTexture = nullptr;

	private:

		friend class cereal::access;

		template <class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP(id),
				CEREAL_NVP(emissive),
				CEREAL_NVP(skipLighting),
				CEREAL_NVP(nonShadowing),
				CEREAL_NVP(normalInterpolation),
				CEREAL_NVP(autoInvertNormal),
				CEREAL_NVP(invertNormal),
				CEREAL_NVP(fresnelReflection),
				CEREAL_NVP(attenuating),
				CEREAL_NVP(shininess),
				CEREAL_NVP(refractiveIndex),
				CEREAL_NVP(rayReflectance),
				CEREAL_NVP(rayTransmittance),
				CEREAL_NVP(attenuationFactor),
				CEREAL_NVP(attenuationColor),
				CEREAL_NVP(texcoordScale),
				CEREAL_NVP(reflectance),
				CEREAL_NVP(reflectanceMapTextureId),
				CEREAL_NVP(emittance),
				CEREAL_NVP(emittanceMapTextureId),
				CEREAL_NVP(ambientReflectance),
				CEREAL_NVP(ambientMapTextureId),
				CEREAL_NVP(diffuseReflectance),
				CEREAL_NVP(diffuseMapTextureId),
				CEREAL_NVP(specularReflectance),
				CEREAL_NVP(specularMapTextureId),
				CEREAL_NVP(normalMapTextureId),
				CEREAL_NVP(maskMapTextureId));
		}
	};
}