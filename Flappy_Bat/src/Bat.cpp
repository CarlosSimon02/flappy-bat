#include "Bat.h"

Bat::Bat()
{
	setInitPos();
}

void Bat::draw(CHAR_INFO* screenBuff)
{
	writeToBuffer(screenBuff, mCurFigure, COLOUR::FG_CYAN, mDIM, mPos);
}

void Bat::animate(float fElapsedTime)
{
	if (mAnimCounter >= mTimePerFrame)
	{
		mFrame = (mFrame + 1) % 4;
		mCurFigure = mFIGURE[mFrame];
		mAnimCounter = 0;
	}
	mAnimCounter += fElapsedTime * 10.f;
}

void Bat::flapOrFall(bool key, float fElapsedTime)
{
	if (key && !mIsCollide) mFallVelocity = 0, mUpVelocity = 1.5;
	if (mFallCounter >= 1)
	{
		mTimePerFrame = (mFallVelocity-mUpVelocity > 0) ? 1.8f : 0.5f;
		mPos.y += mFallVelocity - mUpVelocity;
		mFallVelocity += mFallAcceleration;
		mFallCounter = 0;
	} 
	mFallCounter += fElapsedTime * 10.f;
}

bool Bat::isDead(std::vector<Pipe> pipes)
{
	CHAR_INFO tempBuffer[SWIDTH * SHEIGHT]{};
	for (size_t i = 0; i < pipes.size(); i++) 
		writeToBuffer(tempBuffer, pipes[i].getFigure(), COLOUR::FG_GREEN,pipes[i].getDim(), pipes[i].getPos());

	for (Vec2d i{}; i.y < mDIM.y; i.y++)
	{
		for (i.x = 0; i.x < mDIM.x; i.x++)
			if (tempBuffer[mPos.point() + i.point()].Attributes == COLOUR::FG_GREEN)
				mIsCollide = true;
	}
	mIsOutofGrid = (mPos.y <= -mDIM.y || mPos.y >= SHEIGHT) ? true:false;
	if (mIsCollide || mIsOutofGrid)
	{
		mCurFigure = mFIGURE[0];
		return true;
	}
	else return false;
}

void Bat::setInitPos()
{
	mPos = mSPAWNPOINT;
	mCurFigure = mFIGURE[0];
	mFallVelocity = 0, mUpVelocity = 1.5;
	mIsCollide = false, mIsOutofGrid = false;
}

Vec2d Bat::getPos()
{
	return mPos;
}