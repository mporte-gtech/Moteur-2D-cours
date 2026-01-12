#include "Entity.h"

Entity::Entity(float x, float y)
{

	position.SetX(x);
	position.SetY(y);
}

Vector2 Entity::GetPosition() const
{
	return position;
}

void Entity::SetPosition(const Vector2& newPosition)
{
	position = newPosition;
}
