#pragma once

#include <array>

#include "Object.h"

class Background :public Object
{
public:
	Background();
	void draw(CHAR_INFO* screenBuff) override;
private:
	std::vector<Vec2d> mStarPos;
};