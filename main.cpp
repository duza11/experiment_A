#include "item_floor.h"
#include "quiz_floor.h"
#include "timer.h"
#include "player.h"

void PrintTutorial()
{
	int input_key;
	int sleep_time = 15;
	string tutorial_message = "�������X�L�b�v����ꍇ�̓G���^�[�L�[�������Ă�������...\n\n�y���[�������z\n\n1�K�ŃA�C�e�����W�����A2�K����8�K�܂ł̃^�C�s���O���N�C�Y�ɒ��킵�܂��B\n�܂�1�K�ŃA�C�e�������W���܂��B\n���߂�3�̔�������I�сA���ɃA�C�e��������Ύ擾���܂��B���ɂ܂�3�̔�������I�сA���ɃA�C�e��������Ύ擾���܂��B������J��Ԃ��Ă䂫5�̕�����T�����I�����2�K�ɏオ��܂��B\n�A�C�e����2��ނ���hT �h�͎��Ԃ��~�߂邱�Ƃ��ł��A�h1/2 �h�͓����̑I�����𔼕��ɂ��邱�Ƃ��ł��܂��B\n2�K����̓^�C�s���O�ƃN�C�Y�ɒ��킵�Ă��炢�܂��B\n2�K�ɓ��B����Ǝ��Ԑ����̃^�C�}�[�ƁA��ʏ㕔�ɃA���t�@�x�b�g�̕����o������̂ŁA���̕����X�y�[�X�Ȃǂ��܂߂ă^�C�s���O���Ă��炢�܂��B\n�^�C�s���O�~�X�������1�b�}�C�i�X����܂��B\n�^�C�s���O���I����ƕ��̉��ɑI����������A�X�ɃA�C�e�����g�p���邩�A�𓚂��邩��I���o���܂��B\n�A�C�e�����g�p����ꍇ�A�ǂ̃A�C�e�����g�p���邩�I�����A�G���^�[�L�[�������܂��B\n�𓚂���ꍇ�A�������Ǝv���𓚂̃A���t�@�x�b�g����͂��G���^�[�L�[�������܂��B\n�������Ԉ���Ă����ꍇ�A30�b�}�C�i�X����A�A�C�e�����g�p���邩�A�𓚂��邩�̑I���ɖ߂�܂��B\n�����������Ă����ꍇ�A���̊K�ɐi�݁A���̃A���t�@�x�b�g�̕����o������̂ŁA�^�C�s���O�����Ă��炢�܂��B�����8�K�܂ŌJ��Ԃ��܂��B\n9�K�ɓ��B�������_�Ń^�C�}�[����~���A���Ԃ��c���Ă�����Q�[���N���A�ł��B\n�^�C�}�[��0�ɂȂ�����Q�[���I�[�o�[�ɂȂ�܂��B\n\n\n";

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

int main()
{
	system("cls");	// ��ʂ�����
	SetBufferSize(120, 30);
	SetCursorDisplay(FALSE);	// �J�[�\���̔�\����
	PrintTutorial();
	ItemFloor itf;	// 1F�̃C���X�^���X��
	QuizFloor qf;	// 2F�ȍ~�̂̃C���X�^���X��

	itf.ItemFloorMain();	// 1F�̃Q�[���i�s���Ǘ�����֐�
	Timer::GetInstance();	// �^�C�}�[�̏�����
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

	_getch();	// ���͑҂�

	return 0;
}