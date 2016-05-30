#include "item_floor.h"

ItemFloor::ItemFloor()
{
	for (int x = 0; x < BOARD_WD; ++x) {
		for (int y = 0; y < BOARD_HT; ++y) {
			if ((x == 0 || x == BOARD_WD - 1) && (y == 0 || y == BOARD_HT - 1))
			{
				//g_board[x][y] = WALL;
				room[x][y].room_status = WALL;
				room[x][y].item_status = -1;
				room[x][y].item_get_flag = true;
			}
			else if (y == 0 || y == BOARD_HT - 1)
			{
				room[x][y].room_status = 0;
				room[x][y].item_status = -1;
				room[x][y].item_get_flag = true;
			}
			else
			{
				room[x][y].room_status = 0;
				room[x][y].item_status = x - 1;
				room[x][y].item_get_flag = false;
			}
		}
	}
	this->clear_flag = false;
	setColor(COL_WHITE);
	setCursorPos(60, 3);
	cout << "移動：[←][→]";
	setCursorPos(60, 4);
	cout << "選択：[SPACE]";
	setCursorPos(0, 0);
}

ItemFloor::~ItemFloor()
{
}

int ItemFloor::item_floor_main()
{
	Player::GetInstance().PrintNowFloor();
	for (this->changed_flag = true; !this->clear_flag;)
	{
		if (changed_flag)
		{
			//Update(p.player_get_pos(), p.player_get_next_pos());
			Update(Player::GetInstance().get_now_position(), Player::GetInstance().get_next_position());
			Print();
			setColor(COL_WHITE, COL_BLACK);
			changed_flag = false;
		}if (_kbhit())
		{
			int c = _getch();
			if (c == 'q')
			{
				exit(0);
			}
			if (c == KEY_SPACE)
			{
				//p.player_move_front();
				Player::GetInstance().MovePositionFront();
				changed_flag = true;
			}
			else if (c == KEY_ARROW)
			{
				int c = _getch();
				switch (c) {
				case KEY_LEFT:
					//p.player_move_left();
					Player::GetInstance().MoveNextPositionLeft();
					changed_flag = true;
					break;
				case KEY_RIGHT:
					//p.player_move_right();
					Player::GetInstance().MoveNextPositionRight();
					changed_flag = true;
					break;
				}
			}
		}
		this->clear_flag = CheckGoal();
	}
	Player::GetInstance().GoUpstairs();
	system("cls");

	return 0;
}

void ItemFloor::Update(pair<int, int> now_position, pair<int, int> next_position)
{
	for (int x = 0; x < BOARD_WD; x++)
	{
		for (int y = 0; y < BOARD_HT; y++)
		{
			if (x == now_position.first && y == now_position.second)
			{
				if (room[x][y].item_get_flag == false)
				{

					//Item::get_instance().get_item(room[x][y].item_status);
					Player::GetInstance().GetItem(room[x][y].item_status);
					room[x][y].item_get_flag == true;
				}
				room[x][y].room_status = 'P';
			}
			else if (x == next_position.first && y == next_position.second)
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

void ItemFloor::Print()
{
	setCursorPos(0, 0);
	for (int y = 0; y < BOARD_HT; y++)
	{
		PrintLine(y, false);
		PrintLine(y, true);
		PrintLine(y, false);
	}
}

void ItemFloor::PrintLine(int y, bool print_value_flag)
{
	for (int x = 0; x < BOARD_WD; x++) {
		int v = room[x][y].room_status;
		//setColor(fgColor(v), bgColor(v));
		setFgBgColor(v);
		string str(CELL_WIDTH, ' ');
		if (print_value_flag) {
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

bool ItemFloor::CheckGoal()
{
	for (int x = 0; x < BOARD_WD; x++)
	{
		if (room[x][0].room_status == 'P') {
			return true;
		}
	}
	return false;
}