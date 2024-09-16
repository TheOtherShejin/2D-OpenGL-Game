#include "Vector3.h"

Vector3::Vector3(float n) : x(n), y(n), z(n) {};
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {};

Vector3 Vector3::operator+(const Vector3& other) const {
	Vector3 temp(*this);
	temp += other;
	return temp;
}
Vector3 Vector3::operator-(const Vector3& other) const {
	Vector3 temp(*this);
	temp -= other;
	return temp;
}
Vector3 Vector3::operator+=(const Vector3& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}
Vector3 Vector3::operator-=(const Vector3& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

Vector3 Vector3::operator*(const float other) const {
	Vector3 temp(*this);
	temp *= other;
	return temp;
}
Vector3 Vector3::operator/(const float other) const {
	Vector3 temp(*this);
	temp /= other;
	return temp;
}
Vector3 Vector3::operator*=(const float other) {
	x *= other;
	y *= other;
	z *= other;
	return *this;
}
Vector3 Vector3::operator/=(const float other) {
	x /= other;
	y /= other;
	z /= other;
	return *this;
}

float Vector3::Dot(Vector3 other) const {
	return (x * other.x + y * other.y + z * other.z);
}
float Vector3::Magnitude() const {
	return sqrt(MagnitudeSquared());
}
float Vector3::MagnitudeSquared() const {
	return Dot(*this);
}
Vector3 Vector3::Normalized() const {
	return *this / Magnitude();
}
void Vector3::Normalize() {
	*this = Normalized();
}