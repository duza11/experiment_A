#pragma once

#include <utility>
#include <string>
#include <random>
#include "common.h"
#include "consoleUtil.h"
#include "Timer.h"

using namespace std;

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
	Player(const Player &Player) {}
	~Player() {}
	void UseFiftyFity(Quiz &quiz);
	void UseStopTimer();

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