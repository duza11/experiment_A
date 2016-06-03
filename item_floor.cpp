#include "item_floor.h"

ItemFloor::ItemFloor()
{
	for (int y = 0; y < ITEM_FLOOR_HEIGT; y++) {
		for (int x = 0; x < ITEM_FLOOR_WIDTH; x++) {
			if (y == 0 || y == ITEM_FLOOR_HEIGT - 1)
			{
				room_[x][y] = { 0, -1, true };
			}
			else
			{
				room_[x][y] = { 0, (x - 1), false };
			}
		}
		for (int x = 0; x < ITEM_FLOOR_WIDTH; x++)
		{
			int ran_num = (unsigned)rnd() % ITEM_FLOOR_WIDTH;
			int temp = room_[x][y].item_status;
			room_[x][y].item_status = room_[ran_num][y].item_status;
			room_[ran_num][y].item_status = temp;
		}
	}

	this->clear_flag_ = false;
	item_position_ = { 60, 8 };
}

ItemFloor::~ItemFloor()
{
}

int ItemFloor::ItemFloorMain()
{
	for (this->changed_flag_ = true; !this->clear_flag_;)
	{
		if (changed_flag_)
		{
			Update(Player::GetInstance().get_now_position(), Player::GetInstance().get_next_position());
			Print();
			changed_flag_ = false;
		}if (_kbhit())
		{
			int input_key = _getch();
			if (input_key == KEY_SPACE)
			{
				Player::GetInstance().MovePositionFront();
				changed_flag_ = true;
			}
			else if (input_key == KEY_ARROW)
			{
				input_key = _getch();
				switch (input_key) {
				case KEY_LEFT:
					Player::GetInstance().MoveNextPositionLeft();
					changed_flag_ = true;
					break;
				case KEY_RIGHT:
					Player::GetInstance().MoveNextPositionRight();
					changed_flag_ = true;
					break;
				}
			}
		}
		this->clear_flag_ = CheckGoal();
	}
	Player::GetInstance().GoUpstairs();

	system("cls");
	//DoubleBuffer::GetInstance().swap();
	//DoubleBuffer::GetInstance().ClearScreen();
	return 0;
}

void ItemFloor::Update(pair<int, int> now_position, pair<int, int> next_position)
{
	for (int x = 0; x < ITEM_FLOOR_WIDTH; x++)
	{
		for (int y = 0; y < ITEM_FLOOR_HEIGT; y++)
		{
			if (x == now_position.first && y == now_position.second)
			{

				if (room_[x][y].item_get_flag == false)
				{
					Player::GetInstance().GetItem(room_[x][y].item_status);
					room_[x][y].item_get_flag = true;
				}
				room_[x][y].room_status = 1;
			}
			else if (x == next_position.first && y == next_position.second)
			{
				room_[x][y].room_status = 2;
			}
			else
			{
				room_[x][y].room_status = 0;
			}
		}
	}
}

void ItemFloor::Print()
{
	
	SetCursorPosition(0, 0);
	for (int y = 0; y < ITEM_FLOOR_HEIGT; y++)
	{
		PrintLine(y, false);
		PrintLine(y, true);
		PrintLine(y, false);
	}
	SetColor(COL_WHITE, COL_BLACK);
	Player::GetInstance().PrintNowFloor();
	SetCursorPosition(60, 5);
	cout << "�ړ��F[��][��]";
	SetCursorPosition(60, 6);
	cout << "�I���F[SPACE]";
	Player::GetInstance().PrintItemStatus(item_position_);
	SetCursorPosition(0, 0);
}

void ItemFloor::PrintLine(int y, bool print_value_flag)
{
	for (int x = 0; x < ITEM_FLOOR_WIDTH; x++) {
		int room_status = room_[x][y].room_status;
		int fg = COL_WHITE;
		int bg = COL_BLACK;
		switch (room_status) {
		case 0:
			if (y == 0)
			{
				bg = COL_DARK_RED;
			}
			else if (y == ITEM_FLOOR_HEIGT - 1)
			{
				bg = COL_DARK_BLUE;
			}
			else
			{
				bg = COL_LIGHT_GRAY;
			}
			break;
		case 1:
			bg = COL_DARK_GREEN;
			break;
		case 2:
			bg = COL_DARK_YELLOW;
			break;
		}
		SetColor(fg, bg);
		string str(CELL_WIDTH, ' ');
		if (print_value_flag) {
			if (!room_status)
			{
				str = '.';
			}
			else
			{
				if (room_status == 1)
				{
					str = 'P';
				}
				else if (room_status == 2)
				{
					str = 'N';
				}
			}
			str += string((CELL_WIDTH - str.size()) / 2, ' ');		//	�����ɋ󔒃p�f�B���O
			str = string(CELL_WIDTH - str.size(), ' ') + str;		//	�擪�ɋ󔒃p�f�B���O
		}
		cout << str;
	}
	cout << "\n";
}

bool ItemFloor::CheckGoal()
{
	for (int x = 0; x < ITEM_FLOOR_WIDTH; x++)
	{
		if (room_[x][0].room_status == 1) {
			return true;
		}
	}
	return false;
}