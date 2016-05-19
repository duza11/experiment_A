#pragma once

#include <conio.h>		//	_getch
#include <iostream>
#include "field.h"
#include "player.h"
#include "consoleUtil.h"

#define	KEY_ARROW 0xe0
#define	KEY_UP 0x48
#define	KEY_LEFT 0x4b
#define	KEY_RIGHT 0x4d
#define	KEY_DOWN 0x50

class ItemFloor
{
public:
	ItemFloor();
	~ItemFloor();
	int item_floor_main();

private:
	bool clear_flag;
	Field f;
	Player p;
};