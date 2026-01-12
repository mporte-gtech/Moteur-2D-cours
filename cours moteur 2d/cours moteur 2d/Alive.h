#pragma once

class Alive
{
private:
	float maxHealth, currentHealth;

public:
	Alive(float currentHealth, float maxHealth);

	virtual float GetCurrentHealth() const;
	void SetCurrentHealth(float newAmount);

	virtual float GetMaxHealth() const;
	void SetMaxHealth(float newAmount);

	virtual void TakeDamage(const float amount);
};
