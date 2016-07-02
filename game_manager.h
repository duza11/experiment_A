#pragma once

#include <fstream>
#include <iostream>
#include <sstream> //•¶šƒXƒgƒŠ[ƒ€
#include "item_floor.h"
#include "quiz_floor.h"
#include "timer.h"
#include "player.h"
#include "console_util.h"
#include "tutorial_item_floor.h"
#include "tutorial_quiz_floor.h"

class GameManager
{
public:
	GameManager();
	void PrintRanking();
	void PrintTitle();
	void PrintResult();
	void PrintStartMenu();
	void PrintExplain();
	void CheckRanking();
	void StartGame();
	void StartTutorial();

private:
	int remaining_time_;
	int score_;
	string grade_;
};