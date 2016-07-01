#pragma once
#include "item_floor.h"

#define TUTORIAL_ITEM_FLOOR_WIDTH 3
#define TUTORIAL_ITEM_FLOOR_HEIGHT 3

class TutorialItemFloor : public ItemFloor
{
public:
	TutorialItemFloor();
	
	
	Room tutorial_room[TUTORIAL_ITEM_FLOOR_WIDTH][TUTORIAL_ITEM_FLOOR_HEIGHT];
	random_device rnd;
};