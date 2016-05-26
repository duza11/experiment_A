#include "answer_mode.h"

AnswerMode::AnswerMode(IModeChanger* changer, Quiz* q) : BaseMode(changer, q)
{
	m_mode_changer = changer;
	this->q = q;
	this->pos.first = ANSWER_OPT_X;
	this->pos.second = ANSWER_OPT_Y;
	this->box_pos.first = ANSWER_BOX_X;
	this->box_pos.second = ANSWER_BOX_Y;
	tb = new TextBox(box_pos, ANSWER_BOX_WD, ANSWER_BOX_HT);
}

void AnswerMode::init()
{

}

void AnswerMode::finit()
{
	tb->finitialize();
	delete tb;
}

void AnswerMode::update()
{
	if (_kbhit())
	{
		int c = _getch();
		if (c == KEY_SPACE)
		{
			
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
				now_select = (now_select + 1) % QZ_OPT_SIZE;
			}
			else if (c == KEY_DOWN)
			{
				now_select = (now_select + QZ_OPT_SIZE - 1) % QZ_OPT_SIZE;
			}
		}
	}
}

void AnswerMode::print()
{
	tb->print();
}