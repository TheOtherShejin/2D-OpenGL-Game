#include "Vector4.h"

Vector4::Vector4(float n) : x(n), y(n), z(n), w(n) {};
Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {};

Vector4 Vector4::operator+(const Vector4& other) const {
	Vector4 temp(*this);
	temp += other;
	return temp;
}
Vector4 Vector4::operator-(const Vector4& other) const {
	Vector4 temp(*this);
	temp -= other;
	return temp;
}
Vector4 Vector4::operator+=(const Vector4& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}
Vector4 Vector4::operator-=(const Vector4& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}

Vector4 Vector4::operator*(const float other) const {
	Vector4 temp(*this);
	temp *= other;
	return temp;
}
Vector4 Vector4::operator/(const float other) const {
	Vector4 temp(*this);
	temp /= other;
	return temp;
}
Vector4 Vector4::operator*=(const float other) {
	x *= other;
	y *= other;
	z *= other;
	w *= other;
	return *this;
}
Vector4 Vector4::operator/=(const float other) {
	x /= other;
	y /= other;
	z /= other;
	w /= other;
	return *this;
}

float Vector4::Dot(Vector4 other) const {
	return (x * other.x + y * other.y + z * other.z + w * other.w);
}
float Vector4::Magnitude() const {
	return sqrt(MagnitudeSquared());
}
float Vector4::MagnitudeSquared() const {
	return Dot(*this);
}
Vector4 Vector4::Normalized() const {
	return *this / Magnitude();
}
void Vector4::Normalize() {
	*this = Normalized();
}