#pragma once

#include <string>
#include <random>
#include "common.h"
#include "console_util.h"
#include "timer.h"

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
	static Player &GetInstance();
	pair<int, int> get_now_position();
	pair<int, int> get_next_position();
	void MoveNextPositionLeft();
	void MoveNextPositionRight();
	void MovePositionFront();
	void GetItem(int item_num);
	void UseItem(int item_num, Quiz &quiz);
	void GoUpstairs();
	int get_now_floor();
	void PrintNowFloor();
	void EnableItem();
	void PrintItemStatus(pair<int, int> position);

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