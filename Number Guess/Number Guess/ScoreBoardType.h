#pragma once
#include "scoreBoard.h"

class ScoreBoardEasy : public ScoreBoard
{
public:
	ScoreBoardEasy();
	~ScoreBoardEasy();
	void printScoreboard() override;

};

class ScoreBoardMedium : public ScoreBoard
{
public:
	ScoreBoardMedium();
	~ScoreBoardMedium();
	void printScoreboard() override;
};

class ScoreBoardHard : public ScoreBoard
{
public:
	ScoreBoardHard();
	~ScoreBoardHard();
	void printScoreboard() override;
};
