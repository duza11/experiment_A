#include "tutorial_item_floor.h"

TutorialItemFloor::TutorialItemFloor()
{
	for (int y = 0; y < ITEM_FLOOR_HEIGT; y++) {
		for (int x = 0; x < ITEM_FLOOR_WIDTH; x++) {
			if (y == 0 || y == ITEM_FLOOR_HEIGT - 1)
			{
				tutorial_room[x][y] = { 0, -1, true };	// y = ITEM_FLOOR_HEIGHT(�X�^�[�g�ʒu),y = 0(�S�[���ʒu)�ł̓A�C�e���Ȃ�,�A�C�e�������t���O��true�ɂ���
			}
			else
			{
				tutorial_room[x][y] = { 0, (x - 1), false }; // ����ȊO�̕�����2��ނ̃A�C�e�����A�C�e���Ȃ��Ƃ���,�A�C�e�������p�t���O��false�ɂ���
			}
		}
		for (int x = 0; x < ITEM_FLOOR_WIDTH; x++) // �A�C�e���̔z�u�������_���ɂ���
		{
			int ran_num = (unsigned)rnd() % ITEM_FLOOR_WIDTH;
			int temp = tutorial_room[x][y].item_status;
			tutorial_room[x][y].item_status = tutorial_room[ran_num][y].item_status;
			tutorial_room[ran_num][y].item_status = temp;
		}

	}
}

