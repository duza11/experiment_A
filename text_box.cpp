#include "text_box.h"

TextBox::TextBox()
{
}

TextBox::TextBox(pair<int, int> pos, int box_wd, int box_ht)
{
	this->pos = pos;
	this->box_wd = box_wd;
	this->box_ht = box_ht;
}

TextBox::~TextBox()
{
}

void TextBox::Print()
{
	for (int y = 0; y < this->box_ht; y++)
	{
		setCursorPos(this->pos.first, this->pos.second + y);
		for (int x = 0; x < this->box_wd; x += 2)
		{
			if (x == 0 && y == 0)
			{
				cout << "„¬";
			}
			else if (x == this->box_wd - 2 && y == 0)
			{
				cout << "„­";
			}
			else if (x == 0 && y == this->box_ht - 1)
			{
				cout << "„¯";
			}
			else if (x == this->box_wd - 2 && y == this->box_ht - 1)
			{
				cout << "„®";
			}
			else if (x == 0 || x == this->box_wd - 2)
			{
				cout << "„«";
			}
			else if (y == 0 || y == this->box_ht - 1)
			{
				cout << "„ª";
			}
			else
			{
				cout << "  ";
			}
		}
	}
}

void TextBox::Finitialize()
{
	for (int y = 0; y < this->box_ht; y++)
	{
		setCursorPos(this->pos.first, this->pos.second + y);
		for (int x = 0; x < this->box_wd; x += 2)
		{
			cout << "  ";
		}
	}
}
