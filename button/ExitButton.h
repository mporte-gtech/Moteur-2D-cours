#pragma once
#include "Button.h"
#include "Window.h"

class ExitButton : public Button
{
public:
	ExitButton(Window* window);

	void Action() override;
};
