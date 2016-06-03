#pragma once

#include <string>
#include <random>
#include "common.h"
#include "console_util.h"
#include "timer.h"

using namespace std;

//アイテム用の列挙型
typedef enum
{
	kFiftyFifty,
	kStopTimer,

	kItemKind,
} ItemNum;

class Player
{
public:
	// プレイヤーのインスタンスの取得
	static Player &GetInstance();
	//プレイヤーの現在位置を取得
	pair<int, int> get_now_position();
	//プレイヤーの移動先位置を取得
	pair<int, int> get_next_position();
	//プレイヤーの移動先座標を左に移動
	void MoveNextPositionLeft();
	//プレイヤーの移動先座標を右に移動
	void MoveNextPositionRight();
	//プレイヤーの座標を移動
	void MovePositionFront();
	//アイテムの獲得
	void GetItem(int item_num);
	//アイテムの使用
	void UseItem(int item_num, Quiz &quiz);
	//階を昇る
	void GoUpstairs();
	//現在の階を取得
	int get_now_floor();
	//現在の階を表示
	void PrintNowFloor();
	//アイテムを使用可能にする
	void EnableItem();
	//アイテムの所持情報を表示
	void PrintItemStatus(pair<int, int> position);

private:
	//プレイヤー情報の初期化
	Player();
	Player(const Player &Player) {}
	~Player() {}
	//回答を半分にするアイテムの使用
	void UseFiftyFity(Quiz &quiz);
	//時間を止めるアイテムの使用
	void UseStopTimer();

	//アイテム用構造体
	typedef struct
	{
		string item_name;
		int item_count;
		bool enable_flag;
	} Item;

	random_device rnd; //乱数生成クラス
	pair<int, int> now_position_; //現在座標
	pair<int, int> next_position_; //移動先座標
	int now_floor_; //現在の階
	Item item_[kItemKind]; //アイテム構造体
};