#include "item_floor.h"

ItemFloor::ItemFloor()
{
	this->clear_flag = false;
	this->movable_flag = true;
	setCursorPos(60, 2);
	cout << "ˆÚ“®F[©][¨]";
	setCursorPos(60, 3);
	cout << "‘I‘ðF[SPACE]";
	setCursorPos(0, 0);
}

ItemFloor::~ItemFloor()
{
}

int ItemFloor::item_floor_main()
{
	while (1) {
		for (this->moved_flag = true;!this->clear_flag;)
		{
			if (moved_flag)
			{
				f.field_update(p.player_get_pos(), p.player_get_next_pos());
				f.field_print();
				setColor(COL_WHITE, COL_BLACK);
				moved_flag = false;
			}if (_kbhit())
			{
				int c = _getch();
				if (c == 'q')
				{
					exit(0);
				}
				if (c == KEY_SPACE)
				{
					p.player_move_front();
					moved_flag = true;
				}
				else if (c == KEY_ARROW)
				{
					int c = _getch();
					switch (c) {
					case KEY_LEFT:
						p.player_move_left();
						moved_flag = true;
						break;
					case KEY_RIGHT:
						p.player_move_right();
						moved_flag = true;
						break;
					}
				}
			}
			this->clear_flag = f.field_clear_check();
		}
		break;
	}
	return 0;
}