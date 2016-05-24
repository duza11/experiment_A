#include "field_room.h"

FieldRoom::FieldRoom()
{
	this->status = 0;
	this->item = 0;
	item_flag = true;
}

FieldRoom::FieldRoom(int status, int item)
{
	this->status = status;
	this->item = item;
}

FieldRoom::~FieldRoom()
{
}

void FieldRoom::field_room_update(int status)
{
	this->status = status;
}

int FieldRoom::field_room_get_status()
{
	return this->status;
}

int FieldRoom::field_room_get_item()
{
	return this->item;
}

bool FieldRoom::field_room_get_item_flag()
{
	return this->item_flag;
}

void FieldRoom::field_room_set_item_flag(bool item_flag)
{
	this->item_flag = item_flag;
}
