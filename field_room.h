#pragma once

class FieldRoom
{
public:
	FieldRoom();
	FieldRoom(int status, int item);
	~FieldRoom();
	int field_room_get_status();

private:
	int status;
	int item;
};