// Copyright © 2015 Mikko Ronkainen <firstname@mikkoronkainen.com>
// License: MIT, see the LICENSE file.

#include <algorithm>
#include <cmath>

#include "Math/EulerAngle.h"
#include "Math/Vector3.h"
#include "Math/MathUtils.h"

using namespace Raycer;

EulerAngle::EulerAngle(double yaw_, double pitch_, double roll_) : yaw(yaw_), pitch(pitch_), roll(roll_)
{
}

EulerAngle::EulerAngle(const EulerAngle& e)
{
	yaw = e.yaw;
	pitch = e.pitch;
	roll = e.roll;
}

EulerAngle& EulerAngle::operator=(const EulerAngle& e)
{
	yaw = e.yaw;
	pitch = e.pitch;
	roll = e.roll;

	return *this;
}

void EulerAngle::clampPitch()
{
	if (pitch > 89.0)
		pitch = 89.0;

	if (pitch < -89.0)
		pitch = -89.0;
}

void EulerAngle::normalize()
{
	while (fabs(yaw) > 180.0)
		yaw += (yaw > 0.0) ? -360.0 : 360.0;

	while (fabs(pitch) > 180.0)
		pitch += (pitch > 0.0) ? -360.0 : 360.0;

	while (fabs(roll) > 180.0)
		roll += (roll > 0.0) ? -360.0 : 360.0;
}

Vector3 EulerAngle::getDirectionVector() const
{
	Vector3 result;

	result.x = -sin(MathUtils::degToRad(yaw)) * cos(MathUtils::degToRad(pitch));
	result.y = sin(MathUtils::degToRad(pitch));
	result.z = -cos(MathUtils::degToRad(yaw)) * cos(MathUtils::degToRad(pitch));

	return result.normalized();
}

EulerAngle EulerAngle::lerp(const EulerAngle& e1, const EulerAngle& e2, double t)
{
	EulerAngle result;
	double oneMinusT = 1.0 - t;

	result.yaw = e1.yaw * oneMinusT + e2.yaw * t;
	result.pitch = e1.pitch * oneMinusT + e2.pitch * t;
	result.roll = e1.roll * oneMinusT + e2.roll * t;

	return result;
}
