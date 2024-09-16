#include "RigidBody2D.h"

void RigidBody2D::Update(float dt) {
	position += velocity * dt + acceleration * 0.5f * dt * dt;
	velocity += acceleration * dt;
	acceleration = 0.0f;
}
void RigidBody2D::ApplyForce(Vector2 force) {
	acceleration += force / mass;
}