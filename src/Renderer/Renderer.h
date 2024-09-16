#pragma once

#include <glad/glad.h>
#include "Shader.h"
#include "CustomSprites.h"
#include "../OpenGL/Buffers/VAO.h"
#include "../OpenGL/Buffers/VBO.h"
#include "../OpenGL/Buffers/EBO.h"
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Renderer {
private:
	Sprite quadSprite;
public:
	Shader* shader = nullptr;

	Renderer();
	void UseShader(Shader* shader);
	void Clear(float r, float g, float b, float a = 1.0f);
	void Clear(Color color);
	void Draw(Sprite* sprite);
	~Renderer();
};