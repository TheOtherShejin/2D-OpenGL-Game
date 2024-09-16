#pragma once

#include "../Renderer/Renderer.h"
#include "../Math/Vector.h"
#include "../Physics/RigidBody/RigidBody2D.h"

class GameObject {
public:
	Sprite sprite;
	Vector2 position;
	RigidBody2D rigidBody;

	GameObject(Vector2 position = Vector2(0.0f));
	void Draw(Renderer* renderer);
};