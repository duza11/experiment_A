#include "tutorial_item_floor.h"

TutorialItemFloor::TutorialItemFloor() : ItemFloor::ItemFloor()
{
}

void TutorialItemFloor::Print()
{
	SetCursorPosition(0, 0);
	for (int y = 0; y < ITEM_FLOOR_HEIGHT; y++) // PrintLine�𗘗p���ă_���W�������o��
	{
		PrintLine(y, false);
		PrintLine(y, true);
		PrintLine(y, false);
	}
	SetColor(COL_WHITE, COL_BLACK); // �����F��,�w�i�F�����ɐݒ�
	SetCursorPosition(70, 5);
	cout << "�ړ��F[��][��]";
	SetCursorPosition(70, 6);
	cout << "����F[ENTER]";
	Player::GetInstance().PrintItemStatus(item_position_); // ���L�A�C�e�����o��
	SetCursorPosition(70, 11);
	SetColor(COL_WHITE, COL_DARK_GREEN);
	cout << "P";
	SetColor(COL_WHITE, COL_BLACK);
	cout << "�F�v���C���[�̈ʒu";
	SetCursorPosition(70, 12);
	SetColor(COL_WHITE, COL_DARK_YELLOW);
	cout << "N";
	SetColor(COL_WHITE, COL_BLACK);
	cout << "�F�v���C���[�̈ړ���";
	SetCursorPosition(70, 13);
	SetColor(COL_WHITE, COL_DARK_BLUE);
	cout << " ";
	SetColor(COL_WHITE, COL_BLACK);
	cout << "�F�X�^�[�g�n�_";
	SetCursorPosition(70, 14);
	SetColor(COL_WHITE, COL_DARK_RED);
	cout << " ";
	SetColor(COL_WHITE, COL_BLACK);
	cout << "�F�S�[���n�_";
	SetCursorPosition(70, 15);
	SetColor(COL_WHITE, COL_LIGHT_GRAY);
	cout << " ";
	SetColor(COL_WHITE, COL_BLACK);
	cout << "�F����";
	SetCursorPosition(MESSAGE_X, MESSAGE_Y);
	cout << message_;
	SetCursorPosition(0, 0);
}
