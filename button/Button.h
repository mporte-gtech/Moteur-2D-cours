#pragma once
#include <SDL3/SDL.h>

class Window;

class Button
{
private:
	SDL_FRect buttonRect;
	SDL_Color buttonColor;

	Window* window;
public:
	SDL_FRect GetButtonRect();
	void SetButtonRect(SDL_FRect rect);

	SDL_Color GetButtonColor();
	void SetButtonColor(SDL_Color color);

	Window* GetWindow();
	void SetWindow(Window* newWindow);

	void Draw(SDL_Renderer* renderer);

	bool IsHovered(float mouseX, float mouseY);

	virtual void Action() = 0;
};
