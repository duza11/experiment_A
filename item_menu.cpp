#include "item_menu.h"

ItemMenu::ItemMenu(IQuizFloor* changer, Quiz *quiz) : Menu(changer, quiz)
{
	this->now_select_ = kFiftyFifty;
	this->quiz_ = quiz;
	this->position_ = { ITEM_MENU_OPTION_X , ITEM_MENU_OPTION_Y };
	this->box_position_ = { ITEM_MENU_BOX_X , ITEM_MENU_BOX_Y };
	text_box_ = new TextBox(box_position_, ITEM_MENU_BOX_WIDTH, ITEM_MENU_BOX_HEIGHT);
}

void ItemMenu::Finitialize()
{
	text_box_->Finitialize();
	delete text_box_;
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
				Player::GetInstance().UseItem(kFiftyFifty, *quiz_, iqf_);
				break;
			case kStopTimer:
				Player::GetInstance().UseItem(kStopTimer, *quiz_, iqf_);
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
	text_box_->Print();
	Player::GetInstance().PrintItemStatus(this->position_);
	SetCursorPosition(this->position_.first - 1, this->position_.second + now_select_);
	cout << ">";
}