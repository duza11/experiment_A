#pragma once

#include <string>
#include <random>
#include "common.h"
#include "console_util.h"
#include "timer.h"
#include "quiz_floor.h"

using namespace std;

class Player
{
public:
	// プレイヤーのインスタンスの取得
	static Player &GetInstance(); // 清水大樹
	void Initialize();
	//プレイヤーの現在位置を取得
	pair<int, int> get_now_position(); // 清水大樹
	//プレイヤーの移動先位置を取得
	pair<int, int> get_next_position(); // 清水大樹
	//プレイヤーの移動先座標を左に移動
	void MoveNextPositionLeft(); // 清水大樹
	//プレイヤーの移動先座標を右に移動
	void MoveNextPositionRight(); // 清水大樹
	//プレイヤーの座標を移動
	void MovePositionFront(); // 清水大樹
	//アイテムの獲得
	string GetItem(int item_num); // 清水大樹
	//アイテムの使用
	void UseItem(int item_num, Quiz &quiz, IQuizFloor *iqf); // 清水大樹
	//階を昇る
	void GoUpstairs(); // 清水大樹
	//現在の階を取得
	int get_now_floor(); // 清水大樹
	//現在の階を表示
	void PrintNowFloor(); // 清水大樹
	//アイテムを使用可能にする
	void EnableItem(); // 清水大樹
	//アイテムの所持情報を表示
	void PrintItemStatus(pair<int, int> position); // 清水大樹
	//アイテムの説明を表示
	void PrintItemExplain(int item_num, pair<int, int> position); // 清水大樹
	//アイテム無使用フラグを取得
	bool get_no_item_flag();

	void AddTypingCounter();

	int get_typing_counter();

private:
	//プレイヤー情報の初期化
	Player(); // 清水大樹
	Player(const Player &Player) {} // 清水大樹
	~Player() {} // 清水大樹
	//回答を半分にするアイテムの使用
	void UseFiftyFity(Quiz &quiz, IQuizFloor *iqf); // 清水大樹
	//時間を止めるアイテムの使用
	void UseStopTimer(); // 清水大樹

	//アイテム用構造体
	typedef struct
	{
		string item_name;
		int item_count;
		bool enable_flag;
		vector<string> item_explain;
	} Item;

	random_device rnd; //乱数生成クラス
	pair<int, int> now_position_; //現在座標
	pair<int, int> next_position_; //移動先座標
	int now_floor_; //現在の階
	Item item_[kItemKind]; //アイテム構造体
	bool no_item_flag_;
	int typing_counter_;
};