#include <iostream>
#include <random>
#include <ctime>
#include <assert.h>

#include "NumGuess.h"
#include "ScoreBoard.h"

enum choice
{
	Play,
	Score,
	Quit,
	def	// def = default
};

choice makeChoice()
{
	char playerChoice = 0;
	system("cls");

	std::cout << "What would you like to do?\n"
		<< "P. Play\n"
		<< "S. ScoreBoard\n"
		<< "Q. Quit\n" << std::endl;
	std::cin >> playerChoice;

	switch (playerChoice)
	{
	case 'P':
	case 'p':
		return Play;
		break;
	case 'S':
	case 's':
		return Score;
		break;
	case 'Q':
	case'q':
		return Quit;
		break;
	default:
		//assert(playerChoice != playerChoice && "RTFM"); 
		return def;
	}
}

int main()
{
	NumGuess randNumGame;
	bool numGuessed = false;
	choice phase = def;

	while (phase != Quit)
	{
		phase = makeChoice();

		if (phase == Play)
		{
			randNumGame.startGame();
			randNumGame.takeTurn();
			randNumGame.endGame();
		}
		if (phase == Score)
		{
			randNumGame.printScore();
		}
	}

	return 0;
}