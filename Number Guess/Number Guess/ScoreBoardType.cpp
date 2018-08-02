#include "ScoreBoardType.h"

#include <iostream>
#include <iomanip>
#include <fstream>



ScoreBoardEasy::ScoreBoardEasy()
{
	for (int i = 0; i < boardSize; i++)
	{
		m_scoreBoard[i].playerName = "AAA";
		m_scoreBoard[i].playerScore = 999;
	}
}


ScoreBoardEasy::~ScoreBoardEasy()
{
}

void ScoreBoardEasy::printScoreboard()
{
	std::cout << "Easy: \n";
	std::cout << " # " << std::setw(9) << "Name" << std::setw(12) << "Score\n";
	for (int i = 0; i < boardSize; i++)
	{
		std::cout << std::setw(2) << i + 1 << ". " << std::setw(8) << m_scoreBoard[i].playerName << " -     " << m_scoreBoard[i].playerScore << std::endl;
	}
	std::cout << "\n" << std::endl;
}

ScoreBoardMedium::ScoreBoardMedium()
{
	for (int i = 0; i < boardSize; i++)
	{
		m_scoreBoard[i].playerName = "AAA";
		m_scoreBoard[i].playerScore = 999;
	}
}

ScoreBoardMedium::~ScoreBoardMedium()
{
}

void ScoreBoardMedium::printScoreboard()
{
	std::cout << "Medium: \n";
	std::cout << " # " << std::setw(9) << "Name" << std::setw(12) << "Score\n";
	for (int i = 0; i < boardSize; i++)
	{
		std::cout << std::setw(2) << i + 1 << ". " << std::setw(8) << m_scoreBoard[i].playerName << " -     " << m_scoreBoard[i].playerScore << std::endl;
	}
	std::cout << "\n" << std::endl;
}

ScoreBoardHard::ScoreBoardHard()
{
	for (int i = 0; i < boardSize; i++)
	{
		m_scoreBoard[i].playerName = "AAA";
		m_scoreBoard[i].playerScore = 999;
	}
}

ScoreBoardHard::~ScoreBoardHard()
{
}

void ScoreBoardHard::printScoreboard()
{
	std::cout << "Hard: \n";
	std::cout << " # " << std::setw(9) << "Name" << std::setw(12) << "Score\n";
	for (int i = 0; i < boardSize; i++)
	{
		std::cout << std::setw(2) << i + 1 << ". " << std::setw(8) << m_scoreBoard[i].playerName << " -     " << m_scoreBoard[i].playerScore << std::endl;
	}
	std::cout << "\n" << std::endl;
}
