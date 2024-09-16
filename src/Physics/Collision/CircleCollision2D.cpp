#include "CircleCollision2D.h"

CircleCollision2D::CircleCollision2D(Vector2 position, float radius)
	: position(position), radius(radius) {}

bool CircleCollision2D::Intersects(CircleCollision2D& other) {
	float distance = (other.position - position).MagnitudeSquared();
	return (distance < pow(other.radius + radius, 2));
}