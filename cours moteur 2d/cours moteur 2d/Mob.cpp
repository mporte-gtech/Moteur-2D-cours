#include "Mob.h"
#include <iostream>

Mob::Mob(float x, float y, float currentHealth, float maxHealth, Vector2 direction, float speed) :
	Entity(x, y), Alive(currentHealth, maxHealth), AMovable(direction, speed) {
	std::cout << "Mob just created at x = " << x << " and y = " << y << " with " << currentHealth << "life with direction x = " << direction.GetX() << " and y = " << direction.GetY() << std::endl;
}

void Mob::TakeDamage(float amount)
{
	SetCurrentHealth(fmax(0, GetCurrentHealth() - amount));

	if (GetCurrentHealth() <= 0)
		std::cout << "Mob just died" << std::endl;
}

void Mob::Move()
{
	Vector2 pos = GetPosition();

	int x = pos.GetX();
	int y = pos.GetY();

	pos.SetX(pos.GetX() + GetDirection().GetX() * GetSpeed());
	pos.SetY(pos.GetY() + GetDirection().GetY() * GetSpeed());

	std::cout << "Mob move to x = " << GetPosition().GetX() << " and y = " << GetPosition().GetY() << std::endl;
}
