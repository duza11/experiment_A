#include "item_floor.h"
#include "quiz_floor.h"
#include "timer.h"
#include "player.h"

void PrintTutorial()
{
	int input_key;
	int sleep_time = 15;
	string tutorial_message = "説明をスキップする場合はエンターキーを押してください...\n\n【ルール説明】\n\n1階でアイテム収集をし、2階から8階までのタイピング＆クイズに挑戦します。\nまず1階でアイテムを収集します。\n初めに3つの扉から一つを選び、中にアイテムがあれば取得します。次にまた3つの扉から一つを選び、中にアイテムがあれば取得します。これを繰り返してゆき5つの部屋を探索し終えると2階に上がります。\nアイテムは2種類あり”T ”は時間を止めることができ、”1/2 ”は答えの選択肢を半分にすることができます。\n2階からはタイピングとクイズに挑戦してもらいます。\n2階に到達すると時間制限のタイマーと、画面上部にアルファベットの文が出現するので、その文をスペースなども含めてタイピングしてもらいます。\nタイピングミスをすると1秒マイナスされます。\nタイピングを終えると文の下に選択肢が現れ、更にアイテムを使用するか、解答するかを選択出来ます。\nアイテムを使用する場合、どのアイテムを使用するか選択し、エンターキーを押します。\n解答する場合、正解だと思う解答のアルファベットを入力しエンターキーを押します。\n答えが間違っていた場合、30秒マイナスされ、アイテムを使用するか、解答するかの選択に戻ります。\n答えが合っていた場合、次の階に進み、次のアルファベットの文が出現するので、タイピングをしてもらいます。これを8階まで繰り返します。\n9階に到達した時点でタイマーが停止し、時間が残っていたらゲームクリアです。\nタイマーが0になったらゲームオーバーになります。\n\n\n";

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

int main()
{
	system("cls");	// 画面を消去
	SetBufferSize(120, 30);
	SetCursorDisplay(FALSE);	// カーソルの非表示化
	PrintTutorial();
	ItemFloor itf;	// 1Fのインスタンス化
	QuizFloor qf;	// 2F以降ののインスタンス化

	itf.ItemFloorMain();	// 1Fのゲーム進行を管理する関数
	Timer::GetInstance();	// タイマーの初期化
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

	_getch();	// 入力待ち

	return 0;
}