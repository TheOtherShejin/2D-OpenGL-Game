#include "Sprite.h"

void Sprite::SetVertices(std::vector<Vertex> vertices, std::vector<unsigned int> indices) {
	verticesCount = vertices.size();
	indicesCount = indices.size();

	vao = new VAO();
	VBO vbo(vertices);
	ebo = new EBO(indices);
	vao->LinkAttrib(0, 2, sizeof(Vertex), 0);
	vao->Unbind();
	ebo->Unbind();
}

void Sprite::BindBuffers() {
	vao->Bind();
	ebo->Bind();
}
void Sprite::UnbindBuffers() {
	vao->Unbind();
	ebo->Unbind();
}
void Sprite::Delete() {
	vao->Delete();
	ebo->Delete();
}