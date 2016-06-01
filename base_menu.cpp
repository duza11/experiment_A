#include "base_menu.h"

BaseMenu::BaseMenu(IQuizFloor* changer) : Menu(changer)
{
	this->now_select_ = kAnswerMenu;
	this->position_ = { BASE_MENU_OPTION_X , BASE_MENU_OPTION_Y };
	this->box_position_ = { BASE_MENU_BOX_X , BASE_MENU_BOX_Y };
	text_box_ = new TextBox(box_position_, BASE_MENU_BOX_WIDTH, BASE_MENU_BOX_HEIGHT);
}

void BaseMenu::Finitialize()
{
	delete text_box_;
	for (int i = 0; i < 2; i++)
	{
		setCursorPos(position_.first - 1, position_.second + i);
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
	text_box_->Print();
	setCursorPos(this->position_.first, this->position_.second);
	cout << "‰ð“š";
	setCursorPos(this->position_.first, this->position_.second + 1);
	cout << "ƒAƒCƒeƒ€";
	setCursorPos(this->position_.first - 1, this->position_.second + now_select_);
	cout << ">";
}