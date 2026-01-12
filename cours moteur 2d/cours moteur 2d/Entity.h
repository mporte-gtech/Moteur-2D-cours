#pragma once
#include "Vector2.h"

class Entity
{
private:
	Vector2 position;

public:
	Entity(float x, float y);

	virtual Vector2 GetPosition() const;
	virtual void SetPosition(const Vector2& newPosition);
};
