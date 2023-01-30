#include <fstream>

#include "Text.h"

Text::Text()
{
	std::fstream file("./assets/HighScore.txt", fstream::out||fstream::app);
	file.close();
	file.open("./assets/HighScore.txt", fstream::in || fstream::out || fstream::app);
	file >> mBest;
	file.close();
}

void Text::draw(CHAR_INFO* screenBuff)
{
	const std::wstring FLAPPY_BIRD{ L"[[[[[ [[   [[[[[ [[[[[ [[[[[ [[ [[   [[[[  [[[[[ [[[[[[[    [[   [[ [[ [[ [[ [[ [[ [[ [[   [[ [[ [[ [[  [[  [[[[  [[   [[[[[ [[[[[ [[[[[ [[[[[   [[[[[ [[[[[  [[  [[    [[   [[ [[ [[    [[       [[   [[ [[ [[ [[  [[  [[    [[[[ [[ [[ [[    [[    [[[[[   [[[[  [[ [[  [[  " };
	const std::wstring GAME_OVER{ L"GAME OVER                                                                                          " };
	const std::wstring PRESS_SPACEBAR{ L"[PRESS SPACEBAR]" };
	std::wstring score{ L"SCORE:    " + std::to_wstring(mScore) };
	std::wstring best{ L"BEST:     " + std::to_wstring(getBest()) };

	switch (mState)
	{
	case State::Home:
		mScore = 0;
		score = L" ";
		mScorePos= { 10,30 }, mBestPos={ 10,32 };
		writeToBuffer(screenBuff, PRESS_SPACEBAR, COLOUR::FG_YELLOW, { int(PRESS_SPACEBAR.size()),1 }, { SWIDTH / 2 - int(PRESS_SPACEBAR.size() / 2), 9 });
		writeToBuffer(screenBuff, FLAPPY_BIRD, COLOUR::FG_YELLOW, { 54,5 }, { 18, 3 });
		
		break;
	case State::Play:
		mScorePos = { 3,0 }, mBestPos = { SWIDTH-int(best.size())-3,0};
		break;
	case State::GameOver:
		mScorePos = { 10,30 }, mBestPos = { 10,32 };
		writeToBuffer(screenBuff, GAME_OVER, COLOUR::FG_YELLOW, {20,5}, {10,28},NULL);
		break;
	}

	writeToBuffer(screenBuff, score, COLOUR::FG_YELLOW, { static_cast<int>(score.size()),1 }, mScorePos,NULL);
	writeToBuffer(screenBuff, best, COLOUR::FG_YELLOW, { static_cast<int>(best.size()),1 }, mBestPos,NULL);
}

void Text::incrementScore()
{
	mScore += 1;
}

void Text::checkIfBest()
{
	if (mBest < mScore)
	{
		mBest = mScore;

		std::ofstream HighScoreFile("./assets/HighScore.txt");
		HighScoreFile << mBest;
		HighScoreFile.close();
	}
}

void Text::setState(int state)
{
	mState = static_cast<State>(state);
}

int Text::getScore()
{
	return mScore;
}

int Text::getBest()
{
	return mBest;
}
