#pragma once
#include "Entity.h"
#include "Alive.h"
#include "AMovable.h"
#include "Vector2.h"

class Mob : public Entity, public Alive, public AMovable
{
public:
	Mob(float x, float y, float currentHealth, float maxHealth, Vector2 direction, float speed);

	void TakeDamage(float amount) override;

	void Move() override;
};
