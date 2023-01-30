#include "Pipe.h"


Pipe::Pipe()
{
	for (size_t i = 0; i < size_t(mDIM.x*mDIM.y); i++) mFigure += L' ';
	createPipeFigure();
}

void Pipe::draw(CHAR_INFO* screenBuff)
{
	writeToBuffer(screenBuff, mFigure, COLOUR::FG_GREEN, mDIM, mPos);
}

void Pipe::move(float fElapsedTime, Text& text, int setscorePos)
{
	counter += fElapsedTime * 10.f;
	if (counter >= mTimePerMove)
	{
		mPos.x++;
		if(mPos.x == setscorePos) text.incrementScore();
		counter = 0;
	}
}

void Pipe::createPipeFigure()
{ 
	srand(static_cast<uint16_t>(time(NULL)));
	std::wstring hole{L" /OOOOOOO\\ [OOOOOOOOO]                                                                                                                                               [OOOOOOOOO] \\OOOOOOO/ "};
	size_t pipeHoleLocation = rand()%(SHEIGHT-(hole.size()/mDIM.x));
	for (size_t i = 0; i < size_t(mDIM.x*mDIM.y); i++)
	{
		if (i % mDIM.x == 0 || i % mDIM.x == 10) mFigure[i] = L' ';
		else if(i % mDIM.x == 1 || i % mDIM.x == 9) mFigure[i] = L'|';
 		else mFigure[i] = L'O';
	}
	for (size_t i = 0; i < hole.size(); i++) mFigure[i + pipeHoleLocation * mDIM.x] = hole[i];
}

Vec2d Pipe::getPos()
{
	return mPos;
}

Vec2d Pipe::getDim()
{
	return mDIM;
}

float Pipe::getTimePerMove()
{
	return mTimePerMove;
}

std::wstring Pipe::getFigure()
{
	return mFigure;
}