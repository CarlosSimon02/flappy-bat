#pragma once

#include <string>
#include <vector>

#include "Object.h"
#include "Pipe.h"

class Bat :public Object
{
public:
	Bat();
	void draw(CHAR_INFO* screenBuff) override;
	void animate(float fElapsedTime);
	void flapOrFall(bool key, float fElapsedTime);
	bool isDead(std::vector<Pipe> pipes);
	void setInitPos();
	Vec2d getPos();
private:
	const Vec2d mDIM{7,4};
	Vec2d mPos{};
	const Vec2d mSPAWNPOINT{ SWIDTH/2+10,(SHEIGHT / 2) - mDIM.y / 2 };
	const std::wstring mFIGURE[5] = { L"_    __'\\,,/.'  \"-'         ",
									  L"       \\_,,_/. `\"-`'        ",
									  L"         ,,    ,\"-\\   |, |; ",
									  L"         ,,   .'\"-'. \\    / "};
	std::wstring mCurFigure{};
	int mFrame{};
	float mAnimCounter{}, mTimePerFrame{ 1.8f };
	float mFallCounter{}, mFallAcceleration{ 0.3f }, mFallVelocity{}, mUpVelocity{};
	bool mIsCollide{}, mIsOutofGrid;
};