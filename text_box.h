#pragma once

#include "common.h"
#include "console_util.h"

class TextBox
{
public:
	TextBox(); // –kì—Tˆê
	TextBox(pair<int, int> position, int height, int width); // –kì—Tˆê
	~TextBox(); // –kì—Tˆê
	void Print(); // –kì—Tˆê
	void Finitialize(); // –kì—Tˆê

private:
	pair<int, int> position_;
	int  height_;
	int width_;
};