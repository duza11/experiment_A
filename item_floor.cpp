#include "item_floor.h"

ItemFloor::ItemFloor()
{
	// 1F内の部屋の初期化
	for (int y = 0; y < ITEM_FLOOR_HEIGT; y++) {
		for (int x = 0; x < ITEM_FLOOR_WIDTH; x++) {
			if (y == 0 || y == ITEM_FLOOR_HEIGT - 1)
			{
				room_[x][y] = { 0, -1, true };	// y = ITEM_FLOOR_HEIGHT(スタート位置),y = 0(ゴール位置)ではアイテムなし,アイテム所得フラグをtrueにする
			}
			else
			{
				room_[x][y] = { 0, (x - 1), false }; // それ以外の部屋は2種類のアイテムかアイテムなしとして,アイテム所得用フラグをfalseにする
			}
		}
		for (int x = 0; x < ITEM_FLOOR_WIDTH; x++) // アイテムの配置をランダムにする
		{
			int ran_num = (unsigned)rnd() % ITEM_FLOOR_WIDTH;
			int temp = room_[x][y].item_status;
			room_[x][y].item_status = room_[ran_num][y].item_status;
			room_[ran_num][y].item_status = temp;
		}
	}

	this->goal_flag_ = false; // ゴール判定フラグをfalseにする
	this->item_position_ = { 70, 8 }; // アイテム情報描画座標を(70, 8)にする
	this->changed_flag_ = true; // 画面更新判定フラグをtrueにする
	this->text_box_ = new TextBox({ MESSAGE_BOX_X, MESSAGE_BOX_Y }, MESSAGE_BOX_WIDTH, MESSAGE_BOX_HEIGHT);
}

int ItemFloor::ItemFloorMain() // 1Fのゲーム進行を管理する関数
{
	while (!this->goal_flag_) // ゴール判定フラグがfalseである限り繰り返す
	{
		if (_kbhit()) // キー入力があるか判定
		{
			int input_key = _getch(); // キー入力を受け取る
			if (input_key == KEY_ENTER)
			{
				Player::GetInstance().MovePositionFront(); // スペースキーであればプレイヤーを移動する
				changed_flag_ = true;
			}
			else if (input_key == KEY_ARROW)
			{
				input_key = _getch(); // 十字キーであれば再びキー入力を受け取る
				switch (input_key) {
				case KEY_LEFT:
					Player::GetInstance().MoveNextPositionLeft(); // 左キーであれば移動先座標を左に移動する
					changed_flag_ = true;
					break;
				case KEY_RIGHT:
					Player::GetInstance().MoveNextPositionRight(); // 右キーであれば移動先座標を右に移動する
					changed_flag_ = true;
					break;
				}
			}
		}
		if (changed_flag_) // 画面更新判定フラグがtrueであれば1Fの情報の更新,描画を行う
		{
			Update(Player::GetInstance().get_now_position(), Player::GetInstance().get_next_position()); // 1Fの情報の更新
			Print(); // 1Fの描画
			changed_flag_ = false; // 画面更新判定フラグをfalseにする
		}
	}
	while (1)
	{
		if (_kbhit())
		{
			int input_key = _getch();
			if (input_key == KEY_ENTER)
			{
				break;
			}
			else if (input_key == 0x00 || input_key == KEY_ARROW)
			{
				_getch();
			}
		}
	}
	Player::GetInstance().GoUpstairs(); // プレイヤーの階を1つ進める
	delete text_box_;
	system("cls"); // 画面を消去する
	return 0;
}

void ItemFloor::Update(pair<int, int> now_position, pair<int, int> next_position)
{
	for (int x = 0; x < ITEM_FLOOR_WIDTH; x++)
	{
		for (int y = 0; y < ITEM_FLOOR_HEIGT; y++)
		{
			if (x == now_position.first && y == now_position.second)
			{
				text_box_->Print();
				if (room_[x][y].item_get_flag == false) // プレイヤーの座標かつアイテム所得フラグがfalseならばアイテムを獲得する
				{
					this->message_ = Player::GetInstance().GetItem(room_[x][y].item_status);
					room_[x][y].item_get_flag = true;
				}
				else
				{
					this->message_.clear();
				}
				room_[x][y].room_status = 1; // プレイヤーのいる部屋の状態を1にする
			}
			else if (x == next_position.first && y == next_position.second)
			{
				room_[x][y].room_status = 2; // プレイヤーの移動先の部屋の状態を2にする
			}
			else
			{
				room_[x][y].room_status = 0; // それ以外の部屋の状態を0にする
			}
		}
	}
	if (this->goal_flag_ = CheckGoal()) // プレイヤーがゴールにいるか判定)
	{
		message_ = "クリアです [ENTER]で次に進む";
	}
}

void ItemFloor::Print()
{

	SetCursorPosition(0, 0);
	for (int y = 0; y < ITEM_FLOOR_HEIGT; y++) // PrintLineを利用してダンジョンを出力
	{
		PrintLine(y, false);
		PrintLine(y, true);
		PrintLine(y, false);
	}
	SetColor(COL_WHITE, COL_BLACK); // 文字色を白,背景色を黒に設定
	Player::GetInstance().PrintNowFloor();
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

void ItemFloor::PrintLine(int y, bool print_value_flag)
{
	for (int x = 0; x < ITEM_FLOOR_WIDTH; x++) {
		int fg = COL_WHITE;
		int bg = COL_BLACK;
		switch (room_[x][y].room_status) {
		case 0:
			if (y == 0)
			{
				bg = COL_DARK_RED; // yが0(ゴール地点)ならば背景色を赤にする
			}
			else if (y == ITEM_FLOOR_HEIGT - 1)
			{
				bg = COL_DARK_BLUE; // yがITEM_FLOOR_HEIGT-1(スタート地点)ならば背景色を青にする
			}
			else
			{
				bg = COL_LIGHT_GRAY; // それ以外は背景色をグレーにする
			}
			break;
		case 1:
			bg = COL_DARK_GREEN; // 部屋の状態が1(プレイヤーが居る)ならば背景色を緑にする
			break;
		case 2:
			bg = COL_DARK_YELLOW; // 部屋の状態が2(プレイヤーの移動先)ならば背景色を黄にする
			break;
		}
		SetColor(fg, bg);
		string str(CELL_WIDTH, ' ');
		if (print_value_flag) {
			if (!room_[x][y].room_status)
			{
				str = '.'; // 部屋の状態が0(プレイヤー,移動先ではない)の場合.をセットする
			}
			else
			{
				if (room_[x][y].room_status == 1) // 部屋の状態が1(プレイヤー)の場合Pをセットする
				{
					str = 'P';
				}
				else if (room_[x][y].room_status == 2) // 部屋の状態が2(プレイヤーの移動先)の場合Nをセットする
				{
					str = 'N';
				}
			}
			str += string((CELL_WIDTH - str.size()) / 2, ' ');		//	末尾に空白パディング
			str = string(CELL_WIDTH - str.size(), ' ') + str;		//	先頭に空白パディング
		}
		cout << str;
	}
	cout << "\n";
}

bool ItemFloor::CheckGoal()
{
	for (int x = 0; x < ITEM_FLOOR_WIDTH; x++)
	{
		if (room_[x][0].room_status == 1) {
			return true;
		}
	}
	return false;
}