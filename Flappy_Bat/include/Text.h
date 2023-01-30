#pragma once



#include "Object.h"

class Text :public Object
{
public:
	Text();
	void draw(CHAR_INFO* screenBuff) override;
	void setScoreandBestPos(Vec2d scorePos, Vec2d BestPos);
	void incrementScore();
	void checkIfBest();
	void setState(int state);
	int getScore();
	int getBest();
public:
	enum class State
	{
		Home, Play, GameOver
	};
private:
	State mState{State::Home};
	int mScore{}, mBest{};
	Vec2d mScorePos{}, mBestPos{};
};