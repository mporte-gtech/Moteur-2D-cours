#pragma once
#include "Entity.h"
#include "Alive.h"

class BreakableObject : Entity, Alive
{
public:
	BreakableObject(float x, float y, float currentHealth, float maxHealth);

	void TakeDamage(float amount) override;
};
