#pragma once
#include <SDL3/SDL.h>
#include <vector>

class Button;

class Window
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isOpen;
	SDL_Color clearColor;

	bool mousePress;
	float mouseX;
	float mouseY;

	std::vector<Button*> buttons;

public:
	Window();

	void Tick();

	void RetrieveEvents();

	void Display();

	void Stop();

	SDL_Color GetClearColor();
	void SetClearColor(SDL_Color newColor);

	void SetIsOpen(bool newIsOpen);
};
