﻿// Copyright © 2015 Mikko Ronkainen <firstname@mikkoronkainen.com>
// License: MIT, see the LICENSE file.

#include "Precompiled.h"

#include "Scenes/Scene.h"

using namespace Raycer;

Scene Scene::createTestScene1()
{
	Scene scene;

	scene.general.tracerType = TracerType::PATH;
	scene.pathtracing.enableMultiSampling = true;
	scene.pathtracing.terminationProbability = 0.5;
	scene.pathtracing.multiSamplerFilterType = FilterType::TENT;
	scene.pathtracing.minPathLength = 3;
	scene.pathtracing.pixelSampleCount = 1;

	scene.camera.position = Vector3(0.0, 1.0, 3.5);

	ModelLoaderInfo model;
	model.modelFilePath = "data/models/cornellbox/cornellbox.obj";

	scene.models.push_back(model);
	
	AmbientLight ambientLight;
	ambientLight.color = Color(1.0, 1.0, 1.0) * 0.01;
	ambientLight.occlusion = false;
	ambientLight.maxSampleDistance = 0.2;
	ambientLight.sampleCountSqrt = 4;

	scene.lights.ambientLights.push_back(ambientLight);

	DirectionalLight directionalLight;
	directionalLight.color = Color(1.0, 1.0, 1.0) * 0.2;
	directionalLight.direction = EulerAngle(-30.0, 50.0, 0.0).getDirection();

	//scene.lights.directionalLights.push_back(directionalLight);

	PointLight pointLight;
	pointLight.color = Color(1.0, 0.71, 0.24) * 0.5;
	pointLight.position = Vector3(0.0, 1.9, 0.0);

	scene.lights.pointLights.push_back(pointLight);

	AreaPointLight areaLight;
	areaLight.color = Color(1.0, 0.71, 0.24) * 0.5;
	areaLight.position = Vector3(0.0, 1.9, 0.0);
	areaLight.radius = 0.2;
	areaLight.sampleCountSqrt = 4;

	//scene.lights.areaPointLights.push_back(areaLight);

	return scene;
}
