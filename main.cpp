#include "console_util.h"
#include "game_manager.h"

// "main.cpp"�ȊO�̊֐��S���҂̓w�b�_�[�t�@�C���̊֐���`�̉��ɋL�q
// �^�C�s���O�ƃN�C�Y�̖���CSV�t�@�C������ǂݍ��ނ���
// ��o�p�̃t�@�C���Ŏ��s����ƃG���[���������邩������܂���

int main() // �S��
{
	SetBufferSize(120, 30); // �X�N���[���o�b�t�@�̃T�C�Y��120�~30�ɕύX
	SetCursorDisplay(FALSE);	// �J�[�\���̔�\����
	while (true)
	{
		system("cls");	// ��ʂ�����
		
		GameManager gm;

		gm.PrintTitle();
		gm.PrintStartMenu();
	}

	return 0;
}