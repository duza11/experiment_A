#include "menu_mode.h"

MenuMode::MenuMode(IModeChanger* changer) : BaseMode(changer)
{
	this->pos.first = MENU_OPT_X;
	this->pos.second = MENU_OPT_Y;
	this->pos.first = MENU_BOX_X;
	this->pos.second = MENU_BOX_Y;
	tb = new TextBox(box_pos, MENU_BOX_WD, MENU_BOX_HT);
}

void MenuMode::init()
{
}

void MenuMode::finit()
{
	delete tb;
}

void MenuMode::update()
{
	if (_kbhit())
	{
		int c = _getch();
		if (c == KEY_SPACE)
		{
			switch (now_select)
			{
			case eMenu_Asnwer:
				m_mode_changer->change_mode(eMode_Answer);
				break;
			case eMenu_Item:
				m_mode_changer->change_mode(eMode_Item);
				break;
			}
		}
		else if (c == KEY_ARROW)
		{
			c = _getch();
			if (c == KEY_UP)
			{
				now_select = (now_select + 1) % eMenu_Num;
			}
			else if (c == KEY_DOWN)
			{
				now_select = (now_select + eMenu_Num - 1) % eMenu_Num;
			}
		}
	}
}

void MenuMode::print()
{
	
	tb->print();
	setCursorPos(this->pos.first, this->pos.second);
	cout << " ‰ð“š";
	setCursorPos(this->pos.first, this->pos.second + 1);
	cout << " ƒAƒCƒeƒ€";
}