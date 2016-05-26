#include "item_mode.h"

ItemMode::ItemMode(IModeChanger* changer) : BaseMode(changer)
{
}

void ItemMode::init()
{

}

void ItemMode::finit()
{
	tb->finitialize();
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
				Item::get_instance().use_item(eItem_harf);
				break;
			case eItem_time:
				Item::get_instance().use_item(eItem_time);
				break;
			}
		}
		else if (c == KEY_BACK)
		{
			m_mode_changer->change_mode(eMode_Menu);
		}
		else if (c == KEY_ARROW)
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
	tb->print();
	tb->print();
	setCursorPos(this->pos.first, this->pos.second);
	cout << " アイテム1";
	setCursorPos(this->pos.first, this->pos.second + 1);
	cout << " アイテム2";
}