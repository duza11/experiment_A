#pragma once

#include <conio.h>
#include <iostream>
#include "quiz.h"
#include "consoleUtil.h"
#include "item.h"
#include "i_mode_changer.h"
#include "base_mode.h"
#include "menu_mode.h"
#include "item_mode.h"
#include "answer_mode.h"

#define QZ_START_Y 4

class QuizMaker : IModeChanger
{
public:
	QuizMaker();
	~QuizMaker();
	void quiz_maker_init(Quiz & q);
	int quiz_maker_main(Quiz & q);
	void change_mode(eMode next_mode);
	void quiz_maker_set_color(Quiz & q, int index);

private:
	bool moved;
	int selected_ans;
	int clear_flag;
	BaseMode* bm;
	eMode m_next_mode;
};