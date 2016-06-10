#pragma once

#include "menu.h"
#include "player.h"
#include "text_box.h"
#include "common.h"

class ItemMenu : Menu
{
public:
	ItemMenu(IQuizFloor* changer, Quiz *quiz);
	void Finitialize() override;
	bool Update() override;
	void Print() override;

private:
	int now_select_ = kFiftyFifty;
	pair<int, int> position_;
	pair<int, int> box_position_;
	pair<int, int> explain_position_;
	pair<int, int> explain_box_position_;
	TextBox *text_box_;
	TextBox *explain_box_;
	Quiz *quiz_;
};