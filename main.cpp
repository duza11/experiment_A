#include "console_util.h"
#include "game_manager.h"

// "main.cpp"以外の関数担当者はヘッダーファイルの関数定義の横に記述
// タイピングとクイズの問題はCSVファイルから読み込むため
// 提出用のファイルで実行するとエラーが発生するかもしれません

int main() // 全員
{
	SetBufferSize(120, 30); // スクリーンバッファのサイズを120×30に変更
	SetCursorDisplay(FALSE);	// カーソルの非表示化
	while (true)
	{
		system("cls");	// 画面を消去
		
		GameManager gm;

		gm.PrintTitle();
		gm.PrintStartMenu();
	}

	return 0;
}