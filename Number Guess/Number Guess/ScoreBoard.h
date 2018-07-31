#pragma once
#include <string>

const int boardSize = 10;

struct scoreBoardArr
{
	std::string playerName;
	int playerScore;
};

class ScoreBoard
{
public:
	scoreBoardArr m_scoreBoardEasy[boardSize];
	scoreBoardArr m_scoreBoardMedium[boardSize];
	scoreBoardArr m_scoreBoardHard[boardSize];


	ScoreBoard();
	~ScoreBoard();

	enum difficulty
	{
		easy,
		medium,
		hard
	};

	void printScoreboard();
	bool compareScore(int score, int difficultNum);
	void insertScore(std::string name, int score, int difficultNum);

private:
	void sortScoreBoard(difficulty difficult);
};

