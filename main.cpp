#include <time.h>			//	time
#include <string>
#include "item_floor.h"
#include "quiz_floor.h"
#include "common.h"
#include "timer.h"

int main()
{
	system("cls");

	bool clear_flag = false;

	ItemFloor itf;
	QuizFloor qf;

	itf.item_floor_main();
	Timer::get_instance();

	qf.quiz_floor_main();
	clear_flag = true;

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