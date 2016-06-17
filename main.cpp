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

/*仕様の変更点*/
// 簡単なクイズの追加
// タイピングミスでのペナルティを1秒→5秒に変更
// クイズミスでのペナルティを30秒→20秒に変更

void PrintTitle()
{
	char title[6][10][20] = {
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
			SetCursorPosition(s * 20, y);
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
	string tutorial_message = "説明をスキップする場合はエンターキーを押してください...\n\n\n【ルール説明】\n\n1階でアイテムを収集し、2階から8階までのタイピング＆クイズに挑戦します。\n\nまず1階でアイテムを収集します。\n初めに3つの扉から一つを選び、中にアイテムがあれば取得します。次にまた3つの扉から一つを選び、中にアイテムがあれば取得します。これを繰り返して5つの部屋を探索し終えると2階に上がります。\n\n2階からはタイピングとクイズに挑戦してもらいます。\n2階に到達すると10分の制限時間が開始し、画面上部にアルファベットの文が出現するので、その文をスペースなども含めてタイピングしてもらいます。\nタイピングミスをすると制限時間が5秒マイナスされます。\nタイピングを終えるとクイズの問題文と選択肢が現れ、アイテムを使用するか、解答するかを選択出来ます。\n答えが間違っていた場合、制限時間が20秒マイナスされます。\n答えが合っていた場合、次の階に進み、次のアルファベットの文が出現するので、タイピングをしてもらいます。これを8階まで繰り返します。クイズの問題は階を進むごとに難しくなります\n\n9階に到達した時点でタイマーが停止し、時間が残っていたらゲームクリアです。\nタイマーが0になったらゲームオーバーになります。\n\n\n\n";

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
	cout << "次に進む[ENTER]";
	while ((input_key = _getch()) != KEY_ENTER)
	{
		Sleep(0);
	}
	system("cls");
}

bool CheckContinue()
{
	pair<int, int> continue_position = { 48, 20 };
	bool changed_flag = true;
	TextBox *continue_box = new TextBox(continue_position, 24, 4);
	int now_select = 0;
	while (true)
	{
		if (changed_flag)
		{
			continue_box->Print();
			SetCursorPosition(51, 21);
			cout << "プレイする";
			SetCursorPosition(51, 22);
			cout << "終了する";
			SetCursorPosition(50, 21 + now_select);
			cout << ">";
			changed_flag = false;
		}
		if (_kbhit)
		{
			int c = _getch();
			if (c == KEY_ENTER)
			{
				system("cls");
				if (now_select)
				{
					return false;
				}
				return true;
			}
			else if (c == 0x00 || c == 0xe0)
			{
				c = _getch();
				if (c == KEY_UP || c == KEY_DOWN)
				{
					now_select = !now_select;
					changed_flag = true;
				}
			}
		}
	}
}

void PrintResult()
{
	cout << "残り時間：" << Timer::GetInstance().get_remaining_time() / 60 << "分" << Timer::GetInstance().get_remaining_time() % 60 << "秒\t"
		<< "スコア：" << Timer::GetInstance().get_remaining_time() * 100;
}

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
	for (auto itr = ranking_array.begin(); itr != ranking_array.end(); itr++)
	{
		if (Timer::GetInstance().get_remaining_time() > (*itr).score)
		{
			string input_name;
			cout << "\n名前を入力してください:";
			cin >> input_name;
			ranking.player_name = input_name;
			ranking.score = Timer::GetInstance().get_remaining_time();
			ranking.time = to_string(Timer::GetInstance().get_remaining_time() / 60) + "：" + to_string(Timer::GetInstance().get_remaining_time() % 60);
			ranking.grade = "S";
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
	for (auto itr = ranking_array.begin(); itr != ranking_array.end() - 1; itr++)
	{
		cout << (*itr).player_name << "\t"
			<< (*itr).score << "\t"
			<< (*itr).time << "\t"
			<< (*itr).grade << "\n";
	}
}

int main() // 全員
{
	while (true)
	{
		system("cls");	// 画面を消去
		SetBufferSize(120, 30); // スクリーンバッファのサイズを120×30に変更
		SetCursorDisplay(FALSE);	// カーソルの非表示化
		PrintTitle();
		if (!CheckContinue())
		{
			break;
		}
		PrintTutorial(); // チュートリアルを表示する関数
		ItemFloor itf;	// 1Fのインスタンス化
		QuizFloor qf;	// 2F以降ののインスタンス化

		Player::GetInstance().Initialize();
		itf.ItemFloorMain();	// 1Fのゲーム進行を管理する関数
		Timer::GetInstance().Initialize();
		qf.QuizFloorMain();	// 2F以降のゲーム進行を管理する関数

		system("cls");
		if (Player::GetInstance().get_now_floor() == 9)	//プレイヤーが現在9階にいるか判定
		{
			cout << "GAME CLEAR";	// 9階であればGAME CLEAR
		}
		else
		{
			cout << "GAME OVER";	// 9階以外(未満)であればGAME OVER
		}
		PrintRanking();

		SetCursorPosition(MESSAGE_X, MESSAGE_Y);
		cout << "タイトルに戻る[ENTER]";
		while (_getch() != KEY_ENTER)
		{
			Sleep(0);
		}
	}

	return 0;
}