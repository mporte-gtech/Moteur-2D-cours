#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Food.h"

class Game
{
private:
	std::mt19937 gen;
	sf::RenderWindow window;
	sf::RectangleShape shape;

	float time_between_move;
	float current_timer_between_move;

	sf::Clock c;

	bool gameover;
	Snake snake;
	Food food;

public:
	Game();

	void Play();

	void Step();

	void GetInputs();

	void Display();
};
