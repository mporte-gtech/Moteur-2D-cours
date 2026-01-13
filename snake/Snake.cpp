#include "Snake.h"
#include "Snake.h"
#include "Snake.h"
#include "Snake.h"
#include "Snake.h"
#include "BodyPart.h"

Snake::Snake()
{
	snakeDirection = { 0, 0 };

	AddBodyPart({ 0, 0 });
}

void Snake::AddBodyPart(sf::Vector2f position)
{
	snakeBody.push_back(BodyPart(position))
}

std::vector<sf::Vector2f> Snake::GetBody()
{
	return snakeBody;
}

void Snake::SetDirection(sf::Vector2f newDirection)
{
	snakeDirection = newDirection;
}

sf::Vector2f Snake::GetDirection()
{
	return direction;
}

void Snake::Move()
{
	if (direction == sf::Vector2f{ 0, 0 })
		return;

	for (size_t i = body.size() - 1; i > 0; --i) {
		body[i].SetPosition(body[i - 1].GetPosition());
	}
	body[0].SetPosition(body[0].GetPosition() + direction);
}

void Draw(sf::RenderWindow& window, sf::RectangleShape shape)
{
	for (BodyPart* bodyPart : snakeBody)
	{
		bodyPart->Draw();
	}
}
