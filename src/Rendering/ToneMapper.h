// Copyright © 2015 Mikko Ronkainen <firstname@mikkoronkainen.com>
// License: MIT, see the LICENSE file.

#pragma once

namespace Raycer
{
	class Image;

	class ToneMapper
	{
		public:

			static void gamma(Image& image, double gamma);
	};
}