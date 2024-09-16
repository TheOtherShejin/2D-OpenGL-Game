#pragma once

#include "../../Math/Vector.h"

class AABBCollision2D;
class CircleCollision2D;
class ConvexCollision2D;

class Collision2D {
public:
	virtual bool Intersects(AABBCollision2D& other) {}
	virtual bool Intersects(CircleCollision2D& other) {}
	virtual bool Intersects(ConvexCollision2D& other) {}
};