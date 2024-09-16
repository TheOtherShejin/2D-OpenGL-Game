#pragma once

#include "../Renderer/Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
	float left = 0.0f, right = 0.0f, bottom = 0.0f, top = 0.0f;
	Vector2 position;
	float rotationDeg;

	Camera(Vector2 position = Vector2(0.0f), float rotationDeg = 0.0f);
	void SetViewPort(float left, float right, float bottom, float top);
	void SetProjectionMatrix(Shader* shader);
};