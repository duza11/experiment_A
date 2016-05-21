#include <time.h>			//	time
#include <string>
#include "item_floor.h"
#include "quiz_floor.h"
#include "common.h"

int main()
{
	system("cls");
	ItemFloor itf;
	itf.item_floor_main();
	QuizFloor qf;
	qf.quiz_floor_main();
	system("cls");
	return 0;
}