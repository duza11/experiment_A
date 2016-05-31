#pragma once

#include "menu.h"
#include "text_box.h"
#include "common.h"

class AnswerMenu : public Menu
{
public:
	AnswerMenu(IQuizFloor* changer, Quiz *quiz);
	void Finitialize() override;
	bool Update() override;
	void Print() override;

private:
	int now_select_;
	pair<int, int> position_;
	pair<int, int> box_position_;
	TextBox *text_box_;
	Quiz *quiz_;
};