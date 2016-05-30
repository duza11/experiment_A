#pragma once

#include "menu.h"
#include "text_box.h"

#define ANSWER_BOX_X 10
#define ANSWER_BOX_Y 17
#define ANSWER_OPT_X (ANSWER_BOX_X + 2)
#define ANSWER_OPT_Y (ANSWER_BOX_Y + 1)
#define ANSWER_BOX_WD 16
#define ANSWER_BOX_HT 8

class AnswerMenu : Menu
{
public:
	AnswerMenu(IQuizFloor* changer, Quiz *quiz);
	void Finitialize() override;
	bool Update() override;
	void Print() override;

private:
	int now_select_ = 0;
	pair<int, int> position_;
	pair<int, int> box_position_;
	TextBox *tb_;
	Quiz *quiz_;
};