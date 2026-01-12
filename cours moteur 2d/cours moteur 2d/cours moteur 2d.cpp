#include <iostream>
#include "World.h"

int main()
{
	World world = World();

	world.InitWorld();

	bool exit = false;

	while (exit == false)
	{
		exit = world.Step();
	}

	return 0;
}
