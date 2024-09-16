#include "AABBCollision2D.h"

AABBCollision2D::AABBCollision2D(Vector2 position, Vector2 size)
	: position(position), size(size) {}

bool AABBCollision2D::Intersects(AABBCollision2D& other) {
	return !(
		position.x > other.position.x + other.size.x ||
		position.x + size.x <= other.position.x ||
		position.y > other.position.y + other.size.y ||
		position.y + size.y <= other.position.y
	);
}