#pragma once

class Vector2
{
private:
	float X, Y;

public:
	Vector2();

	float GetX() const;
	void SetX(const float& newX);

	float GetY() const;
	void SetY(const float& newY);
};
