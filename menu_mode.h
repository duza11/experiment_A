#pragma once

#include "base_mode.h"
#include "text_box.h"

#define MENU_BOX_X 0
#define MENU_BOX_Y 22
#define MENU_OPT_X (MENU_BOX_X + 2)
#define MENU_OPT_Y (MENU_BOX_Y + 1)
#define MENU_BOX_WD 12
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
	MenuMode(IModeChanger* changer);
	void init() override;
	void finit() override;
	void update() override;
	void print() override;

private:
	
	int now_select = eMenu_Asnwer;
	pair<int, int> pos;
	pair<int, int> box_pos;
	TextBox *tb;
};