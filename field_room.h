#pragma once

class FieldRoom
{
public:
	FieldRoom();
	FieldRoom(int status, int item);
	~FieldRoom();

private:
	int status;
	int item;
};