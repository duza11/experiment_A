#include "answer_mode.h"

AnswerMode::AnswerMode(IQuizFloor* changer, Quiz *quiz) : BaseMode(changer, quiz)
{
	this->quiz_ = quiz;
	this->position_.first = ANSWER_OPT_X;
	this->position_.second = ANSWER_OPT_Y;
	this->box_position_.first = ANSWER_BOX_X;
	this->box_position_.second = ANSWER_BOX_Y;
	tb_ = new TextBox(box_position_, ANSWER_BOX_WD, ANSWER_BOX_HT);
}

void AnswerMode::Finitialize()
{
	tb_->finitialize();
	delete tb_;
}

bool AnswerMode::Update()
{
	if (_kbhit())
	{
		int c = _getch();
		if (c == KEY_SPACE)
		{
			iqf_->CheckAnswer(*quiz_, now_select_);
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
				now_select_ = (now_select_ + QZ_OPT_SIZE - 1) % QZ_OPT_SIZE;
			}
			else if (c == KEY_DOWN)
			{
				now_select_ = (now_select_ + 1) % QZ_OPT_SIZE;
			}
		}
		return true;
	}
	return false;
}

void AnswerMode::Print ()
{
	tb_->print();
	for (int i = 0; i < QZ_OPT_SIZE; i++)
	{
		setCursorPos(this->position_.first, this->position_.second + i);
		cout << " " << (*quiz_).quiz_opt[i] << "\n";
	}
	setCursorPos(this->position_.first, this->position_.second + now_select_);
	cout << ">";
}