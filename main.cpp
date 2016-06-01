#include "item_floor.h"
#include "quiz_floor.h"
#include "timer.h"
#include "Player.h"
#include "double_buffer.h"

int main()
{
	system("cls");
	
	SetCursorDisplay(FALSE);
	ItemFloor itf;
	QuizFloor qf;

	itf.ItemFloorMain();
	Timer::GetInstance();
	qf.QuizFloorMain();

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