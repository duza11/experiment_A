#pragma once

#include <vector>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> //•¶šƒXƒgƒŠ[ƒ€
#include <random>
#include "common.h"
#include "timer.h"
#include "i_quiz_floor.h"
#include "menu.h"
#include "base_menu.h"
#include "item_menu.h"
#include "answer_menu.h"

class QuizFloor : public IQuizFloor
{
public:
	QuizFloor(); // ‚’J½—C
	virtual int QuizFloorMain(); // –kì—Tˆê
	void TypingMain(); // –kì—Tˆê
	void QuizMain(); // –kì—Tˆê
	void UpdateQuizMenu(); // ´…‘å÷
	void CheckAnswer(int option_num) override; // ´…‘å÷
	void set_message(string message) override; // ´…‘å÷
	void SwitchMenu(MenuEnum) override; // ´…‘å÷
	void PrintQuiz(); // ‚’J½—C
	void PrintGoalMessage(); // ´…‘å÷
	void SetQuizArray(string file_name, vector<Quiz> &quiz_array); // ‚’J½—C

protected:
	int mistake_ = 0;
	vector<Quiz> quiz_array_;
	bool goal_flag_;
	bool changed_flag_;
	Menu *menu_;
	MenuEnum next_menu_;
	random_device rnd;
	Quiz *quiz_;
	pair<int, int> text_position_;
	TextBox *text_box_;
	string message_;
};