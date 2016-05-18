#pragma once

#include "room.h"
#include "common.h"

class RoomMgr
{
public:
	RoomMgr();
	~RoomMgr();

private:
	Room r[BOARD_WD][BOARD_HT];
};

RoomMgr::RoomMgr()
{
}

RoomMgr::~RoomMgr()
{
}