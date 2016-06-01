#pragma once

#include <vector>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> //ï∂éöÉXÉgÉäÅ[ÉÄ
#include <random>
#include "common.h"
#include "timer.h"
#include "i_quiz_floor.h"
#include "menu.h"
#include "base_menu.h"
#include "item_menu.h"
#include "answer_menu.h"
#include "double_buffer.h"

#define QZ_START_Y 4

class QuizFloor : public IQuizFloor
{
public:
	QuizFloor();
	~QuizFloor();
	int QuizFloorMain();
	void TypingMain();
	void QuizMain();
	void UpdateQuizMenu();
	void CheckAnswer(int option_num);
	void SwitchMenu(MenuEnum);
	void PrintQuiz();

private:
	int mistake_ = 0;
	vector<Quiz> quiz_array_;
	bool goal_flag_;
	bool changed_flag_;
	Menu *menu_;
	MenuEnum next_menu_;
	random_device rnd;
	Quiz *quiz_;
};