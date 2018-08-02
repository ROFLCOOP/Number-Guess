#include "ScoreBoard.h"
#include "NumGuess.h"

#include <iostream>
#include <iomanip>


bool ScoreBoard::compareScore(int score)
{
	bool highScore = false;

	for (int i = 0; i < boardSize; i++)
	{
		if (m_scoreBoard[i].playerScore > score)
		{
			highScore = true;
		}
	}
	return highScore;
}

void ScoreBoard::insertScore(std::string name, int score)
{
	m_scoreBoard[boardSize - 1].playerName = name;
	m_scoreBoard[boardSize - 1].playerScore = score;
	sortScoreBoard();
}

void ScoreBoard::sortScoreBoard()
{
	bool isSwitched = false;
	do
	{
		isSwitched = false;
		for (int i = 0; i < boardSize - 1; i++)
		{
			if (m_scoreBoard[i].playerScore > m_scoreBoard[i + 1].playerScore)
			{
				std::swap(m_scoreBoard[i], m_scoreBoard[i + 1]);
				isSwitched = true;
			}
		}
	}while (isSwitched);
}
