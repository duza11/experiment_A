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
				new(fr + x) FieldRoom(0, 0);
			}
		}
	}
}

Field::~Field()
{
}

void Field::field_update(pair<int, int> p_pos, pair<int, int>np_pos)
{
	for (int x = 1; x < BOARD_WD + 1; x++)
	{
		for (int y = 1; y < BOARD_HT + 1; y++)
		{
			if (x == p_pos.first && y == p_pos.second)
			{
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
			str += string((CELL_WIDTH - str.size()) / 2, ' ');		//	�����ɋ󔒃p�f�B���O
			str = string(CELL_WIDTH - str.size(), ' ') + str;		//	�擪�ɋ󔒃p�f�B���O
		}
		cout << str;
	}
	cout << "\n";
}

void Field::field_print()
{
	setCursorPos(0, 0);
	setColor(COL_WHITE, COL_BLACK);
	cout << "SCORE: " << 0 << "        \n\n";
	for (int y = 1; y < BOARD_HT + 1; y++)
	{
		field_print_line(y, false);
		field_print_line(y, true);
		field_print_line(y, false);
	}
}