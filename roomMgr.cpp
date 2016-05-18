#include "roomMgr.h"

RoomMgr::RoomMgr()
{
	for (int x = 0; x < BOARD_WD + 2; ++x) {
		for (int y = 0; y < BOARD_HT + 2; ++y) {
			if (x == 0 || x == BOARD_WD + 1 ||
				y == 0 || y == BOARD_HT + 1)
			{
				//g_board[x][y] = WALL;
				new(r + x) Room(WALL, 0);
			}
			else {
				//g_board[x][y] = 0;
				new(r + x) Room(0, 0);
			}
		}
	}
}

RoomMgr::~RoomMgr()
{
}