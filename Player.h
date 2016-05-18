#pragma once

#include <utility>
#include "common.h"

using namespace std;

class Player
{
public:
	Player();
	~Player();
	void player_set_pos(int(&g_board)[BOARD_ARY_WD][BOARD_ARY_HT]);
	void player_move_left(int(&g_board)[BOARD_ARY_WD][BOARD_ARY_HT]);
	void player_move_right(int(&g_board)[BOARD_ARY_WD][BOARD_ARY_HT]);
	void player_move_front(int(&g_board)[BOARD_ARY_WD][BOARD_ARY_HT]);

private:
	int x, y;
	int next_x, next_y;
};