#pragma once

#include "menu.h"
#include "text_box.h"
#include "common.h"

class BaseMenu : public Menu
{
public:
	BaseMenu(IQuizFloor* changer); // ´…‘åŽ÷
	void Finitialize() override; // ´…‘åŽ÷
	bool Update() override; // ´…‘åŽ÷
	void Print() override; // ´…‘åŽ÷

private:
	int now_select_;
	pair<int, int> position_;
	pair<int, int> box_position_;
	TextBox *text_box_;
};