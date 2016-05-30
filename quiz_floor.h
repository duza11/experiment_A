#pragma once

#include <vector>
#include <conio.h>
#include<fstream>
#include<iostream>
#include<string>
#include<sstream> //文字ストリーム
#include "common.h"
#include "timer.h"
#include "i_quiz_floor.h"
#include "menu.h"
#include "base_menu.h"
#include "item_menu.h"
#include "answer_menu.h"

#define QZ_START_Y 4

using namespace std;

class QuizFloor : IQuizFloor
{
public:
	QuizFloor();
	~QuizFloor();
	int quiz_floor_main();
	void TypingMain(string &sentence);
	void QuizMain(Quiz &quiz);
	void UpdateQuizMenu(Quiz &quiz);
	void CheckAnswer(Quiz &quiz, int option_num);
	void SwitchMenu(MenuEnum);
	void PrintQuiz(Quiz &quiz);

private:
	bool qz_init_flag = true;
	bool qm_init_flag = true;
	int input_key_ = 0;
	int mistake_ = 0;
	//int qf_status = 0;
	vector<Quiz> quiz_array_;
	//vector<Quiz>::iterator itr;
	//Typing t;
	//QuizMaker qm;
	bool goal_flag_;
	bool changed_flag_;
	Menu *bm;
	MenuEnum next_menu_;
};