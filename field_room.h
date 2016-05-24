#pragma once

class FieldRoom
{
public:
	FieldRoom();
	FieldRoom(int status, int item);
	~FieldRoom();
	void field_room_update(int status);
	int field_room_get_status();
	int field_room_get_item();
	bool field_room_get_item_flag();
	void field_room_set_item_flag(bool item_flag);

private:
	int status;
	int item;
	bool item_flag;
};