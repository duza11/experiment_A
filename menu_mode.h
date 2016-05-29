#pragma once

#include "base_mode.h"
#include "text_box.h"

#define MENU_BOX_X 0
#define MENU_BOX_Y 21
#define MENU_OPT_X (MENU_BOX_X + 2)
#define MENU_OPT_Y (MENU_BOX_Y + 1)
#define MENU_BOX_WD 16
#define MENU_BOX_HT 4

typedef enum
{
	eMenu_Asnwer,
	eMenu_Item,

	eMenu_Num,
} eMenu;

class MenuMode : public BaseMode
{
public:
	MenuMode(IQuizFloor* changer);
	void init() override;
	void finit() override;
	bool update() override;
	void print() override;

private:
	
	int now_select = eMenu_Asnwer;
	pair<int, int> pos;
	pair<int, int> box_pos;
	TextBox *tb;
};