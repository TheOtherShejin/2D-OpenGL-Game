#pragma once

#include <math.h>

class Vector2 {
public:
	float x, y;

	Vector2(float n = 0.0f);
	Vector2(float x, float y);

	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator+=(const Vector2& other);
	Vector2 operator-=(const Vector2& other);

	Vector2 operator*(const float other) const;
	Vector2 operator/(const float other) const;
	Vector2 operator*=(const float other);
	Vector2 operator/=(const float other);

	float Dot(Vector2 other) const;
	float Magnitude() const;
	float MagnitudeSquared() const;
	Vector2 Normalized() const;
	void Normalize();
};