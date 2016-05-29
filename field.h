#pragma once

#include <new.h>
#include <iostream>
#include <sstream>      // std::ostringstream
#include <string>
#include "consoleUtil.h"
#include "common.h"
#include "item.h"

using namespace std;

class Field
{
public:
	Field();
	~Field();
	void field_update(pair<int, int> p_pos, pair<int, int> np_pos);
	void field_print_line(int y, bool printVal);
	void field_print();
	bool field_clear_check();

private:
	typedef struct
	{
		int room_status;
		int item_status;
		int item_get_flag;
	} Room;
	Room room[BOARD_WD][BOARD_HT];
};