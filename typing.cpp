#include "typing.h"

Typing::Typing()
{
}

Typing::~Typing()
{
}

int Typing::typing_main()
{
	int key = 0;
	int score = 0;
	int mistake = 0;
	string word = "A lie can make it half way around the world before the truth has time to put its boots on.";
	string input;
	auto itr = word.begin();

	while (1)
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
	cout << "結果\n";
	cout << "得点" << score << "点　ミス" << mistake << "回\n";
	cout << "おしまい";

	return 0;
}