// Copyright © 2015 Mikko Ronkainen <firstname@mikkoronkainen.com>
// License: MIT, see the LICENSE file.

#pragma once

#include <string>

namespace Raycer
{
	class Settings
	{
	public:

		void load(const std::string& fileName);

		struct General
		{
			bool interactive;
		} general;

		struct OpenCL
		{
			bool enabled;
			int platformId;
			int deviceType;
			int deviceId;
			std::string options;
		} openCL;

		struct Network
		{
			bool isClient;
			bool isServer;
			std::string localAddress;
			int localPort;
			std::string broadcastAddress;
			int broadcastPort;
		} network;

		struct Scene
		{
			std::string fileName;
		} scene;

		struct Image
		{
			int width;
			int height;
			std::string fileName;
			bool autoView;
		} image;

		struct Window
		{
			int width;
			int height;
			bool fullscreen;
			bool vsync;
			bool hideCursor;
			bool showFps;
			bool showCameraInfo;
			std::string defaultFont;
			int defaultFontSize;
		} window;

		struct Framebuffer
		{
			double scale;
			bool smoothing;
			std::string vertexShader;
			std::string fragmentShader;
		} framebuffer;

		struct Controls
		{
			double moveSpeed;
			double fastModifier;
			double slowModifier;
			double mouseSpeed;
			bool freeLook;
		} controls;
	};
}