#include "CircleSprite.h"

CircleSprite::CircleSprite(Vector2 position, float radius, unsigned int pointCount) : radius(radius), pointCount(pointCount) {
	std::vector<Vertex> vertices = { {{0.0f, 0.0f}} };
	std::vector<unsigned int> indices;

	float PI = 3.1415926535f;
	float angleInterval = 2 * PI / pointCount;

	for (int i = 0; i < pointCount; i++) {
		float x = cos(angleInterval * i);
		float y = sin(angleInterval * i);
		vertices.push_back({ {x, y} });
	}

	for (int i = 1; i <= pointCount; i++) {
		indices.push_back(0);
		indices.push_back(i);
		if (i + 1 > pointCount) indices.push_back(1);
		else indices.push_back(i + 1);
	}

	SetVertices(vertices, indices);
	SetRadius(radius);
	this->position = position;
}

void CircleSprite::SetRadius(float radius) {
	this->size = Vector2(2 * radius, 2 * radius);
}

float CircleSprite::GetRadius() const {
	return radius;
}

unsigned int CircleSprite::GetPointCount() const {
	return pointCount;
}