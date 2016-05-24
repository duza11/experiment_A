#pragma once

#include <time.h>

#define WALL -1							// �Ԑl
#define BOARD_WD 3						// �{�[�h��
#define BOARD_HT 7						// �{�[�h����
#define BOARD_ARY_WD (BOARD_WD + 2)		// �{�[�h�p�z���1�����ڂ̗v�f��
#define BOARD_ARY_HT (BOARD_HT + 2)		// �{�[�h�p�z���2�����ڂ̗v�f��
#define CELL_WIDTH 8					// �Z���\����

#define PLAYER_X ((BOARD_WD + 1) / 2)	// �v���C���[�̏���X���W
#define PLAYER_Y BOARD_HT				// �v���C���[�̏���Y���W
#define PLAYER_NEXT_X PLAYER_X			// �v���C���[�̎��̏���X���W
#define PLAYER_NEXT_Y (PLAYER_Y - 1)	// �v���C���[�̎��̏���Y���W
#define PLAYER_MAX_X BOARD_WD			// �v���C���[��X���W�̍ő�l
#define PLAYER_MIN_X 1					// �v���C���[��X���W�̍ŏ��l
#define PLAYER_MAX_Y BOARD_HT			// �v���C���[��Y���W�̍ő�l

#define TIME 600
#define QZ_FLOOR_SIZE 7

typedef enum
{
	eItem_harf,
	eItem_time,

	eItem_length,
} eItem;

class Item
{
public:
	static Item& get_instance()
	{
		static Item item;
		return item;
	}

	void get_item(int selected_item) {
		this->avail_item[selected_item]++;
	}

	void use_item(int selected_item) {
		if (use_flag[selected_item]) {
			switch (selected_item)
			{
			case eItem_harf:
				break;
			case eItem_time:
				break;
			}
		}
	}

private:
	Item()
	{
		for (int i = 0; i < eItem_length; i++)
		{
			avail_item[i] = 0;
			use_flag[i] = 0;
		}
	}
	Item(const Item & item) {}
	~Item() {}
	
	static Item* item;
	int avail_item[eItem_length];
	int use_flag[eItem_length];
};