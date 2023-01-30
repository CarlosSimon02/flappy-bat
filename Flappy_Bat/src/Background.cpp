#include <random>

#include "Background.h"

Background::Background()
{
	for (Vec2d i{}; i.y < SHEIGHT; i.y+=5)
	{
		for (i.x = 0; i.x < SWIDTH; i.x+=5) mStarPos.push_back(i);
	}
	std::random_shuffle(mStarPos.begin(), mStarPos.end());
}

void Background::draw(CHAR_INFO* screenBuff)
{
	std::wstring Star = L".";
	std::wstring Moon = L"   __,._    ,`  ,` '  /   /      |   '      \\    `.__,/ `. -__ -' ";

	for (size_t i = 0; i < 30; i++) writeToBuffer(screenBuff, Star, FG_DARK_GREY, { 1,1 }, mStarPos[i], NULL);
	writeToBuffer(screenBuff, Moon, FG_DARK_GREY, { 11,6 }, { 10,10 }, NULL);
}
