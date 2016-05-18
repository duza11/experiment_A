#pragma once

#include <new.h>
#include "room.h"
#include "common.h"

class RoomMgr
{
public:
	RoomMgr();
	~RoomMgr();

private:
	Room r[BOARD_WD + 2][BOARD_HT + 2];
};