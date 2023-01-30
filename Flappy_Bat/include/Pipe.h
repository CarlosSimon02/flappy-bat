#pragma once

#include <string>
#include <array>
#include <cstdlib>
#include <chrono>

#include "Object.h"
#include "Text.h"

class Pipe :public Object
{
public:
	Pipe();
	void draw(CHAR_INFO* screenBuff) override;
	void move(float fElapsedTime, Text& text, int setscorePos);
	Vec2d getPos();
	Vec2d getDim();
	float getTimePerMove();
	std::wstring getFigure();
private:
	void createPipeFigure();
private:
	Vec2d mDIM{ 11,50 };
	Vec2d mPos{ -mDIM.x,0 };
	std::wstring mFigure;
	float counter{}, mTimePerMove{1};
};