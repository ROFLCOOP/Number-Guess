#pragma once
#include "ScoreBoard.h"


class NumGuess
{
public:

	NumGuess();
	~NumGuess();
	void startGame();
	void takeTurn();
	void endGame();
	void printScore();

private:
	void seedTime();
	void getDifficulty();
	void setNum();
	void drawGame();
	void playerGuess();
	void checkNum();
	void insertScore();
	void resetGame();

	enum difficulty 
	{
		easy,
		medium,
		hard
	};
	difficulty m_difficultLevel = easy;
	

	int m_randNum = 0;
	int m_randRange = 0;
	int m_numGuessed = 0;
	bool win = false;

public:
	ScoreBoard scoreBoard;
	int m_turnNum = 0;
};

