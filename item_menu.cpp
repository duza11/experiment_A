#include "item_menu.h"

ItemMenu::ItemMenu(IQuizFloor* changer, Quiz *quiz) : Menu(changer, quiz)
{
	this->now_select_ = kFiftyFifty;
	this->quiz_ = quiz;
	this->position_ = { ITEM_MENU_OPTION_X , ITEM_MENU_OPTION_Y };
	this->box_position_ = { ITEM_MENU_BOX_X , ITEM_MENU_BOX_Y };
	this->explain_position_ = { 40 , 17 };
	this->explain_box_position_ = { 38 , 16 };
	text_box_ = new TextBox(box_position_, ITEM_MENU_BOX_WIDTH, ITEM_MENU_BOX_HEIGHT);
	explain_box_ = new TextBox(explain_box_position_, 24, 8);
}

void ItemMenu::Finitialize()
{
	explain_box_->Finitialize();
	text_box_->Finitialize();
	delete explain_box_;
	delete text_box_;
}

bool ItemMenu::Update()
{
	if (_kbhit())
	{
		int c = _getch();
		if (c == KEY_ENTER)
		{
			Player::GetInstance().UseItem(now_select_, *quiz_, iqf_);
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
	explain_box_->Print();
	Player::GetInstance().PrintItemStatus(this->position_);
	SetColor(COL_WHITE, COL_BLACK);
	SetCursorPosition(this->position_.first - 1, this->position_.second + now_select_);
	cout << ">";
	Player::GetInstance().PrintItemExplain(now_select_, this->explain_position_);
}