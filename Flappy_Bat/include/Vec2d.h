#pragma once

#include "Constants.h"

struct Vec2d
{
	int x, y;

public:
	int point(int width = SWIDTH)
	{
		return x + y * width;
	}
};