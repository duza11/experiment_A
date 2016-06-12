#pragma once

#include "menu.h"
#include "text_box.h"
#include "common.h"

class AnswerMenu : public Menu
{
public:
	AnswerMenu(IQuizFloor* changer, Quiz *quiz); // ´…‘åŽ÷
	void Finitialize() override; // ´…‘åŽ÷
	bool Update() override; // ´…‘åŽ÷
	void Print() override; // ´…‘åŽ÷

private:
	int now_select_;
	pair<int, int> position_;
	pair<int, int> box_position_;
	TextBox *text_box_;
	Quiz *quiz_;
};