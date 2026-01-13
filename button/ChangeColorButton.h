#pragma once
#include "Button.h"

class ChangeColorButton : public Button
{
public:
	ChangeColorButton(Window* window);

	void Action() override;
};
