#include "NumGuess.h"

#include <ctime>
#include <random>
#include <iostream>
#include <assert.h>

NumGuess::NumGuess()
{
	seedTime();

}


NumGuess::~NumGuess()
{
}

void NumGuess::printScore()
{
	scoreBoard.printScoreboard();
}

void NumGuess::seedTime()
{
	srand((unsigned int)time(nullptr));
}

void NumGuess::getDifficulty()
{
	bool error = false;
	do
	{
		error = false;
		char difficultyChoice = 0;
		system("cls");
		std::cout << "Please select a difficulty: \n"
			<< "E: Easy\n"
			<< "M: Medium\n"
			<< "H: Hard\n\n"
			<< "Type the letter of the difficulty you want: ";
		std::cin >> difficultyChoice;

		switch (difficultyChoice)
		{
		case 'E':
		case 'e':
			m_difficultLevel = easy;
			break;
		case 'M':
		case 'm':
			m_difficultLevel = medium;
			break;
		case 'H':
		case 'h':
			m_difficultLevel = hard;
			break;
		default:
			std::cout << "Please pick one of the valid options\n";
			system("pause");
			error = true;
		}
	} while (error);
}

void NumGuess::setNum()
{

	if (m_difficultLevel == easy)
	{
		m_randRange = 11;
	}
	else if (m_difficultLevel == medium)
	{
		m_randRange = 101;
	}
	else if (m_difficultLevel == hard)
	{
		m_randRange = 1001;
	}
	m_randNum = rand() % m_randRange;
}

void NumGuess::drawGame()
{
	system("cls");
	if (m_turnNum > 0 && m_numGuessed > m_randNum)
	{
		std::cout << m_numGuessed << " was too high!" << std::endl;
	}
	else if (m_turnNum > 0 && m_numGuessed < m_randNum)
	{
		std::cout << m_numGuessed << " was too low!" << std::endl;
	}
	


}

void NumGuess::playerGuess()
{
	bool goodGuess = true;
	do
	{
		goodGuess = true;
		system("cls");
		std::cout << "Guess a number between 0 and " << m_randRange - 1 << std::endl;
		std::cout << "\nYour pick: ";
		std::cin >> m_numGuessed;
		//assert(!std::cin.fail());
		if (std::cin.fail() || m_numGuessed >= m_randRange || m_numGuessed < 0)
		{
			
			std::cout << "\nTry again, maybe use a number this time." << std::endl;
			system("pause");
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			goodGuess = false;
		}

	} while (!goodGuess);
}

void NumGuess::checkNum()
{
	if (m_numGuessed == m_randNum)
	{
		std::cout << "Just Right!" << std::endl;
		win = true;
	}
	else if (m_numGuessed > m_randNum)
	{
		std::cout << "Too High!" << std::endl;
	}
	else if (m_numGuessed < m_randNum)
	{
		std::cout << "Too Low!" << std::endl;
	}
	m_turnNum++;
	system("pause");
}

void NumGuess::startGame()
{
	getDifficulty();
	setNum();
	
}

void NumGuess::takeTurn()
{
	while (!win)
	{
		drawGame();
		playerGuess();
		checkNum();
	}
}

void NumGuess::insertScore()
{
	char choice = 0;
	std::string name;
	int difficultNum;
	if (m_difficultLevel == easy)
	{
		difficultNum = 0;
	}
	if (m_difficultLevel == medium)
	{
		difficultNum = 1;
	}
	if (m_difficultLevel == hard)
	{
		difficultNum = 2;
	}

	bool highScore = scoreBoard.compareScore(m_turnNum, difficultNum);
	if (highScore)
	{
		bool goodCommand = false;

		while (!goodCommand)
		{
			system("cls");
			std::cout << "You got a high score! Would you like to record your score?\nY/N: ";
			std::cin >> choice;

			switch (choice)
			{
			case 'y':
			case 'Y':
				system("cls");
				std::cout << "Write your name (8 char, no spaces): ";
				std::cin >> name;
				name.resize(8);
				scoreBoard.insertScore(name, m_turnNum, difficultNum);
				goodCommand = true;
				break;
			case 'n':
			case 'N':
				goodCommand = true;
				break;
			default:
				std::cout << "\nBad command, try again" << std::endl;
				system("pause");
			}
		}
	}
}

void NumGuess::resetGame()
{
	win = false;
	m_turnNum = 0;
}

void NumGuess::endGame()
{
	system("cls");

	if (m_turnNum > 1)
	{
		std::cout << "You guessed the answer (" << m_randNum << ") in " << m_turnNum << " guesses!" << std::endl;
	}
	else
	{
		std::cout << "You guess the answer in only one guess!!" << std::endl;
	}
	
	insertScore();

	resetGame();
	system("pause");
}
