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
	ItemFloor(); // �r�c�}�C�N
	int ItemFloorMain(); // �r�c�}�C�N
	void Update(pair<int, int> p_pos, pair<int, int> np_pos); // �������
	void Print(); // �r�c�}�C�N
	void PrintLine(int y, bool print_value_flag); // �r�c�}�C�N
	bool CheckGoal(); // �������

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