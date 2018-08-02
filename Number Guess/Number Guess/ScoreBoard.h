#pragma once
#include <string>

const int boardSize = 10;



class ScoreBoard
{
public:
	virtual bool compareScore(int score);
	void insertScore(std::string name, int score);
	virtual void printScoreboard() = 0;

protected:
	struct scoreBoardArr
	{
		std::string playerName;
		int playerScore;
	};
	virtual void sortScoreBoard();
	scoreBoardArr m_scoreBoard[boardSize];
};