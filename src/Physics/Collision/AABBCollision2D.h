#pragma once

#include "Collision2D.h"

class AABBCollision2D : public Collision2D {
public:
	Vector2 position, size;

	AABBCollision2D(Vector2 position, Vector2 size);
	bool Intersects(AABBCollision2D& other) override;
};