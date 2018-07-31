#include "ScoreBoard.h"
#include "NumGuess.h"

#include <iostream>
#include <iomanip>

ScoreBoard::ScoreBoard()
{
	for (int i = 0; i < boardSize; i++)
	{
		m_scoreBoardEasy[i].playerName = "AAA";
		m_scoreBoardEasy[i].playerScore = 999;
	}
	for (int i = 0; i < boardSize; i++)
	{
		m_scoreBoardMedium[i].playerName = "AAA";
		m_scoreBoardMedium[i].playerScore = 999;
	}
	for (int i = 0; i < boardSize; i++)
	{
		m_scoreBoardHard[i].playerName = "AAA";
		m_scoreBoardHard[i].playerScore = 999;
	}
}


ScoreBoard::~ScoreBoard()
{
}

void ScoreBoard::printScoreboard()
{
	system("cls");
	std::cout << "Easy: \n";
	std::cout << " #  Name    Score\n";
	for (int i = 0; i < boardSize; i++)
	{
		std::cout << std::setw(2) << i + 1 << ". " << std::setw(8) << m_scoreBoardEasy[i].playerName << " -     " << m_scoreBoardEasy[i].playerScore << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Medium: \n";
	std::cout << " #  Name    Score\n";
	for (int i = 0; i < boardSize; i++)
	{
		std::cout << std::setw(2) << i + 1 << ". " << std::setw(8) << m_scoreBoardMedium[i].playerName << " -     " << m_scoreBoardMedium[i].playerScore << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Hard: \n";
	std::cout << " #      Name      Score\n";
	for (int i = 0; i < boardSize; i++)
	{
		std::cout << std::setw(2) << i + 1 << ". " << std::setw(8) << m_scoreBoardHard[i].playerName << " -     " << m_scoreBoardHard[i].playerScore << std::endl;
	}
	std::cout << std::endl;
	system("pause");
}

bool ScoreBoard::compareScore(int score, int difficultNum)
{
	bool highScore = false;
	for (int i = 0; i < boardSize; i++)
	{
		if (difficultNum == 0)
		{
			if (m_scoreBoardEasy[i].playerScore > score)
			{
				highScore = true;
			}

		}
		if (difficultNum == 1)
		{
			if (m_scoreBoardMedium[i].playerScore > score)
			{
				highScore = true;
			}
		}
		if (difficultNum == 2)
		{
			if (m_scoreBoardHard[i].playerScore > score)
			{
				highScore = true;
			}
		}
	}
	return highScore;
}

void ScoreBoard::insertScore(std::string name, int score, int difficultNum)
{

	if (difficultNum == 0)
	{
		m_scoreBoardEasy[boardSize - 1].playerName = name;
		m_scoreBoardEasy[boardSize - 1].playerScore = score;
		sortScoreBoard(easy);
	}
	else if (difficultNum == 1)
	{
		m_scoreBoardMedium[boardSize - 1].playerName = name;
		m_scoreBoardMedium[boardSize - 1].playerScore = score;
		sortScoreBoard(medium);
	}
	else if (difficultNum == 2)
	{
		m_scoreBoardHard[boardSize - 1].playerName = name;
		m_scoreBoardHard[boardSize - 1].playerScore = score;
		sortScoreBoard(hard);
	}


}

void ScoreBoard::sortScoreBoard(difficulty difficult)
{
	bool isSwitched = false;
	do
	{
		isSwitched = false;
		for (int i = 0; i < boardSize - 1; i++)
		{
			if (difficult == easy)
			{
				if (m_scoreBoardEasy[i].playerScore > m_scoreBoardEasy[i + 1].playerScore)
				{
					std::swap(m_scoreBoardEasy[i], m_scoreBoardEasy[i + 1]);
					isSwitched = true;
				}
			}
			if (difficult == medium)
			{
				if (m_scoreBoardMedium[i].playerScore > m_scoreBoardMedium[i + 1].playerScore)
				{
					std::swap(m_scoreBoardMedium[i], m_scoreBoardMedium[i + 1]);
					isSwitched = true;
				}
			}
			if (difficult == hard)
			{
				if (m_scoreBoardHard[i].playerScore > m_scoreBoardHard[i + 1].playerScore)
				{
					std::swap(m_scoreBoardHard[i], m_scoreBoardHard[i + 1]);
					isSwitched = true;
				}
			}
		}
	} while (isSwitched);
}
