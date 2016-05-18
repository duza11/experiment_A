#include "field_room.h"

FieldRoom::FieldRoom()
{
	this->status = 0;
	this->item = 0;
}

FieldRoom::FieldRoom(int status, int item)
{
	this->status = status;
	this->item = item;
}

FieldRoom::~FieldRoom()
{
}

int FieldRoom::field_room_get_status()
{
	return this->status;
}
