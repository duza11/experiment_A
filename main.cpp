#include "item_floor.h"
#include "quiz_floor.h"
#include "timer.h"
#include "player.h"

void ClearJudge()
{
	if (Player::GetInstance().get_now_floor() == 9)
	{
		cout << "GAME CLEAR";
	}
	else
	{
		cout << "GAME OVER";
	}
}

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
	ClearJudge();
	
	_getch();

	return 0;
}