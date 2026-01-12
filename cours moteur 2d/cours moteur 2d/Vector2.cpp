#include "Vector2.h"

Vector2::Vector2()
{
	X = 0;
	Y = 0;
};

float Vector2::GetX() const
{
	return X;
}
void Vector2::SetX(const float& newX)
{
	X = newX;
}

float Vector2::GetY() const
{
	return Y;
}
void Vector2::SetY(const float& newY)
{
	Y = newY;
}
