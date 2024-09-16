#pragma once

#include <math.h>

class Vector4 {
public:
	float x, y, z, w;

	Vector4(float n = 0.0f);
	Vector4(float x, float y, float z, float w);

	Vector4 operator+(const Vector4& other) const;
	Vector4 operator-(const Vector4& other) const;
	Vector4 operator+=(const Vector4& other);
	Vector4 operator-=(const Vector4& other);

	Vector4 operator*(const float other) const;
	Vector4 operator/(const float other) const;
	Vector4 operator*=(const float other);
	Vector4 operator/=(const float other);

	float Dot(Vector4 other) const;
	float Magnitude() const;
	float MagnitudeSquared() const;
	Vector4 Normalized() const;
	void Normalize();
};