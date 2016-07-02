#include "game_manager.h"

GameManager::GameManager()
{
	remaining_time_ = 0;
	score_ = 0;
	grade_.clear();
}

void GameManager::PrintRanking()
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
	cout << "����";
	SetCursorPosition(RANKING_CONTENT_X + 5, RANKING_CONTENT_Y);
	cout << "���O";
	SetCursorPosition(RANKING_CONTENT_X + 30, RANKING_CONTENT_Y);
	cout << "�X�R�A";
	SetCursorPosition(RANKING_CONTENT_X + 40, RANKING_CONTENT_Y);
	cout << "�c�莞��";
	SetCursorPosition(RANKING_CONTENT_X + 50, RANKING_CONTENT_Y);
	cout << "�]��";
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
	cout << "�߂�[BACKSPACE]";
	while (_getch() != KEY_BACK)
	{
		Sleep(0);
	}
	tb->Finitialize();
	delete tb;
}

void GameManager::PrintTitle()
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

void GameManager::PrintResult()
{
	remaining_time_ = Timer::GetInstance().get_remaining_time();
	int time_score = remaining_time_ * 100;
	int typing_score = Player::GetInstance().get_typing_counter() * 50;
	score_ = time_score + typing_score;
	if (Player::GetInstance().get_no_item_flag())
	{
		score_ += 3000;
	}
	if (score_ >= 65000)
	{
		grade_ = "S";
	}
	else if (score_ >= 57000)
	{
		grade_ = "A";
	}
	else if (score_ >= 49000)
	{
		grade_ = "B";
	}
	else
	{
		grade_ = "C";
	}
	cout << "�c�莞�ԁF" << remaining_time_ / 60 << "��" << remaining_time_ % 60 << "�b\t\t�X�R�A + " << time_score << "\n";
	cout << "�^�C�s���O�{�[�i�X\t\t�X�R�A + " << typing_score << "\n";
	if (Player::GetInstance().get_no_item_flag())
	{
		cout << "�A�C�e�����g�p�{�[�i�X\t\t�X�R�A + 3000\n";
	}
	cout << "\n�X�R�A�F" << score_ << "\n";
	cout << "�]���F" << grade_ << "\n\n";
	SetCursorPosition(MESSAGE_X, MESSAGE_Y);
	cout << "���ɐi��[ENTER]";
	while (_getch() != KEY_ENTER)
	{
		Sleep(0);
	}
	system("cls");
}

