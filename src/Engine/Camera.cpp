#include "Camera.h"

Camera::Camera(Vector2 position, float rotationDeg)
	: position(position), rotationDeg(rotationDeg) {}

void Camera::SetViewPort(float left, float right, float bottom, float top) {
	this->left = left;
	this->right = right;
	this->bottom = bottom;
	this->top = top;
}

void Camera::SetProjectionMatrix(Shader* shader) {
	shader->Use();
	shader->SetMat4("proj", glm::ortho(left, right, bottom, top));
}