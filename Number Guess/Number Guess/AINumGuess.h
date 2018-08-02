#pragma once
class AINumGuess
{
public:
	AINumGuess();
	~AINumGuess();

	void aiPlay();

private:
	void seedTime();
	void aiGuess(int correctNum);

	int m_aiGuesses = 0;
};

