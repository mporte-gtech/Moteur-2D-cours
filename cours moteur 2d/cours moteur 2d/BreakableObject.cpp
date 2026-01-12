#include "BreakableObject.h"
#include <iostream>

BreakableObject::BreakableObject(float x, float y, float currentHealth, float maxHealth) :
	Entity(x, y), Alive(currentHealth, maxHealth)
{
	std::cout << "Breakable Object just created at x = " << x << " and y = " << y << " with " << currentHealth << " life" << std::endl;
}

void BreakableObject::TakeDamage(float amount)
{
	SetCurrentHealth(fmax(0, GetCurrentHealth() - amount));

	std::cout << "Breakable Object just broke" << std::endl;
}
