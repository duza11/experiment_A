#pragma once

#include "common.h"
#include "console_util.h"

class TextBox
{
public:
	TextBox();
	TextBox(pair<int, int> position, int height, int width);
	~TextBox();
	void Print();
	void Finitialize();

private:
	pair<int, int> position_;
	int  height_;
	int width_;
};