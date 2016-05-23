#include "typing.h"
#include "timer.h"

Typing::Typing()
{
}

Typing::~Typing()
{
}

void Typing::typing_init(string word)
{
	this->mistake = 0;
	this->word = word;
	this->input.clear();
	this->moved = true;
}

int Typing::typing_main()
{
	for (auto itr = this->word.begin(); itr != this->word.end();)
	{
		if (!Timer::get_instance().timer_check()) break;
		if (moved)
		{
			setCursorPos(0, 0);
			cout << "ƒ~ƒX" << mistake << "‰ñ\n\n";
			cout << word << "\n";
			cout << input;
			setColor(COL_WHITE, COL_CYAN);
			cout << " \n";
			setColor(COL_WHITE, COL_BLACK);
			moved = false;
		}
		if (_kbhit())
		{
			key = _getch();
			if (key == 0 || key == 224)key = _getch();
			{
				if (key == (int)*itr)
				{
					this->input.push_back(*itr);
					itr++;
				}
				else
				{
					this->mistake++;
					Timer::get_instance().timer_penalty(1);
				}
				this->moved = true;
			}
		}
	}
	system("cls");
	Timer::get_instance().timer_reprint();
	return 0;
}