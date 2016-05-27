#include "quiz_maker.h"
#include "timer.h"

QuizMaker::QuizMaker()
{
}

QuizMaker::~QuizMaker()
{
}

void QuizMaker::quiz_maker_init(Quiz & q)
{
	bm = (BaseMode*) new MenuMode(this);
	this->selected_ans = 0;
	this->clear_flag = false;
	this->moved = true;

	setCursorPos(0, 0);
	cout << q.quiz_get_qz();
}

void QuizMaker::quiz_maker_update(Quiz & q)
{
	if (m_next_mode != eMode_None)
	{
		bm->finit();
		delete bm;
		switch (m_next_mode)
		{
		case eMode_Menu:
			bm = (BaseMode*) new MenuMode(this);
			break;
		case eMode_Item:
			bm = (BaseMode*) new ItemMode(this, &q);
			break;
		case eMode_Answer:
			bm = (BaseMode*) new AnswerMode(this, &q);
			break;
		}
		m_next_mode = eMode_None;
		moved = true;
	}
	if (!moved)
	{
		moved = bm->update();
	}
}

void QuizMaker::quiz_maker_print(Quiz & q)
{
	if (this->moved)
	{
		bm->print();
		setCursorPos(0, QZ_START_Y);
		for (int i = 0; i < QZ_OPT_SIZE; i++) {
			quiz_maker_set_color(q, i);
			cout << " " << (char)('A' + i) << "." << q.quiz_get_qz_opt(i) << "\n";
			setColor(COL_WHITE, COL_BLACK);
		}
		this->moved = false;
	}
}

int QuizMaker::quiz_maker_main(Quiz & q)
{
	quiz_maker_print(q);
	while (Timer::get_instance().timer_check() && !clear_flag)
	{
		quiz_maker_update(q);
		quiz_maker_print(q);
		/*
		if (_kbhit())
		{
			int c = _getch();
			if (c == KEY_SPACE)
			{
				if (!q.quiz_get_answered_flag(this->selected_ans))
				{
					q.quiz_get_ans_type(this->selected_ans);
				}
				this->clear_flag = q.quiz_ans_check(this->selected_ans);
				this->moved = true;
			}
			else if (c == KEY_ARROW)
			{
				c = _getch();
				if (c == KEY_UP)
				{
					this->selected_ans = (this->selected_ans + QZ_OPT_SIZE - 1) % QZ_OPT_SIZE;
				}
				else if (c == KEY_DOWN)
				{
					this->selected_ans = (this->selected_ans + 1) % QZ_OPT_SIZE;
				}
				this->moved = true;
			}
		}*/
	}
	system("cls");
	Timer::get_instance().timer_switch(true);
	Timer::get_instance().timer_reprint();
	Item::get_instance().use_flag_reset();
	return 0;
}

void QuizMaker::change_mode(eMode next_mode)
{
	m_next_mode = next_mode;
}

void QuizMaker::change_clear_flag(bool clear_flag)
{
	this->clear_flag = clear_flag;
}

void QuizMaker::quiz_maker_set_color(Quiz & q, int index)
{
	if (q.quiz_get_answered_flag(index))
	{
		setColor(COL_GRAY, COL_BLACK);
	}
	else
	{
		setColor(COL_WHITE, COL_BLACK);
	}
}