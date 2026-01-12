#include "StaticObject.h"
#include <iostream>

StaticObject::StaticObject(float x, float y) :
	Entity(x, y)
{
	std::cout << "Static Object just created at x=" << x << " and y=" << y << std::endl;
}
