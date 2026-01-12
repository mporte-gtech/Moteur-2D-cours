#pragma once
#include "Entity.h"
#include "Alive.h"
#include "AMovable.h"
#include "IAttacker.h"

class Player : public Entity, public Alive, public AMovable, public IAttacker
{
public:
	Player(float x, float y, float currentHealth, float maxHealth, Vector2 direction, float speed);

	void TakeDamage(float amount) override;

	void Move() override;

	void Attack(Alive* target) override;
};
