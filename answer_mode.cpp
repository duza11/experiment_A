#include "answer_mode.h"

AnswerMode::AnswerMode(IQuizFloor* changer, Quiz* q) : BaseMode(changer, q)
{
	m_qm_changer = changer;
	this->q = q;
	this->pos.first = ANSWER_OPT_X;
	this->pos.second = ANSWER_OPT_Y;
	this->box_pos.first = ANSWER_BOX_X;
	this->box_pos.second = ANSWER_BOX_Y;
	tb = new TextBox(box_pos, ANSWER_BOX_WD, ANSWER_BOX_HT);
}

void AnswerMode::Finitialize()
{
	tb->finitialize();
	delete tb;
}

bool AnswerMode::Update()
{
	if (_kbhit())
	{
		int c = _getch();
		if (c == KEY_SPACE)
		{
			iqf_->CheckAnswer(q->answer_type);
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
				now_select = (now_select + QZ_OPT_SIZE - 1) % QZ_OPT_SIZE;
			}
			else if (c == KEY_DOWN)
			{
				now_select = (now_select + 1) % QZ_OPT_SIZE;
			}
		}
		return true;
	}
	return false;
}

void AnswerMode::print ()
{
	tb->print();
	for (int i = 0; i < QZ_OPT_SIZE; i++)
	{
		setCursorPos(this->pos.first, this->pos.second + i);
		cout << " " << q->quiz_get_qz_opt(i) << "\n";
	}
	setCursorPos(this->pos.first, this->pos.second + now_select);
	cout << ">";
}