#include "tutorial_item_floor.h"

TutorialItemFloor::TutorialItemFloor()
{
	for (int y = 0; y < ITEM_FLOOR_HEIGT; y++) {
		for (int x = 0; x < ITEM_FLOOR_WIDTH; x++) {
			if (y == 0 || y == ITEM_FLOOR_HEIGT - 1)
			{
				tutorial_room[x][y] = { 0, -1, true };	// y = ITEM_FLOOR_HEIGHT(スタート位置),y = 0(ゴール位置)ではアイテムなし,アイテム所得フラグをtrueにする
			}
			else
			{
				tutorial_room[x][y] = { 0, (x - 1), false }; // それ以外の部屋は2種類のアイテムかアイテムなしとして,アイテム所得用フラグをfalseにする
			}
		}
		for (int x = 0; x < ITEM_FLOOR_WIDTH; x++) // アイテムの配置をランダムにする
		{
			int ran_num = (unsigned)rnd() % ITEM_FLOOR_WIDTH;
			int temp = tutorial_room[x][y].item_status;
			tutorial_room[x][y].item_status = tutorial_room[ran_num][y].item_status;
			tutorial_room[ran_num][y].item_status = temp;
		}

	}
}

