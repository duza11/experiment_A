#pragma once

#include <utility>
#include <string>
#include <random>
#include "common.h"
#include "quiz.h"

using namespace std;

/*
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
};*/

typedef enum
{
	kFiftyFifty,
	kStopTimer,

	kItemKind,
} ItemNum;

class Player
{
public:
	static Player &GetInstance()
	{
		static Player player;
		return player;
	}
	pair<int, int> get_now_position();
	pair<int, int> get_next_position();
	void MoveNextPositionLeft();
	void MoveNextPositionRight();
	void MovePositionFront();
	void GetItem(int item_num);
	void UseItem(int item_num, Quiz &quiz);

private:
	Player();
	Player(const Player & Player) {}
	~Player() {}


	typedef struct
	{
		string item_name;
		int item_count;
		bool enable_flag;
	} Item;

	random_device rnd;
	pair<int, int> now_position_;
	pair<int, int> next_position_;
	int now_floor_;
	Item item_[kItemKind];
};