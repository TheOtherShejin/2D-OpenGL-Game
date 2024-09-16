#include "Renderer.h"

Renderer::Renderer() {
	std::vector<Vertex> vertices = {
		{{-0.5f, -0.5f}}, 
		{{ 0.5f, -0.5f}}, 
		{{ 0.5f,  0.5f}}, 
		{{-0.5f,  0.5f}}
	};
	std::vector<unsigned int> indices = {
		0, 1, 2,
		2, 3, 0
	};

	quadSprite.SetVertices(vertices, indices);
}

void Renderer::UseShader(Shader* shader) {
	this->shader = shader;
	shader->Use();
}

void Renderer::Clear(float r, float g, float b, float a) {
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Clear(Color color) {
	glClearColor(color.r, color.g, color.b, color.a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Draw(Sprite* sprite) {
	glm::mat4 model(1.0f);
	model = glm::translate(model, glm::vec3(ConvertVecToGLMVec(sprite->position), 0.0f));

	model = glm::translate(model, glm::vec3(0.5f * sprite->size.x, 0.5f * sprite->size.y, 0.0f));
	model = glm::rotate(model, glm::radians(sprite->rotationDeg), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(-0.5f * sprite->size.x, -0.5f * sprite->size.y, 0.0f));

	model = glm::scale(model, glm::vec3(ConvertVecToGLMVec(sprite->size), 1.0f));

	shader->SetMat4("model", model);
	shader->SetVec4("color", sprite->color.r, sprite->color.g, sprite->color.b, sprite->color.a);

	sprite->BindBuffers();
	glDrawElements(GL_TRIANGLES, sprite->indicesCount, GL_UNSIGNED_INT, NULL);
	sprite->UnbindBuffers();
}

Renderer::~Renderer() {
	quadSprite.Delete();
}