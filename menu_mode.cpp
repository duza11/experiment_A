#include "menu_mode.h"

MenuMode::MenuMode(IModeChanger* changer) : BaseMode(changer)
{
}

void MenuMode::init()
{
	
}

void MenuMode::finit()
{

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

				break;
			case eMenu_Item:

				break;
			}
		}
		if (c == KEY_ARROW)
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

}