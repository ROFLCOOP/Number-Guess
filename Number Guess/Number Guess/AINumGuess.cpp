#include "AINumGuess.h"
#include <random>
#include <ctime>
#include <iostream>

AINumGuess::AINumGuess()
{
	seedTime();
}


AINumGuess::~AINumGuess()
{
}

void AINumGuess::aiPlay()
{
	int numberToGuess = rand() % 10000;

	system("cls");
	std::cout << "The bot will now try to guess the number that was randomly selected between 0 and 10000!" << std::endl;

	aiGuess(numberToGuess);
}

void AINumGuess::seedTime()
{
	srand((unsigned int)time(nullptr));
}

void AINumGuess::aiGuess(int correctNum)
{
	int min = 0;
	int max = 10000;
	bool answerFound = false;

	while (!answerFound)
	{
		m_aiGuesses++;
		int range = max - min;
		int aiGuess = min + range / 2;
		system("cls");
		if (aiGuess == correctNum)
		{
			answerFound = true;
			std::cout << "Guess Number: " << m_aiGuesses
				<< "\nThe AI guessed: " << aiGuess << "... And it was just right!" << std::endl;
		}
		else if(aiGuess > correctNum)
		{
			std::cout << "Guess Number: " << m_aiGuesses
				<< "\nThe AI guessed: " << aiGuess << "... but it was much too high!" << std::endl;

			max = aiGuess;
		}
		else if (aiGuess < correctNum)
		{
			std::cout << "Guess Number: " << m_aiGuesses
				<< "\nThe AI guessed: " << aiGuess << "... but it was much too Low!" << std::endl;

			min = aiGuess;
		}
		system("pause");
	}
	m_aiGuesses = 0;
}
