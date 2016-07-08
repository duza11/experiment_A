#include "tutorial_item_floor.h"

TutorialItemFloor::TutorialItemFloor() : ItemFloor::ItemFloor()
{
}

void TutorialItemFloor::Print()
{
	SetCursorPosition(0, 0);
	for (int y = 0; y < ITEM_FLOOR_HEIGHT; y++) // PrintLineを利用してダンジョンを出力
	{
		PrintLine(y, false);
		PrintLine(y, true);
		PrintLine(y, false);
	}
	SetColor(COL_WHITE, COL_BLACK); // 文字色を白,背景色を黒に設定
	SetCursorPosition(70, 5);
	cout << "移動：[←][→]";
	SetCursorPosition(70, 6);
	cout << "決定：[ENTER]";
	Player::GetInstance().PrintItemStatus(item_position_); // 所有アイテムを出力
	SetCursorPosition(70, 11);
	SetColor(COL_WHITE, COL_DARK_GREEN);
	cout << "P";
	SetColor(COL_WHITE, COL_BLACK);
	cout << "：プレイヤーの位置";
	SetCursorPosition(70, 12);
	SetColor(COL_WHITE, COL_DARK_YELLOW);
	cout << "N";
	SetColor(COL_WHITE, COL_BLACK);
	cout << "：プレイヤーの移動先";
	SetCursorPosition(70, 13);
	SetColor(COL_WHITE, COL_DARK_BLUE);
	cout << " ";
	SetColor(COL_WHITE, COL_BLACK);
	cout << "：スタート地点";
	SetCursorPosition(70, 14);
	SetColor(COL_WHITE, COL_DARK_RED);
	cout << " ";
	SetColor(COL_WHITE, COL_BLACK);
	cout << "：ゴール地点";
	SetCursorPosition(70, 15);
	SetColor(COL_WHITE, COL_LIGHT_GRAY);
	cout << " ";
	SetColor(COL_WHITE, COL_BLACK);
	cout << "：部屋";
	SetCursorPosition(MESSAGE_X, MESSAGE_Y);
	cout << message_;
	SetCursorPosition(0, 0);
}
