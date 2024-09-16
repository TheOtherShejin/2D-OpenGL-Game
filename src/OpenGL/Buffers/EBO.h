#pragma once

#include <glad/glad.h>
#include <vector>

class EBO {
public:
	unsigned int ID;

	EBO(std::vector<unsigned int> indices);

	void Bind();
	void Unbind();
	void Delete();
};