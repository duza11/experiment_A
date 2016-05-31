#pragma once

#include "menu.h"
#include "text_box.h"
#include "common.h"

class BaseMenu : public Menu
{
public:
	BaseMenu(IQuizFloor* changer);
	void Finitialize() override;
	bool Update() override;
	void Print() override;

private:
	int now_select_;
	pair<int, int> position_;
	pair<int, int> box_position_;
	TextBox *text_box_;
};