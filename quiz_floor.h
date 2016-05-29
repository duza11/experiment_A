#pragma once

#include <vector>
#include <new.h>
#include <conio.h>
//#include "typing.h"
//#include "quiz_maker.h"
#include "common.h"
#include "timer.h"

#include<fstream>
#include<iostream>
#include<string>
#include<sstream> //ï∂éöÉXÉgÉäÅ[ÉÄ

#include "i_quiz_maker_changer.h"
#include "base_mode.h"
#include "menu_mode.h"
#include "item_mode.h"
#include "answer_mode.h"

#define QZ_START_Y 4

using namespace std;

typedef struct
{
	string typing_str;
	string quiz_str;
	string quiz_opt[QZ_OPT_SIZE];
	bool answer_type[QZ_OPT_SIZE];
	bool enable_flag[QZ_OPT_SIZE];
} Quiz;

class QuizFloor : IQuizFloor
{
public:
	QuizFloor();
	~QuizFloor();
	int quiz_floor_main();
	void TypingMain(string &sentence);
	void QuizMain(Quiz &quiz);
	void UpdateQuizMenu();
	void CheckAnswer(bool answer_type);
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
	BaseMode* bm;
	MenuEnum next_menu_;
};