#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Game.h"

int main()
{
	Game game;

	game.Play();

	/*std::mt19937 gen;
	gen.seed(time(nullptr));

	sf::RenderWindow window(sf::VideoMode({1920u, 1080u}), "Snake");

	sf::RectangleShape shape({32, 32});

	std::vector<sf::Vector2f> snakeBody;
	snakeBody.push_back({0, 0});
	sf::Vector2f snakeDirection = {0, 0};

	sf::Vector2f foodPosition;
	bool found;
	do {
		found = false;
		sf::Vector2f tmpPosition((int)(gen() % 23) - 12, (int)(gen() % 17) - 8);
		if (std::find(snakeBody.begin(), snakeBody.end(), tmpPosition) != snakeBody.end()) {
			found = true;
		}
		foodPosition = tmpPosition;
	} while (found);


	sf::View v = window.getDefaultView();
	v.setCenter({0, 0});

	window.setView(v);


	float time_between_move = 0.5f;
	float current_timer_between_move = 0.f;

	bool gameover = false;

	sf::Clock c;
	// run the program as long as the window is open
	while (window.isOpen())
	{
		float deltaTime = c.restart().asSeconds();
		// check all the window's events that were triggered since the last iteration of the loop
		while (const std::optional event = window.pollEvent())
		{
			// "close requested" event: we close the window
			if (event->is<sf::Event::Closed>())
				window.close();
			if (const sf::Event::KeyPressed* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
				if (keyPressed->scancode == sf::Keyboard::Scancode::Left) {
					snakeDirection = {-1, 0};
				}
				if (keyPressed->scancode == sf::Keyboard::Scancode::Right) {
					snakeDirection = {1, 0};
				}
				if (keyPressed->scancode == sf::Keyboard::Scancode::Up) {
					snakeDirection = {0, -1};
				}
				if (keyPressed->scancode == sf::Keyboard::Scancode::Down) {
					snakeDirection = {0, 1};
				}
			}
		}

		if (gameover) {
			std::cout << "Game Over !" << std::endl;
			window.close();
		}
		else {
			if (current_timer_between_move <= 0) {
				if (snakeDirection.x != 0 || snakeDirection.y != 0) {
					sf::Vector2f nextPosition = snakeBody[0] + snakeDirection;
					if (std::find(snakeBody.begin(), snakeBody.end(), nextPosition) == snakeBody.end()) {
						if (nextPosition == foodPosition) {
							do {
								found = false;
								sf::Vector2f tmpPosition((int)(gen() % 23) - 12, (int)(gen() % 17) - 8);
								if (std::find(snakeBody.begin(), snakeBody.end(), tmpPosition) != snakeBody.end() && nextPosition != tmpPosition) {
									found = true;
								}
								foodPosition = tmpPosition;
							} while (found);
							snakeBody.push_back(snakeBody[snakeBody.size() - 1]);
						}
						for (int i = snakeBody.size() - 1; i > 0; --i) {
							snakeBody[i] = snakeBody[i - 1];
						}
						snakeBody[0] = nextPosition;
					}
					else {
						gameover = true;
					}

				}
				current_timer_between_move += (time_between_move - 0.01f * snakeBody.size() < 0.06f) ? 0.06f : (time_between_move - 0.01f * snakeBody.size());
			}
			else {
				current_timer_between_move -= deltaTime;
			}

			window.clear(sf::Color::Black);

			for (sf::Vector2f p : snakeBody) {
				shape.setPosition(p * shape.getSize().x);
				shape.setFillColor(sf::Color::Green);
				window.draw(shape);
			}

			shape.setPosition(foodPosition * shape.getSize().x);
			shape.setFillColor(sf::Color::Red);
			window.draw(shape);
		}
		window.display();
	}*/

	return 0;
}
