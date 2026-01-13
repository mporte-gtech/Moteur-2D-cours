#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "BodyPart.h"

class Snake
{
private:
	std::vector<BodyPart*> snakeBody;
	sf::Vector2f snakeDirection;

public:
	Snake();

	void AddBodyPart(sf::Vector2f position);
	std::vector<sf::Vector2f> GetBody();

	void SetDirection(sf::Vector2f newDirection);
	sf::Vector2f GetDirection();

	void Move();

	void Draw(sf::RenderWindow& window, sf::RectangleShape shape);
};
