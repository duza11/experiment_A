#pragma once

#include "base_mode.h"
#include "text_box.h"

#define MENU_BOX_X 0
#define MENU_BOX_Y 21
#define MENU_OPT_X (MENU_BOX_X + 2)
#define MENU_OPT_Y (MENU_BOX_Y + 1)
#define MENU_BOX_WD 16
#define MENU_BOX_HT 4

class MenuMode : public BaseMode
{
public:
	MenuMode(IQuizFloor* changer);
	void Finitialize() override;
	bool Update() override;
	void Print() override;

private:
	
	int now_select_ = kAnswerMenu;
	pair<int, int> position_;
	pair<int, int> box_position_;
	TextBox *tb_;
};