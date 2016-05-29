#include "Field.h"

Field::Field()
{
	for (int x = 0; x < BOARD_WD; ++x) {
		for (int y = 0; y < BOARD_HT; ++y) {
			if ((x == 0 || x == BOARD_WD - 1) && (y == 0 || y == BOARD_HT - 1))
			{
				//g_board[x][y] = WALL;
				room[x][y].room_status = WALL;
				room[x][y].item_status = -1;
			}
			else if (y == 0 || y == BOARD_HT - 1)
			{
				room[x][y].room_status = 0;
				room[x][y].item_status = -1;
			}
			else
			{
				room[x][y].room_status = 0;
				room[x][y].item_status = x - 1;
			}
		}
	}
}

Field::~Field()
{
}

void Field::field_update(pair<int, int> p_pos, pair<int, int> np_pos)
{
	for (int x = 0; x < BOARD_WD; x++)
	{
		for (int y = 0; y < BOARD_HT; y++)
		{
			if (x == p_pos.first && y == p_pos.second)
			{
				if (room[x][y].item_get_flag == false)
				{
					Item::get_instance().get_item(room[x][y].item_status);
					room[x][y].item_get_flag == true;
				}
				room[x][y].room_status = 'P';
			}
			else if (x == np_pos.first && y == np_pos.second)
			{
				room[x][y].room_status = 'N';
			}
			else
			{
				room[x][y].room_status = 0;
			}
		}
	}
}

void Field::field_print_line(int y, bool printVal)
{
	for (int x = 0; x < BOARD_WD; x++) {
		int v = room[x][y].room_status;
		//setColor(fgColor(v), bgColor(v));
		setFgBgColor(v);
		string str(CELL_WIDTH, ' ');
		if (printVal) {
			if (!v)
				str = '.';
			else
				str = v;
			str += string((CELL_WIDTH - str.size()) / 2, ' ');		//	末尾に空白パディング
			str = string(CELL_WIDTH - str.size(), ' ') + str;		//	先頭に空白パディング
		}
		cout << str;
	}
	cout << "\n";
}

void Field::field_print()
{
	setCursorPos(0, 0);
	for (int y = 0; y < BOARD_HT; y++)
	{
		field_print_line(y, false);
		field_print_line(y, true);
		field_print_line(y, false);
	}
}

bool Field::field_clear_check()
{
	for (int x = 0; x < BOARD_WD; x++)
	{
		if (room[x][0].room_status == 'P') {
			return true;
		}
	}
	return false;
}