void GameManager::PrintStartMenu()
{
	enum MyEnum
	{
		kStart,
		KTutorial,
		kRanking,
		kQuit,

		kStartMenuNum,
	};
	bool selected_flag = false;
	bool changed_flag = true;
	TextBox *continue_box = new TextBox({ START_MENU_BOX_X, START_MENU_BOX_Y }, START_MENU_BOX_WIDTH, START_MENU_BOX_HEIGHT);
	int now_select = 0;
	while (!selected_flag)
	{
		if (changed_flag)
		{
			continue_box->Print();
			SetCursorPosition(51, 21);
			cout << "�v���C";
			SetCursorPosition(51, 22);
			cout << "���K";
			SetCursorPosition(51, 23);
			cout << "�����L���O";
			SetCursorPosition(51, 24);
			cout << "�I��";
			SetCursorPosition(50, 21 + now_select);
			cout << ">";
			changed_flag = false;
		}
		if (_kbhit())
		{
			int c = _getch();
			if (c == KEY_ENTER)
			{
				delete continue_box;
				selected_flag = true;
				if (now_select == kStart)
				{
					StartGame();
				}
				else if (now_select == KTutorial)
				{
					StartTutorial();
				}
				else if (now_select == kRanking)
				{
					PrintRanking();
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

void GameManager::PrintExplain()
{
	int input_key;
	int sleep_time = 15;
	string tutorial_message = "�������X�L�b�v����ꍇ�̓G���^�[�L�[�������Ă�������...\n\n\n"
		"�y���[�������z\n\n1�K�ŃA�C�e�������W���A2�K����8�K�܂ł̃^�C�s���O���N�C�Y�ɒ��킵�܂��B\n\n"
		"�܂�1�K�ŃA�C�e�������W���܂��B\n���߂ɑO����3�̕���������I�сA���ɃA�C�e��������Ύ擾���܂��B"
		"���ɂ܂��O����3�̕���������I�сA���ɃA�C�e��������Ύ擾���܂��B"
		"������J��Ԃ���5�̕�����T�����I�����2�K�ɏオ��܂��B\n\n"
		"2�K����̓^�C�s���O�ƃN�C�Y�ɒ��킵�Ă��炢�܂��B\n2�K�ɓ��B�����10���̐������Ԃ��J�n���A"
		"��ʏ㕔�ɃA���t�@�x�b�g�̕����o������̂ŁA���̕����X�y�[�X�Ȃǂ��܂߂ă^�C�s���O���Ă��炢�܂��B\n"
		"�A���t�@�x�b�g�͏����������g�p���Ă��܂���̂Łul�v�͑S�ď������́uL�v�ł��B\n"
		"�^�C�s���O�~�X������Ǝc�莞�Ԃ�5�b�}�C�i�X����܂��B\n�^�C�s���O���I����ƃN�C�Y�̖�蕶�ƑI����������A"
		"�A�C�e�����g�p���邩�A�𓚂��邩��I���o���܂��B\n�������Ԉ���Ă����ꍇ�A�c�莞�Ԃ�20�b�}�C�i�X����܂��B\n"
		"�����������Ă����ꍇ�A���̊K�ɐi�݁A���̃A���t�@�x�b�g�̕����o������̂ŁA�Ăу^�C�s���O�����Ă��炢�܂��B"
		"�����8�K�܂ŌJ��Ԃ��܂��B�N�C�Y�̖��͊K��i�ނ��Ƃɓ���Ȃ�܂��B\n\n"
		"9�K�ɓ��B�������_�Ő������Ԃ̃^�C�}�[����~���A�c�莞�Ԃ�0�łȂ���΃Q�[���N���A�ł��B\n"
		"�c�莞�Ԃ�0�ɂȂ�����Q�[���I�[�o�[�ɂȂ�܂��B\n\n\n\n";;

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
	TextBox *tb = new TextBox({ MESSAGE_BOX_X, MESSAGE_BOX_Y }, MESSAGE_BOX_WIDTH, MESSAGE_BOX_HEIGHT);
	tb->Print();
	SetCursorPosition(MESSAGE_X, MESSAGE_Y);
	cout << "���ɐi��[ENTER]";
	while ((input_key = _getch()) != KEY_ENTER)
	{
		Sleep(0);
	}
	delete tb;
	system("cls");
}

void GameManager::CheckRanking()
{
	int ranking_count = -1;
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
		if (score_ > (*itr).score)
		{
			ranking_count = itr - ranking_array.begin() + 1;
			string input_name;
			bool name_checked_flag = false;
			while (!name_checked_flag)
			{
				SetCursorPosition(0, 0);
				cout << ranking_count << "�ʂɃ����N�C�����܂���\n\n";
				cout << "���O����͂��Ă�������(���p������20�����C�S�p������10�����܂�)\n";
				cout << ">";
				getline(cin, input_name);
				system("cls");
				if (input_name.empty() || input_name.size() == 0)
				{
					SetCursorPosition(0, 5);
					SetColor(COL_RED);
					cout << "���O���Z�߂��܂�\n";
					input_name.clear();
					SetColor(COL_WHITE);
				}
				else if (input_name.size() > 20)
				{
					SetCursorPosition(0, 5);
					SetColor(COL_RED);
					cout << "���O�����߂��܂�\n";
					input_name.clear();
					SetColor(COL_WHITE);
				}
				else {
					for (auto itr = input_name.begin(); itr != input_name.end(); itr++)
					{
						bool em = false;
						if (!(((itr != input_name.end() - 1) && (em = (*itr == -127) && *(itr + 1) == 0x40)) || *itr == KEY_SPACE))
						{
							name_checked_flag = true;
							break;
						}
						else if ((em  && itr == (input_name.end() - 2)) || itr == (input_name.end() - 1))
						{
							SetCursorPosition(0, 5);
							SetColor(COL_RED);
							cout << "���O���X�y�[�X�݂̂ɂ��邱�Ƃ͂ł��܂���\n";
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
			ranking.score = score_;
			ranking.time = to_string(remaining_time_ / 60) + "��" + to_string(remaining_time_ % 60) + "�b";
			ranking.grade = grade_;
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
	cout << "����";
	SetCursorPosition(5, 0);
	cout << "���O";
	SetCursorPosition(30, 0);
	cout << "�X�R�A";
	SetCursorPosition(40, 0);
	cout << "�c�莞��";
	SetCursorPosition(50, 0);
	cout << "�]��";
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

void GameManager::StartGame()
{
	system("cls");
	ItemFloor itf;
	itf.ItemFloorMain();
	QuizFloor qf;
	qf.QuizFloorMain();

	system("cls");
	if (Player::GetInstance().get_now_floor() == FLOOR_SIZE)	//�v���C���[������9�K�ɂ��邩����
	{
		cout << "GAME CLEAR";	// 9�K�ł����GAME CLEAR
		SetCursorPosition(MESSAGE_X, MESSAGE_Y);
		cout << "���ɐi��[ENTER]";
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
		cout << "GAME OVER";	// 9�K�ȊO(����)�ł����GAME OVER
	}

	SetCursorPosition(MESSAGE_X, MESSAGE_Y);
	cout << "�^�C�g���ɖ߂�[ENTER]";
	while (_getch() != KEY_ENTER)
	{
		Sleep(0);
	}
}

void GameManager::StartTutorial()
{
	system("cls");
	TutorialItemFloor titf;
	titf.ItemFloorMain();
	TutorialQuizFloor tqf;
	tqf.QuizFloorMain();
	SetCursorPosition(MESSAGE_X, MESSAGE_Y);
	cout << "�^�C�g���ɖ߂�[ENTER]";
	while (_getch() != KEY_ENTER)
	{
		Sleep(0);
	}
}
