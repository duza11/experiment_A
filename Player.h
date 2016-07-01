#pragma once

#include <string>
#include <random>
#include "common.h"
#include "console_util.h"
#include "timer.h"
#include "quiz_floor.h"

using namespace std;

class Player
{
public:
	// �v���C���[�̃C���X�^���X�̎擾
	static Player &GetInstance(); // �������
	void Initialize();
	//�v���C���[�̌��݈ʒu���擾
	pair<int, int> get_now_position(); // �������
	//�v���C���[�̈ړ���ʒu���擾
	pair<int, int> get_next_position(); // �������
	//�v���C���[�̈ړ�����W�����Ɉړ�
	void MoveNextPositionLeft(); // �������
	//�v���C���[�̈ړ�����W���E�Ɉړ�
	void MoveNextPositionRight(); // �������
	//�v���C���[�̍��W���ړ�
	void MovePositionFront(); // �������
	//�A�C�e���̊l��
	string GetItem(int item_num); // �������
	//�A�C�e���̎g�p
	void UseItem(int item_num, Quiz &quiz, IQuizFloor *iqf); // �������
	//�K������
	void GoUpstairs(); // �������
	//���݂̊K���擾
	int get_now_floor(); // �������
	//���݂̊K��\��
	void PrintNowFloor(); // �������
	//�A�C�e�����g�p�\�ɂ���
	void EnableItem(); // �������
	//�A�C�e���̏�������\��
	void PrintItemStatus(pair<int, int> position); // �������
	//�A�C�e���̐�����\��
	void PrintItemExplain(int item_num, pair<int, int> position); // �������
	//�A�C�e�����g�p�t���O���擾
	bool get_no_item_flag();

	void AddTypingCounter();

	int get_typing_counter();

private:
	//�v���C���[���̏�����
	Player(); // �������
	Player(const Player &Player) {} // �������
	~Player() {} // �������
	//�񓚂𔼕��ɂ���A�C�e���̎g�p
	void UseFiftyFity(Quiz &quiz, IQuizFloor *iqf); // �������
	//���Ԃ��~�߂�A�C�e���̎g�p
	void UseStopTimer(); // �������

	//�A�C�e���p�\����
	typedef struct
	{
		string item_name;
		int item_count;
		bool enable_flag;
		vector<string> item_explain;
	} Item;

	random_device rnd; //���������N���X
	pair<int, int> now_position_; //���ݍ��W
	pair<int, int> next_position_; //�ړ�����W
	int now_floor_; //���݂̊K
	Item item_[kItemKind]; //�A�C�e���\����
	bool no_item_flag_;
	int typing_counter_;
};