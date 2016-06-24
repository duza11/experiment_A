#include <fstream>
#include <iostream>
#include <sstream> //文字ストリーム
#include "item_floor.h"
#include "quiz_floor.h"
#include "timer.h"
#include "player.h"
#include "console_util.h"

// "main.cpp"以外の関数担当者はヘッダーファイルの関数定義の横に記述
// タイピングとクイズの問題はCSVファイルから読み込むため
// 提出用のファイルで実行するとエラーが発生するかもしれません

int remaining_time;
int score;
string grade;

void PrintRanking()
{
	Ranking ranking;
	vector<Ranking> ranking_array;
	ifstream ifs("csv/ranking.csv");


	if (!ifs) {
		return;
	}

	string str;

	while (getline(ifs, str)) {

		int data_count = 0;
		string token;
		istringstream stream(str);

		while (getline(stream, token, ','))
		{
			switch (data_count % 4)
			{
			case 0:
				ranking.player_name = token;
				break;
			case 1:
				ranking.score = stoi(token);
				break;
			case 2:
				ranking.time = token;
				break;
			case 3:
				ranking.grade = token;
				ranking_array.push_back(ranking);
				break;
			}
			data_count++;
		}
	}

	TextBox *tb = new TextBox({ RANKING_BOX_X, RANKING_BOX_Y }, RANKING_BOX_WIDTH, RANKING_BOX_HEIGHT);
	tb->Print();
	SetCursorPosition(RANKING_CONTENT_X, RANKING_CONTENT_Y);
	cout << "順位";
	SetCursorPosition(RANKING_CONTENT_X + 5, RANKING_CONTENT_Y);
	cout << "名前";
	SetCursorPosition(RANKING_CONTENT_X + 30, RANKING_CONTENT_Y);
	cout << "スコア";
	SetCursorPosition(RANKING_CONTENT_X + 40, RANKING_CONTENT_Y);
	cout << "残り時間";
	SetCursorPosition(RANKING_CONTENT_X + 50, RANKING_CONTENT_Y);
	cout << "評価";
	for (int i = 0; i < 10; i++)
	{
		SetCursorPosition(RANKING_CONTENT_X, RANKING_CONTENT_Y + 2 + i);
		cout << i + 1;
		SetCursorPosition(RANKING_CONTENT_X + 5, RANKING_CONTENT_Y + 2 + i);
		cout << ranking_array[i].player_name;
		SetCursorPosition(RANKING_CONTENT_X + 30, RANKING_CONTENT_Y + 2 + i);
		cout << ranking_array[i].score;
		SetCursorPosition(RANKING_CONTENT_X + 40, RANKING_CONTENT_Y + 2 + i);
		cout << ranking_array[i].time;
		SetCursorPosition(RANKING_CONTENT_X + 50, RANKING_CONTENT_Y + 2 + i);
		cout << ranking_array[i].grade;
	}
	SetCursorPosition(73, RANKING_CONTENT_Y + 13);
	cout << "戻る[BACKSPACE]";
	while (_getch() != KEY_BACK)
	{
		Sleep(0);
	}
	tb->Finitialize();
	delete tb;
}

