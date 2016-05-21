#include "typing.h"

Typing::Typing()
{
}

Typing::~Typing()
{
}

int Typing::typing_main(string word)
{
	this->word = word;
	auto itr = word.begin();
	while (true)
	{
		system("cls");
		cout << "得点" << score << "点　ミス" << mistake << "回\n\n";
		cout << word << "\n";
		cout << input;
		setColor(COL_WHITE, COL_CYAN);
		cout << " \n";
		setColor(COL_WHITE, COL_BLACK);
		while (itr != word.end())
		{
			if (_kbhit())
			{
				key = _getch();
				if (key == 0 || key == 224)key = _getch();
				{
					if (key == (int)*itr)
					{
						score++;
						input.push_back(*itr);
						itr++;
					}
					else
					{
						mistake++;
					}
					break;
				}
			}
		}
		if (itr == word.end())
		{
			break;
		}
	}

	system("cls");

	return 0;
}