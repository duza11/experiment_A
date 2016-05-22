#include "quiz_maker.h"

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
	moved = true;

	cout << q.quiz_get_qz();
}

bool QuizMaker::quiz_maker_main(Quiz & q)
{
	if (!clear_flag)
	{
		if (moved)
		{
			setCursorPos(0, QZ_START_Y);
			for (int i = 0; i < QZ_OPT_SIZE; i++) {
				cout << " " << q.quiz_get_qz_opt(i) << "\n";
			}
			setCursorPos(0, QZ_START_Y + this->selected_ans);
			cout << ">\r";
			moved = false;
		}
		if (_kbhit())
		{
			int c = _getch();
			if (c == KEY_SPACE)
			{
				this->clear_flag = q.quiz_get_ans_type(this->selected_ans);
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
		return 0;
	}
	else
	{
		return 1;
	}
}
