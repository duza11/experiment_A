#pragma once

#include "common.h"
#include "console_util.h"

class TextBox
{
public:
	TextBox();
	TextBox(pair<int, int> pos, int box_ht, int box_wd);
	~TextBox();
	void Print();
	void Finitialize();

private:
	pair<int, int> pos;
	int  box_ht;
	int box_wd;
};