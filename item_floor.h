#pragma once

#include <conio.h>		//	_getch
#include <iostream>
#include "field.h"
#include "player.h"
#include "consoleUtil.h"

class ItemFloor
{
public:
	ItemFloor();
	~ItemFloor();
	int item_floor_main();

private:
	bool moved_flag;
	bool movable_flag;
	bool clear_flag;
	Field f;
	Player p;
};