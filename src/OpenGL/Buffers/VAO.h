#pragma once

#include <glad/glad.h>

class VAO {
public:
	unsigned int ID;

	VAO();
	void LinkAttrib(int index, int size, int stride, int offset);

	void Bind();
	void Unbind();
	void Delete();
};