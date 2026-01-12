#include "AMovable.h"
#include <math.h>
#include <cstdlib>

AMovable::AMovable(Vector2 direction, float speed) :
	direction(direction), speed(speed) {
}

void AMovable::SetDirection(const Vector2& newDirection)
{
	int distance = sqrtf(pow(newDirection.GetX(), 2) + pow(newDirection.GetY(), 2));

	if (distance == 0)
	{
		direction.SetX(0);
		direction.SetY(0);
	}

	direction.SetX(newDirection.GetX() / distance);
	direction.SetY(newDirection.GetY() / distance);
}

Vector2& AMovable::GetDirection()
{
	return direction;
}

void AMovable::SetSpeed(const float& newSpeed)
{
	speed = newSpeed;
}

float AMovable::GetSpeed()
{
	return speed;
}
