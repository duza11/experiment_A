#include "menu_mode.h"

MenuMode::MenuMode(IQuizFloor* changer) : BaseMode(changer)
{
	this->position_.first = MENU_OPT_X;
	this->position_.second = MENU_OPT_Y;
	this->box_position_.first = MENU_BOX_X;
	this->box_position_.second = MENU_BOX_Y;
	tb_ = new TextBox(box_position_, MENU_BOX_WD, MENU_BOX_HT);
}

void MenuMode::Finitialize()
{
	delete tb_;
}

bool MenuMode::Update()
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

void MenuMode::Print()
{
	tb_->print();
	setCursorPos(this->position_.first, this->position_.second);
	cout << " ‰ð“š";
	setCursorPos(this->position_.first, this->position_.second + 1);
	cout << " ƒAƒCƒeƒ€";
	setCursorPos(this->position_.first, this->position_.second + now_select_);
	cout << ">";
}