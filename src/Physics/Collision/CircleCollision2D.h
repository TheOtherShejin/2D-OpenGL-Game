#pragma once

#include "Collision2D.h"

class CircleCollision2D : public Collision2D {
public:
	Vector2 position;
	float radius;

	CircleCollision2D(Vector2 position, float radius);
	bool Intersects(CircleCollision2D& other) override;
};