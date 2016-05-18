#pragma once

class Room
{
public:
	Room();
	Room(int status, int item);
	~Room();

private:
	int status;
	int item;
};