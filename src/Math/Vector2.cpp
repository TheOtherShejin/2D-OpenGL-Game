#include "Vector2.h"

Vector2::Vector2(float n) : x(n), y(n) {};
Vector2::Vector2(float x, float y) : x(x), y(y) {};

Vector2 Vector2::operator+(const Vector2& other) const {
	Vector2 temp(*this);
	temp += other;
	return temp;
}
Vector2 Vector2::operator-(const Vector2& other) const {
	Vector2 temp(*this);
	temp -= other;
	return temp;
}
Vector2 Vector2::operator+=(const Vector2& other) {
	x += other.x;
	y += other.y;
	return *this;
}
Vector2 Vector2::operator-=(const Vector2& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2 Vector2::operator*(const float other) const {
	Vector2 temp(*this);
	temp *= other;
	return temp;
}
Vector2 Vector2::operator/(const float other) const {
	Vector2 temp(*this);
	temp /= other;
	return temp;
}
Vector2 Vector2::operator*=(const float other) {
	x *= other;
	y *= other;
	return *this;
}
Vector2 Vector2::operator/=(const float other) {
	x /= other;
	y /= other;
	return *this;
}

float Vector2::Dot(Vector2 other) const {
	return (x * other.x + y * other.y);
}
float Vector2::Magnitude() const {
	return sqrt(MagnitudeSquared());
}
float Vector2::MagnitudeSquared() const {
	return Dot(*this);
}
Vector2 Vector2::Normalized() const {
	return *this / Magnitude();
}
void Vector2::Normalize() {
	*this = Normalized();
}