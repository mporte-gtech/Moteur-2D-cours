#include "Button.h"

SDL_FRect Button::GetButtonRect()
{
	return buttonRect;
}

void Button::SetButtonRect(SDL_FRect newRect)
{
	buttonRect = newRect;
}

SDL_Color Button::GetButtonColor()
{
	return buttonColor;
}

void Button::SetButtonColor(SDL_Color newColor)
{
	buttonColor = newColor;
}

Window* Button::GetWindow()
{
	return window;
}

void Button::SetWindow(Window* newWindow)
{
	window = newWindow;
}

void Button::Draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, buttonColor.r, buttonColor.g, buttonColor.b, buttonColor.a);
	SDL_RenderFillRect(renderer, &buttonRect);
}

bool Button::IsHovered(float mouseX, float mouseY)
{
	return (mouseX >= buttonRect.x && mouseX <= buttonRect.x + buttonRect.w && mouseY >= buttonRect.y && mouseY <= buttonRect.y + buttonRect.h);
}
