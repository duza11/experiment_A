#include <fstream>
#include <iostream>
#include <sstream> //�����X�g���[��
#include "item_floor.h"
#include "quiz_floor.h"
#include "timer.h"
#include "player.h"
#include "console_util.h"

// "main.cpp"�ȊO�̊֐��S���҂̓w�b�_�[�t�@�C���̊֐���`�̉��ɋL�q
// �^�C�s���O�ƃN�C�Y�̖���CSV�t�@�C������ǂݍ��ނ���
// ��o�p�̃t�@�C���Ŏ��s����ƃG���[���������邩������܂���

/*�d�l�̕ύX�_*/
// �ȒP�ȃN�C�Y�̒ǉ�
// �^�C�s���O�~�X�ł̃y�i���e�B��1�b��5�b�ɕύX
// �N�C�Y�~�X�ł̃y�i���e�B��30�b��20�b�ɕύX

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


void PrintTutorial() // ���J���C
{
	int input_key;
	int sleep_time = 15;
	string tutorial_message = "�������X�L�b�v����ꍇ�̓G���^�[�L�[�������Ă�������...\n\n\n�y���[�������z\n\n1�K�ŃA�C�e�������W���A2�K����8�K�܂ł̃^�C�s���O���N�C�Y�ɒ��킵�܂��B\n\n�܂�1�K�ŃA�C�e�������W���܂��B\n���߂�3�̔�������I�сA���ɃA�C�e��������Ύ擾���܂��B���ɂ܂�3�̔�������I�сA���ɃA�C�e��������Ύ擾���܂��B������J��Ԃ���5�̕�����T�����I�����2�K�ɏオ��܂��B\n\n2�K����̓^�C�s���O�ƃN�C�Y�ɒ��킵�Ă��炢�܂��B\n2�K�ɓ��B�����10���̐������Ԃ��J�n���A��ʏ㕔�ɃA���t�@�x�b�g�̕����o������̂ŁA���̕����X�y�[�X�Ȃǂ��܂߂ă^�C�s���O���Ă��炢�܂��B\n�^�C�s���O�~�X������Ɛ������Ԃ�5�b�}�C�i�X����܂��B\n�^�C�s���O���I����ƃN�C�Y�̖�蕶�ƑI����������A�A�C�e�����g�p���邩�A�𓚂��邩��I���o���܂��B\n�������Ԉ���Ă����ꍇ�A�������Ԃ�20�b�}�C�i�X����܂��B\n�����������Ă����ꍇ�A���̊K�ɐi�݁A���̃A���t�@�x�b�g�̕����o������̂ŁA�^�C�s���O�����Ă��炢�܂��B�����8�K�܂ŌJ��Ԃ��܂��B�N�C�Y�̖��͊K��i�ނ��Ƃɓ���Ȃ�܂�\n\n9�K�ɓ��B�������_�Ń^�C�}�[����~���A���Ԃ��c���Ă�����Q�[���N���A�ł��B\n�^�C�}�[��0�ɂȂ�����Q�[���I�[�o�[�ɂȂ�܂��B\n\n\n\n";

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
	cout << "���ɐi��[ENTER]";
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
			cout << "�v���C����";
			SetCursorPosition(51, 22);
			cout << "�I������";
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
	cout << "�c�莞�ԁF" << Timer::GetInstance().get_remaining_time() / 60 << "��" << Timer::GetInstance().get_remaining_time() % 60 << "�b\t"
		<< "�X�R�A�F" << Timer::GetInstance().get_remaining_time() * 100;
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
			cout << "\n���O����͂��Ă�������:";
			cin >> input_name;
			ranking.player_name = input_name;
			ranking.score = Timer::GetInstance().get_remaining_time();
			ranking.time = to_string(Timer::GetInstance().get_remaining_time() / 60) + "�F" + to_string(Timer::GetInstance().get_remaining_time() % 60);
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

int main() // �S��
{
	while (true)
	{
		system("cls");	// ��ʂ�����
		SetBufferSize(120, 30); // �X�N���[���o�b�t�@�̃T�C�Y��120�~30�ɕύX
		SetCursorDisplay(FALSE);	// �J�[�\���̔�\����
		PrintTitle();
		if (!CheckContinue())
		{
			break;
		}
		PrintTutorial(); // �`���[�g���A����\������֐�
		ItemFloor itf;	// 1F�̃C���X�^���X��
		QuizFloor qf;	// 2F�ȍ~�̂̃C���X�^���X��

		Player::GetInstance().Initialize();
		itf.ItemFloorMain();	// 1F�̃Q�[���i�s���Ǘ�����֐�
		Timer::GetInstance().Initialize();
		qf.QuizFloorMain();	// 2F�ȍ~�̃Q�[���i�s���Ǘ�����֐�

		system("cls");
		if (Player::GetInstance().get_now_floor() == 9)	//�v���C���[������9�K�ɂ��邩����
		{
			cout << "GAME CLEAR";	// 9�K�ł����GAME CLEAR
		}
		else
		{
			cout << "GAME OVER";	// 9�K�ȊO(����)�ł����GAME OVER
		}
		PrintRanking();

		SetCursorPosition(MESSAGE_X, MESSAGE_Y);
		cout << "�^�C�g���ɖ߂�[ENTER]";
		while (_getch() != KEY_ENTER)
		{
			Sleep(0);
		}
	}

	return 0;
}