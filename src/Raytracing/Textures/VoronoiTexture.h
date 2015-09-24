// Copyright © 2015 Mikko Ronkainen <firstname@mikkoronkainen.com>
// License: MIT, see the LICENSE file.

#pragma once

#include <vector>

#include "cereal/cereal.hpp"

#include "Raytracing/Textures/Texture.h"
#include "Utils/CellNoise.h"
#include "Math/Vector3.h"
#include "Math/Color.h"

namespace Raycer
{
	class Vector2;

	class VoronoiTexture : public Texture
	{
	public:

		void initialize();

		Color getColor(const Vector2& texcoord, const Vector3& position) const;
		double getValue(const Vector2& texcoord, const Vector3& position) const;
		Vector3 getNormalData(const Vector2& texcoord, const Vector3& position, TextureNormalDataType& type) const;

		int seed = 1;
		int density = 1;
		Vector3 scale = Vector3(10.0, 10.0, 10.0);
		CellNoiseDistanceType distanceType = CellNoiseDistanceType::EUCLIDEAN;
		bool useRandomColors = true;
		int randomColorCount = 1000;
		std::vector<Color> colors;
		
	private:

		CellNoise cellNoise;

		friend class cereal::access;

		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(cereal::make_nvp("texture", cereal::base_class<Texture>(this)),
				CEREAL_NVP(seed),
				CEREAL_NVP(density),
				CEREAL_NVP(scale),
				CEREAL_NVP(distanceType),
				CEREAL_NVP(useRandomColors),
				CEREAL_NVP(randomColorCount),
				CEREAL_NVP(colors));
		}
	};
}
