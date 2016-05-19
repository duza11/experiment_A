#pragma once

class FieldRoom
{
public:
	FieldRoom();
	FieldRoom(int status, int item);
	~FieldRoom();
	void field_room_update(int status);
	int field_room_get_status();

private:
	int status;
	int item;
};