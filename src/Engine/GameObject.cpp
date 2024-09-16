#include "GameObject.h"

GameObject::GameObject(Vector2 position)
	: position(position) {}

void GameObject::Draw(Renderer* renderer) {
	sprite.position = position;
	renderer->Draw(&sprite);
}
