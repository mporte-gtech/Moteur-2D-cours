#include "ChangeColorButton.h"
#include "Window.h"

ChangeColorButton::ChangeColorButton(Window* window)
{
	SetButtonRect({ 300, 275, 200, 50 });
	SetButtonColor({ 255, 255, 255, 255 });

	SetWindow(window);
}

void ChangeColorButton::Action()
{
	SDL_Color clearColor = GetWindow()->GetClearColor();

	if (clearColor.r == 0 && clearColor.g == 0 && clearColor.b == 0) {
		clearColor = { 0,255, 255, 255 };
	}
	else if (clearColor.r == 0 && clearColor.g == 255 && clearColor.b == 255) {
		clearColor = { 255, 255, 0, 255 };
	}
	else if (clearColor.r == 255 && clearColor.g == 255 && clearColor.b == 0) {
		clearColor = { 0, 0, 0, 255 };
	}
	GetWindow()->SetClearColor(clearColor);
}
