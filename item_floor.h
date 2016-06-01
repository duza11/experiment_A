#pragma once

#include <conio.h>
#include <iostream>
#include <random>
#include "player.h"
#include "console_util.h"
#include "common.h"
#include "double_buffer.h"

class ItemFloor
{
public:
	ItemFloor();
	~ItemFloor();
	int ItemFloorMain();
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
	Room room_[ITEM_FLOOR_WIDTH][ITEM_FLOOR_HEIGT];
	bool changed_flag_;
	bool clear_flag_;
	pair<int, int> item_position_;
	random_device rnd;
};