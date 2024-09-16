#pragma once

#include <math.h>

class Vector3 {
public:
	float x, y, z;

	Vector3(float n = 0.0f);
	Vector3(float x, float y, float z);

	Vector3 operator+(const Vector3& other) const;
	Vector3 operator-(const Vector3& other) const;
	Vector3 operator+=(const Vector3& other);
	Vector3 operator-=(const Vector3& other);

	Vector3 operator*(const float other) const;
	Vector3 operator/(const float other) const;
	Vector3 operator*=(const float other);
	Vector3 operator/=(const float other);

	float Dot(Vector3 other) const;
	float Magnitude() const;
	float MagnitudeSquared() const;
	Vector3 Normalized() const;
	void Normalize();
};