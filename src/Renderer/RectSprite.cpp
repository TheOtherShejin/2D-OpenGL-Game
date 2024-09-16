#include "RectSprite.h"

RectSprite::RectSprite(Vector2 position, Vector2 size) {
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

	SetVertices(vertices, indices);
	this->position = position;
	this->size = size;
}
