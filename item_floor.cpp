#include "item_floor.h"

ItemFloor::ItemFloor()
{
	clear_flag = false;
}

ItemFloor::~ItemFloor()
{
}

int ItemFloor::item_floor_main()
{
	while (1) {
		for (bool moved = true;this->clear_flag != true;)
		{
			if (moved)
			{
				f.field_update(p.player_get_pos(), p.player_get_next_pos());
				f.field_print();
				setColor(COL_WHITE, COL_BLACK);
				cout << "Type ©¨     ";
				moved = false;
			}
			int c = _getch();
			if (c == 'q')
			{
				break;
			}
			if (c == ' ')
			{
				p.player_move_front();
				moved = true;
			}
			else if (c == KEY_ARROW)
			{
				int c = _getch();
				switch (c) {
				case KEY_LEFT:
					p.player_move_left();
					moved = true;
					break;
				case KEY_RIGHT:
					p.player_move_right();
					moved = true;
					break;
				}
			}
			this->clear_flag = f.field_clear_check();
		}
		break;
	}
	return 0;
}