#include <time.h>			//	time
#include <string>
#include "item_floor.h"
#include "quiz_floor.h"
#include "common.h"
#include "timer.h"

int main()
{
	system("cls");

	int time_limit = TIME;
	time_t old, now;

	bool clear_flag = false;
	bool time_moved_flag = true;

	ItemFloor itf;
	QuizFloor qf;

	int now_qf = 0;
	int qf_size = QZ_FLOOR_SIZE;

	itf.item_floor_main();
	time(&old);

	_getch();
	/*
	while (time_limit > 0 && !clear_flag)
	{
		time(&now);
		if (old != now)
		{
			time_limit -= (now - old);
			time_moved_flag = true;
		}
		if (time_moved_flag)
		{
			time(&old);
			setCursorPos(60, 0);
			cout << "Žc‚èŽžŠÔF" << time_limit / 60 << "•ª" << time_limit % 60 << "•b";
			time_moved_flag = false;
		}
		if (now_qf < qf_size)
		{
			now_qf += qf.quiz_floor_main();
		}
		else
		{
			clear_flag = true;
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
	*/
	return 0;
}