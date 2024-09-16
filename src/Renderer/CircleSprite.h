#pragma once

#include "Sprite.h"

class CircleSprite : public Sprite {
public:
	float radius;
	unsigned int pointCount;

	CircleSprite(Vector2 position, float radius, unsigned int pointCount);
	void SetRadius(float radius);
	float GetRadius() const;
	unsigned int GetPointCount() const;
};