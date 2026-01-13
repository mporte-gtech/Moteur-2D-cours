#include "ExitButton.h"
#include "Window.h"

ExitButton::ExitButton(Window* window)
{
	SetButtonRect({ 300, 475, 200, 50 });
	SetButtonColor({ 255, 0, 0, 255 });

	SetWindow(window);
}

void ExitButton::Action()
{
	GetWindow()->SetIsOpen(false);
}
