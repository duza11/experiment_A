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
		for (bool moved = true;;)
		{
			if (moved)
			{
				f.field_update(p.player_get_pos(), p.player_get_next_pos());
				f.field_print();
				moved = false;
			}
			setColor(COL_WHITE, COL_BLACK);
			cout << "Type ©¨     ";
			int c = _getch();
			//cout << c << "\n";
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
				//cout << c << "\n";
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
		}
		setColor(COL_WHITE, COL_BLACK);
		cout << "Try again ? [y/n]   ";
		int c;
		for (;;) {
			c = _getch();
			if (c == KEY_ARROW)
				_getch();
			if (c == 'y' || c == 'Y' ||
				c == 'n' || c == 'N')
			{
				break;
			}
		}
		if (c != 'y' && c != 'Y') break;
	}
	return 0;
}