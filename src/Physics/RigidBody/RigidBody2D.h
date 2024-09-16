#pragma once

#include "../../Math/Vector.h"
#include "../Collision/Collision2D.h"
#include "../Collision/AABBCollision2D.h"
#include "../Collision/CircleCollision2D.h"

class RigidBody2D {
public:
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	Collision2D collision;
	float mass;

	void Update(float dt);
	void ApplyForce(Vector2 force);
};