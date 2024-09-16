#include "VAO.h"

VAO::VAO() {
	glGenVertexArrays(1, &ID);
	glBindVertexArray(ID);
}

void VAO::LinkAttrib(int index, int size, int stride, int offset) {
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, (void*)offset);
	glEnableVertexAttribArray(index);
}

void VAO::Bind() {
	glBindVertexArray(ID);
}

void VAO::Unbind() {
	glBindVertexArray(0);
}

void VAO::Delete() {
	glDeleteVertexArrays(1, &ID);
}