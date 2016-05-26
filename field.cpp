#include "Field.h"

Field::Field()
{
	for (int x = 0; x < BOARD_ARY_WD; ++x) {
		for (int y = 0; y < BOARD_ARY_HT; ++y) {
			if (x == 0 || x == BOARD_WD + 1 ||
				y == 0 || y == BOARD_HT + 1)
			{
				//g_board[x][y] = WALL;
				new(fr + x) FieldRoom(WALL, 0);
			}
			else {
				//g_board[x][y] = 0;
				new(fr + x) FieldRoom(0, x - 2);
			}
		}
	}
}

Field::~Field()
{
}

void Field::field_update(pair<int, int> p_pos, pair<int, int> np_pos)
{
	for (int x = 1; x <= BOARD_WD; x++)
	{
		for (int y = 1; y <= BOARD_HT; y++)
		{
			if (x == p_pos.first && y == p_pos.second)
			{
				if (fr[x][y].field_room_get_item_flag())
				{
					Item::get_instance().get_item(fr[x][y].field_room_get_item());
					fr[x][y].field_room_set_item_flag(false);
				}
				fr[x][y].field_room_update('P');
			}
			else if (x == np_pos.first && y == np_pos.second)
			{
				fr[x][y].field_room_update('N');
			}
			else
			{
				fr[x][y].field_room_update(0);
			}
		}
	}
}

void Field::field_print_line(int y, bool printVal)
{
	for (int x = 1; x <= BOARD_WD; ++x) {
		int v = fr[x][y].field_room_get_status();
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
	for (int y = 1; y < BOARD_HT + 1; y++)
	{
		field_print_line(y, false);
		field_print_line(y, true);
		field_print_line(y, false);
	}
}

bool Field::field_clear_check()
{
	for (int x = 1; x <= BOARD_WD; x++)
	{
		if (fr[x][1].field_room_get_status() == 'P') {
			return true;
		}
	}
	return false;
}
