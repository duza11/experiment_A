#pragma once

#include <vector>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> //�����X�g���[��
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
	QuizFloor(); // ���J���C
	virtual int QuizFloorMain(); // �k��T��
	void TypingMain(); // �k��T��
	void QuizMain(); // �k��T��
	void UpdateQuizMenu(); // �������
	void CheckAnswer(int option_num) override; // �������
	void set_message(string message) override; // �������
	void SwitchMenu(MenuEnum) override; // �������
	void PrintQuiz(); // ���J���C
	void PrintGoalMessage(); // �������
	void SetQuizArray(string file_name, vector<Quiz> &quiz_array); // ���J���C

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