#pragma once

#include "common.h"
#include "consoleUtil.h"

class TextBox
{
public:
	TextBox();
	TextBox(pair<int, int> pos, int box_ht, int box_wd);
	~TextBox();
	void print();
	void finitialize();

private:
	pair<int, int> pos;
	int  box_ht;
	int box_wd;
};