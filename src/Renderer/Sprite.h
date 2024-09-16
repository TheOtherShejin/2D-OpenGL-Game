#pragma once

#include "../OpenGL/Buffers/VAO.h"
#include "../OpenGL/Buffers/VBO.h"
#include "../OpenGL/Buffers/EBO.h"
#include "../OpenGL/Buffers/Vertex.h"
#include "../Math/Vector.h"
#include "Color.h"

class Sprite {
public:
	VAO* vao = nullptr;
	EBO* ebo = nullptr;

	Color color{ 1.0f, 1.0f, 1.0f, 1.0f };
	Vector2 position{ 0.0f, 0.0f };
	Vector2 size{ 0.0f, 0.0f };
	float rotationDeg = 0.0f;
	unsigned int verticesCount, indicesCount;

	void SetVertices(std::vector<Vertex> vertices, std::vector<unsigned int> indices);

	void BindBuffers();
	void UnbindBuffers();
	void Delete();
};