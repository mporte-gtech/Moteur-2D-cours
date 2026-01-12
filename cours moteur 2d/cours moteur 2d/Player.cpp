#include "Player.h"
#include <iostream>

Player::Player(float x, float y, float currentHealth, float maxHealth, Vector2 direction, float speed) :
	Entity(x, y), Alive(currentHealth, maxHealth), AMovable(direction, speed)
{
	std::cout << "Player just created at x = " << x << " and y = " << y << " with " << currentHealth << " life with direction x = " << direction.GetX() << " and y = " << direction.GetY() << std::endl;
}

void Player::TakeDamage(float amount)
{
	SetCurrentHealth(fmax(0, GetCurrentHealth() - amount));

	if (GetCurrentHealth() <= 0)
		std::cout << "Player just died" << std::endl;
}

void Player::Move()
{
	Vector2 pos = GetPosition();

	int x = pos.GetX();
	int y = pos.GetY();

	pos.SetX(pos.GetX() + GetDirection().GetX() * GetSpeed());
	pos.SetY(pos.GetY() + GetDirection().GetY() * GetSpeed());

	SetPosition(pos);

	std::cout << "Player moved to x = " << GetPosition().GetX() << " and y = " << GetPosition().GetY() << std::endl;
}

void Player::Attack(Alive* target)
{
	target->TakeDamage(10);
	std::cout << "Player just attacked" << std::endl;
}
