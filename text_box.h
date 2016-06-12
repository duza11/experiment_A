#pragma once

#include "common.h"
#include "console_util.h"

class TextBox
{
public:
	TextBox(); // �k��T��
	TextBox(pair<int, int> position, int height, int width); // �k��T��
	~TextBox(); // �k��T��
	void Print(); // �k��T��
	void Finitialize(); // �k��T��

private:
	pair<int, int> position_;
	int  height_;
	int width_;
};