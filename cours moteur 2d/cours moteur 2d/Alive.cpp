#include "Alive.h"
#include <algorithm>

Alive::Alive(float currentHealth, float maxHealth) : 
	currentHealth(currentHealth), maxHealth(maxHealth) { }

float Alive::GetCurrentHealth() const
{
	return currentHealth;
}

void Alive::SetCurrentHealth(float newAmount)
{
	currentHealth = newAmount;
}

float Alive::GetMaxHealth() const
{
	return maxHealth;
}

void Alive::SetMaxHealth(float newAmount)
{
	maxHealth = newAmount;
}

void Alive::TakeDamage(const float amount)
{
	currentHealth = fmax(0, currentHealth - amount);
}
