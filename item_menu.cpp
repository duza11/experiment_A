#include "item_menu.h"

ItemMenu::ItemMenu(IQuizFloor* changer, Quiz *quiz) : Menu(changer, quiz)
{
	this->quiz_ = quiz;
	this->position_.first = ITEM_OPT_X;
	this->position_.second = ITEM_OPT_Y;
	this->box_position_.first =  ITEM_BOX_X;
	this->box_position_.second = ITEM_BOX_Y;
	tb_ = new TextBox(box_position_, ITEM_BOX_WD, ITEM_BOX_HT);
}

void ItemMenu::Finitialize()
{
	tb_->finitialize();
	delete tb_;
}

bool ItemMenu::Update()
{
	if (_kbhit())
	{
		int c = _getch();
		if (c == KEY_SPACE)
		{
			switch (now_select_)
			{
			case kFiftyFifty:
				Player::GetInstance().UseItem(kFiftyFifty, *quiz_);
				break;
			case kStopTimer:
				Player::GetInstance().UseItem(kStopTimer, *quiz_);
				break;
			}
		}
		else if (c == KEY_BACK)
		{
			iqf_->SwitchMenu(kBaseMenu);
		}
		else if (c == KEY_ARROW)
		{
			c = _getch();
			if (c == KEY_UP)
			{
				now_select_ = (now_select_ + kItemKind - 1) % kItemKind;
			}
			else if (c == KEY_DOWN)
			{
				now_select_ = (now_select_ + 1) % kItemKind;
			}
		}
		return true;
	}
	return false;
}

void ItemMenu::Print()
{
	tb_->print();
	setCursorPos(this->position_.first, this->position_.second);
	cout << " アイテム1";
	setCursorPos(this->position_.first, this->position_.second + 1);
	cout << " アイテム2";
	setCursorPos(this->position_.first, this->position_.second + now_select_);
	cout << ">";
}