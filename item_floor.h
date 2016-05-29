#pragma once

#include <conio.h>		//	_getch
#include <iostream>
#include "player.h"
#include "consoleUtil.h"
#include "item.h"

class ItemFloor
{
public:
	ItemFloor();
	~ItemFloor();
	int item_floor_main();
	void Update(pair<int, int> p_pos, pair<int, int> np_pos);
	void Print();
	void PrintLine(int y, bool print_value_flag);
	bool CheckGoal();
	bool CheckInputKey();

private:
	typedef struct
	{
		int room_status;
		int item_status;
		int item_get_flag;
	} Room;
	Room room[BOARD_WD][BOARD_HT];
	bool changed_flag;
	bool clear_flag;
	//Player p;
};