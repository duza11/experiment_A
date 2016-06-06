#include "item_floor.h"

ItemFloor::ItemFloor()
{
	// 1F���̕����̏�����
	for (int y = 0; y < ITEM_FLOOR_HEIGT; y++) {
		for (int x = 0; x < ITEM_FLOOR_WIDTH; x++) {
			if (y == 0 || y == ITEM_FLOOR_HEIGT - 1)
			{
				room_[x][y] = { 0, -1, true };	// y = ITEM_FLOOR_HEIGHT(�X�^�[�g�ʒu),y = 0(�S�[���ʒu)�ł̓A�C�e���Ȃ�,�A�C�e�������t���O��true�ɂ���
			}
			else
			{
				room_[x][y] = { 0, (x - 1), false }; // ����ȊO�̕�����2��ނ̃A�C�e�����A�C�e���Ȃ��Ƃ���,�A�C�e�������p�t���O��false�ɂ���
			}
		}
		for (int x = 0; x < ITEM_FLOOR_WIDTH; x++) // �A�C�e���̔z�u�������_���ɂ���
		{
			int ran_num = (unsigned)rnd() % ITEM_FLOOR_WIDTH;
			int temp = room_[x][y].item_status;
			room_[x][y].item_status = room_[ran_num][y].item_status;
			room_[ran_num][y].item_status = temp;
		}
	}

	this->goal_flag_ = false; // �S�[������t���O��false�ɂ���
	item_position_ = { 60, 8 }; // �A�C�e�����`����W��(60, 8)�ɂ���
	this->changed_flag_ = true; // ��ʍX�V����t���O��true�ɂ���
}

ItemFloor::~ItemFloor()
{
}

int ItemFloor::ItemFloorMain() // 1F�̃Q�[���i�s���Ǘ�����֐�
{
	while (!this->goal_flag_) // �S�[������t���O��false�ł������J��Ԃ�
	{
		if (changed_flag_) // ��ʍX�V����t���O��true�ł����1F�̏��̍X�V,�`����s��
		{
			Update(Player::GetInstance().get_now_position(), Player::GetInstance().get_next_position()); // 1F�̏��̍X�V
			Print(); // 1F�̕`��
			changed_flag_ = false; // ��ʍX�V����t���O��false�ɂ���
		}if (_kbhit()) // �L�[���͂����邩����
		{
			int input_key = _getch(); // �L�[���͂��󂯎��
			if (input_key == KEY_SPACE)
			{
				Player::GetInstance().MovePositionFront(); // �X�y�[�X�L�[�ł���΃v���C���[���ړ�����
				changed_flag_ = true;
			}
			else if (input_key == KEY_ARROW)
			{
				input_key = _getch(); // �\���L�[�ł���΍ĂуL�[���͂��󂯎��
				switch (input_key) {
				case KEY_LEFT:
					Player::GetInstance().MoveNextPositionLeft(); // ���L�[�ł���Έړ�����W�����Ɉړ�����
					changed_flag_ = true;
					break;
				case KEY_RIGHT:
					Player::GetInstance().MoveNextPositionRight(); // �E�L�[�ł���Έړ�����W���E�Ɉړ�����
					changed_flag_ = true;
					break;
				}
			}
		}
		this->goal_flag_ = CheckGoal(); // �v���C���[���S�[���ɂ��邩����
	}
	SetCursorPosition(0, 24);
	cout << "�N���A�ł� [SPACE]�Ŏ��ɐi��";
	while (1)
	{
		if (_kbhit())
		{
			int input_key = _getch();
			if (input_key == KEY_SPACE)
			{
				break;
			}
			else if (input_key == 0 || input_key == 224)
			{
				_getch();
			}
		}
	}
	Player::GetInstance().GoUpstairs(); // �v���C���[�̊K��1�i�߂�
	system("cls"); // ��ʂ���������
	return 0;
}

