#include "item_mode.h"

ItemMode::ItemMode(IModeChanger* changer) : BaseMode(changer)
{
}

void ItemMode::init()
{

}

void ItemMode::finit()
{

}

void ItemMode::update()
{
	if (_kbhit())
	{
		int c = _getch();
		if (c == KEY_SPACE)
		{
			switch (now_select)
			{
			case eItem_harf:
				break;
			case eItem_time:
				break;
			}
		}
		if (c == KEY_ARROW)
		{
			c = _getch();
			if (c == KEY_UP)
			{
				now_select = (now_select + 1) % eItem_length;
			}
			else if (c == KEY_DOWN)
			{
				now_select = (now_select + eItem_length - 1) % eItem_length;
			}
		}
	}
}

void ItemMode::print()
{

}