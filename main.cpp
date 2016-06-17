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
	char title[10][20] = {
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
	};

	for (int y = 0; y < sizeof(title) / sizeof(title[0]); y++)
	{
		for (int x = 0; x < sizeof(title[0]) / sizeof(char); x++)
		{
			if (title[y][x])
			{
				SetColor(COL_WHITE, COL_YELLOW);
			}
			else
			{
				SetColor(COL_WHITE, COL_BLACK);
			}
			cout << " ";
		}
		cout << "\n";
	}
	_getch();
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
	pair<int, int> continue_position = { 48, 13 };
	bool changed_flag = true;
	TextBox *continue_box = new TextBox(continue_position, 24, 5);
	int now_select = 0;
	while (true)
	{
		if (changed_flag)
		{
			continue_box->Print();
			SetCursorPosition(51, 14);
			cout << "���g���C���܂���?";
			SetCursorPosition(51, 16);
			cout << " �͂�      ������";
			SetCursorPosition(51 + now_select, 16);
			cout << ">";
			changed_flag = false;
		}
		if (_kbhit)
		{
			int c = _getch();
			if (c == KEY_ENTER)
			{
				if (now_select)
				{
					return false;
				}
				return true;
			}
			else if (c == 0x00 || c == 0xe0)
			{
				c = _getch();
				if (c == KEY_RIGHT)
				{
					now_select = (!now_select) * 10;
					changed_flag = true;
				}
				else if (c == KEY_LEFT)
				{
					now_select = (!now_select) * 10;
					changed_flag = true;
				}
			}
		}
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

		SetCursorPosition(MESSAGE_X, MESSAGE_Y);
		cout << "���ɐi��[ENTER]";
		while (_getch() != KEY_ENTER)
		{
			Sleep(0);
		}
		if (!CheckContinue())
		{
			break;
		}
	}

	return 0;
}