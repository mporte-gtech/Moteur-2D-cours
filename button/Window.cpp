#include "Window.h"
#include "Button.h"
#include "ChangeColorButton.h"
#include "ExitButton.h"

Window::Window()
{
	window = SDL_CreateWindow("Button", 800, 600, 0);
	renderer = SDL_CreateRenderer(window, NULL);
	isOpen = true;

	clearColor = { 0, 0, 0, 255 };

	mousePress = false;
	mouseX = 0;
	mouseY = 0;

	buttons.push_back(new ChangeColorButton(this));
	buttons.push_back(new ExitButton(this));
}

void Window::Tick()
{
	while (isOpen) {

		RetrieveEvents();

		for (Button* button : buttons)
		{
			if (button->IsHovered(mouseX, mouseY) && mousePress)
				button->Action();
		}

		Display();
	}
}

void Window::RetrieveEvents()
{
	mousePress = false;
	mouseX = 0;
	mouseY = 0;

	SDL_Event e;
	if (SDL_PollEvent(&e))
	{
		if (e.type == SDL_EVENT_QUIT)
		{
			isOpen = false;
		}
		if (e.type == SDL_EVENT_KEY_UP && e.key.key == SDLK_ESCAPE)
		{
			isOpen = false;
		}
		if (e.type == SDL_EVENT_MOUSE_BUTTON_UP && e.button.button == SDL_BUTTON_LEFT) {
			mousePress = true;
			mouseX = e.button.x;
			mouseY = e.button.y;
		}
	}
}

void Window::Display()
{
	SDL_SetRenderDrawColor(renderer, clearColor.r, clearColor.g, clearColor.b, clearColor.a);
	SDL_RenderClear(renderer);

	for (Button* button : buttons)
	{
		button->Draw(renderer);
	}

	SDL_RenderPresent(renderer);
}

void Window::Stop()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

SDL_Color Window::GetClearColor()
{
	return clearColor;
}

void Window::SetClearColor(SDL_Color newColor)
{
	clearColor = newColor;
}

void Window::SetIsOpen(bool newIsOpen)
{
	isOpen = newIsOpen;
}
