#include "answer_menu.h"

AnswerMenu::AnswerMenu(IQuizFloor* changer, Quiz *quiz) : Menu(changer, quiz)
{
	this->now_select_ = 0;
	this->quiz_ = quiz;
	this->position_.first = ANSWER_MENU_OPTION_X;
	this->position_.second = ANSWER_MENU_OPTION_Y;
	this->box_position_.first = ANSWER_MENU_BOX_X;
	this->box_position_.second = ANSWER_MENU_BOX_Y;
	text_box_ = new TextBox(box_position_, ANSWER_MENU_BOX_WIDTH, ANSWER_MENU_BOX_HEIGHT);
}

void AnswerMenu::Finitialize()
{
	text_box_->Finitialize();
	delete text_box_;
}

bool AnswerMenu::Update()
{
	if (_kbhit())
	{
		int c = _getch();
		if (c == KEY_SPACE)
		{
			iqf_->CheckAnswer(now_select_);
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
				now_select_ = (now_select_ + QUIZ_OPTION_SIZE - 1) % QUIZ_OPTION_SIZE;
			}
			else if (c == KEY_DOWN)
			{
				now_select_ = (now_select_ + 1) % QUIZ_OPTION_SIZE;
			}
		}
		return true;
	}
	return false;
}

void AnswerMenu::Print ()
{
	text_box_->Print();
	for (int i = 0; i < QUIZ_OPTION_SIZE; i++)
	{
		if ((*quiz_).enable_flag[i])
		{
			setColor(COL_WHITE, COL_BLACK);
		}
		else
		{
			setColor(COL_GRAY, COL_BLACK);
		}
		setCursorPos(this->position_.first, this->position_.second + i);
		cout << (*quiz_).quiz_opt[i];
	}
	setCursorPos(this->position_.first - 1, this->position_.second + now_select_);
	cout << ">";
}