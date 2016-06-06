#pragma once

#include <string>

using namespace std;

/*1F関連*/
#define WALL -1	// 壁
#define ITEM_FLOOR_WIDTH 3 // 1Fのダンジョンの横幅
#define ITEM_FLOOR_HEIGT 7 // 1Fのダンジョンの縦幅
#define CELL_WIDTH 8 // セル表示幅
#define PLAYER_X (ITEM_FLOOR_WIDTH / 2) // プレイヤーの初期X座標
#define PLAYER_Y ITEM_FLOOR_HEIGT - 1 // プレイヤーの初期Y座標
#define PLAYER_NEXT_X PLAYER_X // プレイヤーの次の初期X座標
#define PLAYER_NEXT_Y (PLAYER_Y - 1) // プレイヤーの次の初期Y座標
/*タイマー関連*/
#define REMAINING_TIME 600 // 制限時間
/*2F以降関連*/
#define QUIZ_FLOOR_SIZE 7 // クイズを出題する階数
#define QUIZ_OPTION_SIZE 6 // クイズの選択肢の数
#define QUIZ_DATA_SIZE ((QUIZ_OPTION_SIZE * 2) + 2) // CVSにおけるクイズ1問のデータ数
/*基本メニュー関連*/
#define BASE_MENU_BOX_X 0
#define BASE_MENU_BOX_Y 20
#define BASE_MENU_OPTION_X (BASE_MENU_BOX_X + 3)
#define BASE_MENU_OPTION_Y (BASE_MENU_BOX_Y + 1)
#define BASE_MENU_BOX_WIDTH 16
#define BASE_MENU_BOX_HEIGHT 4
/*回答メニュー関連*/
#define ANSWER_MENU_BOX_X 10
#define ANSWER_MENU_BOX_Y 16
#define ANSWER_MENU_OPTION_X (ANSWER_MENU_BOX_X + 3)
#define ANSWER_MENU_OPTION_Y (ANSWER_MENU_BOX_Y + 1)
#define ANSWER_MENU_BOX_WIDTH 40
#define ANSWER_MENU_BOX_HEIGHT 8
/*アイテムメニュー関連*/
#define ITEM_MENU_BOX_X 10
#define ITEM_MENU_BOX_Y 20
#define ITEM_MENU_OPTION_X (ITEM_MENU_BOX_X + 3)
#define ITEM_MENU_OPTION_Y (ITEM_MENU_BOX_Y + 1)
#define ITEM_MENU_BOX_WIDTH 16
#define ITEM_MENU_BOX_HEIGHT 4

//アイテム用の列挙型
typedef enum
{
	kFiftyFifty,
	kStopTimer,

	kItemKind,
} ItemNum;

typedef struct
{
	string typing_str;
	string quiz_str;
	string quiz_opt[QUIZ_OPTION_SIZE];
	bool answer_type[QUIZ_OPTION_SIZE];
	bool enable_flag[QUIZ_OPTION_SIZE];
} Quiz;