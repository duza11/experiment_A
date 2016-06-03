#pragma once

#include <string>
#include <random>
#include "common.h"
#include "console_util.h"
#include "timer.h"

using namespace std;

//�A�C�e���p�̗񋓌^
typedef enum
{
	kFiftyFifty,
	kStopTimer,

	kItemKind,
} ItemNum;

class Player
{
public:
	// �v���C���[�̃C���X�^���X�̎擾
	static Player &GetInstance();
	//�v���C���[�̌��݈ʒu���擾
	pair<int, int> get_now_position();
	//�v���C���[�̈ړ���ʒu���擾
	pair<int, int> get_next_position();
	//�v���C���[�̈ړ�����W�����Ɉړ�
	void MoveNextPositionLeft();
	//�v���C���[�̈ړ�����W���E�Ɉړ�
	void MoveNextPositionRight();
	//�v���C���[�̍��W���ړ�
	void MovePositionFront();
	//�A�C�e���̊l��
	void GetItem(int item_num);
	//�A�C�e���̎g�p
	void UseItem(int item_num, Quiz &quiz);
	//�K������
	void GoUpstairs();
	//���݂̊K���擾
	int get_now_floor();
	//���݂̊K��\��
	void PrintNowFloor();
	//�A�C�e�����g�p�\�ɂ���
	void EnableItem();
	//�A�C�e���̏�������\��
	void PrintItemStatus(pair<int, int> position);

private:
	//�v���C���[���̏�����
	Player();
	Player(const Player &Player) {}
	~Player() {}
	//�񓚂𔼕��ɂ���A�C�e���̎g�p
	void UseFiftyFity(Quiz &quiz);
	//���Ԃ��~�߂�A�C�e���̎g�p
	void UseStopTimer();

	//�A�C�e���p�\����
	typedef struct
	{
		string item_name;
		int item_count;
		bool enable_flag;
	} Item;

	random_device rnd; //���������N���X
	pair<int, int> now_position_; //���ݍ��W
	pair<int, int> next_position_; //�ړ�����W
	int now_floor_; //���݂̊K
	Item item_[kItemKind]; //�A�C�e���\����
};