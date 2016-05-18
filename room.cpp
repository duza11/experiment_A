#include "room.h"

Room::Room()
{
	this->status = 0;
	this->item = 0;
}

Room::Room(int status, int item)
{
	this->status = status;
	this->item = item;
}

Room::~Room()
{
}