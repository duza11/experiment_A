#pragma once

#include <conio.h>
#include <iostream>
#include <random>
#include "player.h"
#include "console_util.h"
#include "common.h"

class ItemFloor
{
public:
	ItemFloor(); // 池田マイク
	int ItemFloorMain(); // 池田マイク
	void Update(pair<int, int> p_pos, pair<int, int> np_pos); // 清水大樹
	void Print(); // 池田マイク
	void PrintLine(int y, bool print_value_flag); // 池田マイク
	bool CheckGoal(); // 清水大樹

private:
	typedef struct
	{
		int room_status;
		int item_status;
		int item_get_flag;
	} Room;
	Room room_[ITEM_FLOOR_WIDTH][ITEM_FLOOR_HEIGT];
	bool changed_flag_;
	bool goal_flag_;
	pair<int, int> item_position_;
	random_device rnd;
	TextBox *text_box_;
	string message_;
};