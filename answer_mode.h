#pragma once

#include "base_mode.h"
#include "text_box.h"

#define ANSWER_BOX_X 10
#define ANSWER_BOX_Y 17
#define ANSWER_OPT_X (ANSWER_BOX_X + 2)
#define ANSWER_OPT_Y (ANSWER_BOX_Y + 1)
#define ANSWER_BOX_WD 16
#define ANSWER_BOX_HT 8

class AnswerMode : BaseMode
{
public:
	AnswerMode(IModeChanger* changer, Quiz* q);
	void init() override;
	void finit() override;
	void update() override;
	void print() override;

private:
	int now_select = 0;
	pair<int, int> pos;
	pair<int, int> box_pos;
	TextBox *tb;
	Quiz *q;
};