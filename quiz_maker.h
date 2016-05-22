#pragma once

#include <conio.h>
#include <iostream>
#include "quiz.h"
#include "consoleUtil.h"

#define QZ_START_Y 4

class QuizMaker
{
public:
	QuizMaker();
	~QuizMaker();
	void quiz_maker_init(Quiz & q);
	bool quiz_maker_main(Quiz & q);

private:
	bool moved;
	int selected_ans;
	bool clear_flag;
};