void PrintTitle()
{
	char title[TITLE_CHARACTER_SIZE][TITLE_CHARACTER_HEIGHT][TITLE_CHARACTER_WIDTH] = {
		{
			{ 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
			{ 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
			{ 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
			{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		},
		{
			{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0 },
			{ 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		} };
	for (int s = 0; s < sizeof(title) / sizeof(title[0]); s++)
	{
		for (int y = 0; y < sizeof(title[0]) / sizeof(title[0][0]); y++)
		{
			SetCursorPosition(s * TITLE_CHARACTER_WIDTH, y + 2);
			for (int x = 0; x < sizeof(title[0][0]) / sizeof(char); x++)
			{
				if (title[s][y][x])
				{
					SetColor(COL_WHITE, COL_YELLOW);
				}
				else
				{
					SetColor(COL_WHITE, COL_BLACK);
				}
				cout << " ";
			}
		}
	}
}


void PrintTutorial() // 高谷誠佑
{
	int input_key;
	int sleep_time = 15;
	string tutorial_message = "説明をスキップする場合はエンターキーを押してください...\n\n\n【ルール説明】\n\n1階でアイテムを収集し、2階から8階までのタイピング＆クイズに挑戦します。\n\nまず1階でアイテムを収集します。\n初めに前方の3つの部屋から一つを選び、中にアイテムがあれば取得します。次にまた前方の3つの部屋から一つを選び、中にアイテムがあれば取得します。これを繰り返して5つの部屋を探索し終えると2階に上がります。\n\n2階からはタイピングとクイズに挑戦してもらいます。\n2階に到達すると10分の制限時間が開始し、画面上部にアルファベットの文が出現するので、その文をスペースなども含めてタイピングしてもらいます。\nタイピングミスをすると残り時間が5秒マイナスされます。\nタイピングを終えるとクイズの問題文と選択肢が現れ、アイテムを使用するか、解答するかを選択出来ます。\n答えが間違っていた場合、残り時間が20秒マイナスされます。\n答えが合っていた場合、次の階に進み、次のアルファベットの文が出現するので、再びタイピングをしてもらいます。これを8階まで繰り返します。クイズの問題は階を進むごとに難しくなります\n\n9階に到達した時点で制限時間のタイマーが停止し、残り時間が0でなければゲームクリアです。\n残り時間が0になったらゲームオーバーになります。\n\n\n\n";

	SetColor(COL_WHITE, COL_BLACK);
	for (auto itr = tutorial_message.begin(); itr != tutorial_message.end(); itr++) {

		Sleep(sleep_time);
		if (_kbhit())
		{
			input_key = _getch();
			if (input_key == KEY_ENTER) {
				sleep_time = 0;
			}
		}
		cout << *itr;
	}
	TextBox *tb = new TextBox({MESSAGE_BOX_X, MESSAGE_BOX_Y}, MESSAGE_BOX_WIDTH, MESSAGE_BOX_HEIGHT);
	tb->Print();
	SetCursorPosition(MESSAGE_X, MESSAGE_Y);
	cout << "次に進む[ENTER]";
	while ((input_key = _getch()) != KEY_ENTER)
	{
		Sleep(0);
	}
	delete tb;
	system("cls");
}

void PrintStartMenu()
{
	enum MyEnum
	{
		kStart,
		kRanking,
		kQuit,
		kStartMenuNum,
	};
	bool changed_flag = true;
	TextBox *continue_box = new TextBox({ START_MENU_BOX_X, START_MENU_BOX_Y }, START_MENU_BOX_WIDTH, START_MENU_BOX_HEIGHT);
	int now_select = 0;
	while (true)
	{
		if (changed_flag)
		{
			continue_box->Print();
			SetCursorPosition(51, 21);
			cout << "プレイ";
			SetCursorPosition(51, 22);
			cout << "ランキング";
			SetCursorPosition(51, 23);
			cout << "終了";
			SetCursorPosition(50, 21 + now_select);
			cout << ">";
			changed_flag = false;
		}
		if (_kbhit)
		{
			int c = _getch();
			if (c == KEY_ENTER)
			{
				if (now_select == kStart)
				{
					delete continue_box;
					system("cls");
					return;
				}
				else if (now_select == kRanking)
				{
					now_select = kStart;
					PrintRanking();
					changed_flag = true;
				}
				else if (now_select == kQuit)
				{
					exit(0);
				}
			}
			else if (c == 0x00 || c == KEY_ARROW)
			{
				c = _getch();
				if (c == KEY_UP)
				{
					now_select = (now_select + kStartMenuNum - 1) % kStartMenuNum;
					changed_flag = true;
				}
				else if (c == KEY_DOWN)
				{
					now_select = (now_select + 1) % kStartMenuNum;
					changed_flag = true;
				}
			}
		}
	}
}

void PrintResult()
{
	remaining_time = Timer::GetInstance().get_remaining_time();
	int time_score = remaining_time * 100;
	score = time_score;
	if (Player::GetInstance().get_no_item_flag())
	{
		score += 3000;
	}
	if (score >= 45000)
	{
		grade = "S";
	}
	else if (score >= 40000)
	{
		grade = "A";
	}
	else if (score >= 35000)
	{
		grade = "B";
	}
	else
	{
		grade = "C";
	}
	cout << "残り時間：" << remaining_time / 60 << "分" << remaining_time % 60 << "秒\t\t スコア + " << time_score << "\n";
	if (Player::GetInstance().get_no_item_flag())
	{
		cout << "アイテム未使用ボーナス\t\t スコア + 3000\n";
	}
	cout << "スコア：" << score << "\n";
	cout << "評価：" << grade << "\n\n";
	SetCursorPosition(MESSAGE_X, MESSAGE_Y);
	cout << "次に進む[ENTER]";
	while (_getch() != KEY_ENTER)
	{
		Sleep(0);
	}
	system("cls");
}

void CheckRanking()
{
	int ranking_count;
	Ranking ranking;
	vector<Ranking> ranking_array;
	ifstream ifs("csv/ranking.csv");


	if (!ifs) {
		return;
	}

	string str;

	while (getline(ifs, str)) {

		int data_count = 0;
		string token;
		istringstream stream(str);

		while (getline(stream, token, ','))
		{
			switch (data_count % 4)
			{
			case 0:
				ranking.player_name = token;
				break;
			case 1:
				ranking.score = stoi(token);
				break;
			case 2:
				ranking.time = token;
				break;
			case 3:
				ranking.grade = token;
				ranking_array.push_back(ranking);
				break;
			}
			data_count++;
		}
	}
	for (auto itr = ranking_array.begin(); itr != ranking_array.end(); itr++)
	{
		if (score > (*itr).score)
		{
			ranking_count = itr - ranking_array.begin() + 1;
			string input_name;
			bool name_checked_flag = false;
			while (!name_checked_flag)
			{
				SetCursorPosition(0, 0);
				cout << ranking_count << "位にランクインしました\n\n";
				cout << "名前を入力してください(半角文字は20文字，全角文字は10文字まで)\n";
				cout << ">";
				getline(cin, input_name);
				system("cls");
				if (input_name.empty() || input_name.size() == 0)
				{
					SetCursorPosition(0, 5);
					SetColor(COL_RED);
					cout << "名前が短過ぎます\n";
					input_name.clear();
					SetColor(COL_WHITE);
				}
				else if (input_name.size() > 20)
				{
					SetCursorPosition(0, 5);
					SetColor(COL_RED);
					cout << "名前が長過ぎます\n";
					input_name.clear();
					SetColor(COL_WHITE);
				}
				else {
					for (auto itr = input_name.begin(); itr != input_name.end(); itr++)
					{
						bool em = false;
						if (!(((itr != input_name.end() -1) && (em = (*itr == -127) && *(itr + 1) == 0x40)) || *itr == KEY_SPACE))
						{
							name_checked_flag = true;
							break;
						}
						else if ((em  && itr == (input_name.end() - 2)) || itr == (input_name.end() - 1))
						{
							SetCursorPosition(0, 5);
							SetColor(COL_RED);
							cout << "名前をスペースのみにすることはできません\n";
							input_name.clear();
							SetColor(COL_WHITE);
							break;
						}
						if (em)
						{
							itr++;
						}
					}
				}
			}
			ranking.player_name = input_name;
			ranking.score = score;
			ranking.time = to_string(remaining_time / 60) + "分" + to_string(remaining_time % 60) + "秒";
			ranking.grade = grade;
			ranking_array.insert(itr, ranking);
			
			ofstream ofs("csv/ranking.csv");
			for (int i = 0; i < 10; i++)
			{
				ofs << ranking_array[i].player_name << ","
					<< ranking_array[i].score << ","
					<< ranking_array[i].time << ","
					<< ranking_array[i].grade << endl;
			}
			break;
		}
	}
	system("cls");
	SetCursorPosition(0, 0);
	cout << "順位";
	SetCursorPosition(5, 0);
	cout << "名前";
	SetCursorPosition(30, 0);
	cout << "スコア";
	SetCursorPosition(40, 0);
	cout << "残り時間";
	SetCursorPosition(50, 0);
	cout << "評価";
	for (int i = 0; i < 10; i++)
	{
		if (i == ranking_count - 1)
		{
			SetColor(COL_GREEN);
		}
		SetCursorPosition(0, 2 + i);
		cout << i + 1;
		SetCursorPosition(5, 2 + i);
		cout << ranking_array[i].player_name;
		SetCursorPosition(30, 2 + i);
		cout << ranking_array[i].score;
		SetCursorPosition(40, 2 + i);
		cout << ranking_array[i].time;
		SetCursorPosition(50, 2 + i);
		cout << ranking_array[i].grade;
		SetColor(COL_WHITE);
	}
}

int main() // 全員
{
	while (true)
	{
		remaining_time = 0;
		score = 0;
		grade.clear();
		system("cls");	// 画面を消去
		SetBufferSize(120, 30); // スクリーンバッファのサイズを120×30に変更
		SetCursorDisplay(FALSE);	// カーソルの非表示化
		PrintTitle();
		PrintStartMenu();
		PrintTutorial(); // チュートリアルを表示する関数
		ItemFloor itf;	// 1Fのインスタンス化
		QuizFloor qf;	// 2F以降ののインスタンス化

		Player::GetInstance().Initialize();
		itf.ItemFloorMain();	// 1Fのゲーム進行を管理する関数
		Timer::GetInstance().Initialize();
		qf.QuizFloorMain();	// 2F以降のゲーム進行を管理する関数

		system("cls");
		if (Player::GetInstance().get_now_floor() == FLOOR_SIZE)	//プレイヤーが現在9階にいるか判定
		{
			cout << "GAME CLEAR";	// 9階であればGAME CLEAR
			SetCursorPosition(MESSAGE_X, MESSAGE_Y);
			cout << "次に進む[ENTER]";
			while (_getch() != KEY_ENTER)
			{
				Sleep(0);
			}
			system("cls");
			PrintResult();
			CheckRanking();
		}
		else
		{
			cout << "GAME OVER";	// 9階以外(未満)であればGAME OVER
		}

		SetCursorPosition(MESSAGE_X, MESSAGE_Y);
		cout << "タイトルに戻る[ENTER]";
		while (_getch() != KEY_ENTER)
		{
			Sleep(0);
		}
	}

	return 0;
}