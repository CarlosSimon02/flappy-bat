#include <Flappy_Bat.h>

Flappy_Bat::Flappy_Bat()
{}

bool Flappy_Bat::OnUserCreate()
{
	ConstructConsole(SWIDTH, SHEIGHT, 10, 15);
	return true;
}

bool Flappy_Bat::OnUserUpdate(float fElapsedTime)
{
	//clear screen
	Fill(0, 0, SWIDTH, SHEIGHT, L' ');

	mBg.draw(m_bufScreen);

	switch (mState)
	{
	case State::Home:
		HomeState(fElapsedTime);
		break;
	case State::Play:
		PlayState(fElapsedTime);
		break;
	case State::GameOver:
		GameOverState(fElapsedTime);
		break;
	}

	mText.setState(static_cast<int>(mState));
	mText.draw(m_bufScreen);

	return true;
}

void Flappy_Bat::HomeState(float fElapsedTime)
{
	mBat.animate(fElapsedTime);
	mBat.draw(m_bufScreen);
	if (m_keys[VK_SPACE].bPressed)
	{
		mBat.flapOrFall(m_keys[VK_SPACE].bPressed, fElapsedTime);
		mState = State::Play;
	}
}

void Flappy_Bat::PlayState(float fElapsedTime)
{
	for (size_t i = 0; i < mPipes.size(); i++)
	{
		mPipes[i].draw(m_bufScreen), mPipes[i].move(fElapsedTime, mText, mBat.getPos().x - mPipes[i].getDim().x + 2);
		if (mPipes[mPipes.size() - 1].getPos().x == 20)
		{
			Pipe pipe;
			mPipes.push_back(pipe);
		}
	}
	if (mPipes[0].getPos().x > SWIDTH) mPipes.erase(mPipes.begin());

	mBat.flapOrFall(m_keys[VK_SPACE].bPressed, fElapsedTime);
	mBat.animate(fElapsedTime);
	mBat.draw(m_bufScreen);

	if (mBat.isDead(mPipes)) mState = State::GameOver;
}

void Flappy_Bat::GameOverState(float fElapsedTime)
{
	mText.checkIfBest();
	for (size_t i = 0; i < mPipes.size(); i++) mPipes[i].draw(m_bufScreen);
	mBat.flapOrFall(m_keys[VK_SPACE].bPressed, fElapsedTime);
	mBat.draw(m_bufScreen);
	mWaitCounter += fElapsedTime;
	if (m_keys[VK_SPACE].bPressed && mWaitCounter >= 2)
	{
		mBat.setInitPos();
		mPipes.clear();
		Pipe pipe;
		mPipes.push_back(pipe);
		mState = State::Home;
		mWaitCounter = 0;
	}
}
