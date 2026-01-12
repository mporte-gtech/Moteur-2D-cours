#pragma once
#include "Vector2.h"

class AMovable
{
private:
	Vector2 direction;
	float speed;

public:
	AMovable(Vector2 direction, float speed);

	virtual void SetDirection(const Vector2& newDirection);
	Vector2& GetDirection();

	virtual void SetSpeed(const float& newSpeed);
	float GetSpeed();

	virtual void Move() = 0;
};
