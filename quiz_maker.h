#pragma once

#include <conio.h>
#include <iostream>
#include "quiz.h"
#include "consoleUtil.h"
#include "item.h"

#define QZ_START_Y 4

class QuizMaker
{
public:
	QuizMaker();
	~QuizMaker();
	void quiz_maker_init(Quiz & q);
	int quiz_maker_main(Quiz & q);
	void quiz_maker_set_color(Quiz & q, int index);

private:
	bool moved;
	int selected_ans;
	int clear_flag;
};