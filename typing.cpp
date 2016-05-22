#include "typing.h"

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
	this->itr = this->word.begin();
	this->moved = true;
}

int Typing::typing_main()
{
	if (!this->clear_flag)
	{
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
		if (this->itr != this->word.end())
		{
			if (_kbhit())
			{
				key = _getch();
				if (key == 0 || key == 224)key = _getch();
				{
					if (key == (int)*this->itr)
					{
						this->input.push_back(*this->itr);
						this->itr++;
					}
					else
					{
						this->mistake++;
					}
					this->moved = true;
				}
			}
			return 0;
		}
		else
		{
			system("cls");
			return 1;
		}
	}
}