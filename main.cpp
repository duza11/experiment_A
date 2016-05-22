#include <time.h>			//	time
#include <string>
#include "item_floor.h"
#include "quiz_floor.h"
#include "common.h"

#define TIME 600
#define QZ_FLOOR_SIZE 7

int main()
{
	system("cls");

	int time_limit = TIME;
	time_t old, now;

	bool clear_flag = false;

	ItemFloor itf;
	QuizFloor qf;

	int qf_size = QZ_FLOOR_SIZE;

	itf.item_floor_main();
	while (time_limit > 0 && !clear_flag)
	{
		time(&old);
		setCursorPos(60, 0);
		cout << "Žc‚èŽžŠÔF" << time_limit / 60 << "•ª" << time_limit % 60 << "•b";
		while (true)
		{
			time(&now);
			if (old != now)
			{
				time_limit -= (now - old);
				break;
			}
			//if ()
			//qf.quiz_floor_main();
			//system("cls");
		}
	}

	system("cls");

	if (clear_flag)
	{
		cout << "GAME CLEAR";
	}
	else
	{
		cout << "GAME OVER";
	}
	_getch();

	return 0;
}