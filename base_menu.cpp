#include "base_menu.h"

BaseMenu::BaseMenu(IQuizFloor* changer) : Menu(changer)
{
	this->position_.first = MENU_OPT_X;
	this->position_.second = MENU_OPT_Y;
	this->box_position_.first = MENU_BOX_X;
	this->box_position_.second = MENU_BOX_Y;
	tb_ = new TextBox(box_position_, MENU_BOX_WD, MENU_BOX_HT);
}

void BaseMenu::Finitialize()
{
	delete tb_;
	for (int i = 0; i < 2; i++)
	{
		setCursorPos(position_.first, position_.second + i);
		cout << " ";
	}
}

bool BaseMenu::Update()
{
	if (_kbhit())
	{
		int c = _getch();
		if (c == KEY_SPACE)
		{
			switch (now_select_)
			{
			case kAnswerMenu:
				iqf_->SwitchMenu(kAnswerMenu);
				break;
			case kItemMenu:
				iqf_->SwitchMenu(kItemMenu);
				break;
			}
		}
		else if (c == KEY_ARROW)
		{
			c = _getch();
			if (c == KEY_UP)
			{
				now_select_ = (now_select_ + kMenuNum - 1) % kMenuNum;
			}
			else if (c == KEY_DOWN)
			{
				now_select_ = (now_select_ + 1) % kMenuNum;
			}
		}
		return true;
	}
	return false;
}

void BaseMenu::Print()
{
	tb_->print();
	setCursorPos(this->position_.first, this->position_.second);
	cout << " ‰ð“š";
	setCursorPos(this->position_.first, this->position_.second + 1);
	cout << " ƒAƒCƒeƒ€";
	setCursorPos(this->position_.first, this->position_.second + now_select_);
	cout << ">";
}