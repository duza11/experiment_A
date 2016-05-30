#include <time.h>			//	time
#include <string>
#include "item_floor.h"
#include "quiz_floor.h"
#include "common.h"
#include "timer.h"
#include "Player.h"

int main()
{
	system("cls");

	ItemFloor itf;
	QuizFloor qf;

	itf.item_floor_main();
	Timer::get_instance();
	qf.quiz_floor_main();

	system("cls");

	if (Player::GetInstance().get_now_floor() == 9)
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