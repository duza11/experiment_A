#include "item_mode.h"

ItemMode::ItemMode(IModeChanger* changer) : BaseMode(changer)
{
	this->pos.first = ITEM_OPT_X;
	this->pos.second = ITEM_OPT_Y;
	this->box_pos.first =  ITEM_BOX_X;
	this->box_pos.second = ITEM_BOX_Y;
	tb = new TextBox(box_pos, ITEM_BOX_WD, ITEM_BOX_HT);
}

void ItemMode::init()
{

}

void ItemMode::finit()
{
	tb->finitialize();
	delete tb;
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
	setCursorPos(this->pos.first, this->pos.second);
	cout << " アイテム1";
	setCursorPos(this->pos.first, this->pos.second + 1);
	cout << " アイテム2";
	setCursorPos(this->pos.first, this->pos.second + now_select);
	cout << ">";
}