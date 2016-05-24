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
	this->selected_ans = 0;
	this->clear_flag = false;
	this->moved = true;

	setCursorPos(0, 0);
	cout << q.quiz_get_qz();
}

int QuizMaker::quiz_maker_main(Quiz & q)
{
	while (Timer::get_instance().timer_check() && !clear_flag)
	{
		//Item::get_instance().use_item(eItem_harf, &q);
		if (this->moved)
		{
			setCursorPos(0, QZ_START_Y);
			for (int i = 0; i < QZ_OPT_SIZE; i++) {
				quiz_maker_set_color(q, i);
				cout << " " << (char)('A' + i) << "." << q.quiz_get_qz_opt(i) << "\n";
				setColor(COL_WHITE, COL_BLACK);
			}
			setCursorPos(0, QZ_START_Y + this->selected_ans);
			cout << ">\r";
			this->moved = false;
		}
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
		}
	}
	system("cls");
	Timer::get_instance().timer_switch(true);
	Timer::get_instance().timer_reprint();
	Item::get_instance().use_flag_reset();
	return 0;
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