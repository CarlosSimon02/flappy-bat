#pragma once

#include "olcConsoleGameEngineOOP.h"
#include "Constants.h"
#include "Background.h"
#include "Pipe.h"
#include "Bat.h"
#include "Text.h"



class Flappy_Bat :public olcConsoleGameEngineOOP
{
public:
	Flappy_Bat();
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
	void HomeState(float fElapsedTime);
	void PlayState(float fElapsedTime);
	void GameOverState(float fElapsedTime);
private:
	enum class State
	{
		Home, Play, GameOver
	}mState{};
	Background mBg;
	Text mText;
	Pipe pipe;
	std::vector<Pipe> mPipes{pipe};
	Bat mBat;
	float mWaitCounter{};
};