void ItemFloor::Update(pair<int, int> now_position, pair<int, int> next_position)
{
	for (int x = 0; x < ITEM_FLOOR_WIDTH; x++)
	{
		for (int y = 0; y < ITEM_FLOOR_HEIGT; y++)
		{
			if (x == now_position.first && y == now_position.second)
			{

				if (room_[x][y].item_get_flag == false) // �v���C���[�̍��W���A�C�e�������t���O��false�Ȃ�΃A�C�e�����l������
				{
					Player::GetInstance().GetItem(room_[x][y].item_status);
					room_[x][y].item_get_flag = true;
				}
				room_[x][y].room_status = 1; // �v���C���[�̂��镔���̏�Ԃ�1�ɂ���
			}
			else if (x == next_position.first && y == next_position.second)
			{
				room_[x][y].room_status = 2; // �v���C���[�̈ړ���̕����̏�Ԃ�2�ɂ���
			}
			else
			{
				room_[x][y].room_status = 0; // ����ȊO�̕����̏�Ԃ�0�ɂ���
			}
		}
	}
}

void ItemFloor::Print()
{
	
	SetCursorPosition(0, 0);
	for (int y = 0; y < ITEM_FLOOR_HEIGT; y++) // PrintLine�𗘗p���ă_���W�������o��
	{
		PrintLine(y, false);
		PrintLine(y, true);
		PrintLine(y, false);
	}
	SetColor(COL_WHITE, COL_BLACK); // �����F��,�w�i�F�����ɐݒ�
	Player::GetInstance().PrintNowFloor();
	SetCursorPosition(60, 5); // �J�[�\����(60, 5)�Ɉړ�
	cout << "�ړ��F[��][��]";
	SetCursorPosition(60, 6); // �J�[�\����(60, 6)�Ɉړ�
	cout << "�I���F[SPACE]";
	Player::GetInstance().PrintItemStatus(item_position_); // ���L�A�C�e�����o��
	SetCursorPosition(0, 0); // �J�[�\����(0, 0)�Ɉړ�
}

void ItemFloor::PrintLine(int y, bool print_value_flag)
{
	for (int x = 0; x < ITEM_FLOOR_WIDTH; x++) {
		int fg = COL_WHITE;
		int bg = COL_BLACK;
		switch (room_[x][y].room_status) {
		case 0:
			if (y == 0)
			{
				bg = COL_DARK_RED; // y��0(�S�[���n�_)�Ȃ�Δw�i�F��Ԃɂ���
			}
			else if (y == ITEM_FLOOR_HEIGT - 1)
			{
				bg = COL_DARK_BLUE; // y��ITEM_FLOOR_HEIGT-1(�X�^�[�g�n�_)�Ȃ�Δw�i�F��ɂ���
			}
			else
			{
				bg = COL_LIGHT_GRAY; // ����ȊO�͔w�i�F���O���[�ɂ���
			}
			break;
		case 1:
			bg = COL_DARK_GREEN; // �����̏�Ԃ�1(�v���C���[������)�Ȃ�Δw�i�F��΂ɂ���
			break;
		case 2:
			bg = COL_DARK_YELLOW; // �����̏�Ԃ�2(�v���C���[�̈ړ���)�Ȃ�Δw�i�F�����ɂ���
			break;
		}
		SetColor(fg, bg);
		string str(CELL_WIDTH, ' ');
		if (print_value_flag) {
			if (!room_[x][y].room_status)
			{
				str = '.'; // �����̏�Ԃ�0(�v���C���[,�ړ���ł͂Ȃ�)�̏ꍇ.���Z�b�g����
			}
			else
			{
				if (room_[x][y].room_status == 1) // �����̏�Ԃ�1(�v���C���[)�̏ꍇP���Z�b�g����
				{
					str = 'P';
				}
				else if (room_[x][y].room_status == 2) // �����̏�Ԃ�2(�v���C���[�̈ړ���)�̏ꍇN���Z�b�g����
				{
					str = 'N';
				}
			}
			str += string((CELL_WIDTH - str.size()) / 2, ' ');		//	�����ɋ󔒃p�f�B���O
			str = string(CELL_WIDTH - str.size(), ' ') + str;		//	�擪�ɋ󔒃p�f�B���O
		}
		cout << str;
	}
	cout << "\n";
}

bool ItemFloor::CheckGoal()
{
	for (int x = 0; x < ITEM_FLOOR_WIDTH; x++)
	{
		if (room_[x][0].room_status == 1) {
			return true;
		}
	}
	return false;
}