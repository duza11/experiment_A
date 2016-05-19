#pragma once

#include <utility>
#include "common.h"
#include "field.h"

using namespace std;

class Player
{
public:
	Player();
	~Player();
	pair<int, int> player_get_pos();
	pair<int, int> player_get_next_pos();
	void player_move_left();
	void player_move_right();
	void player_move_front();

private:
	pair<int, int> p_pos;
	pair<int, int> np_pos;
};