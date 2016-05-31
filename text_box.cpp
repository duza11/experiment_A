#include "text_box.h"

TextBox::TextBox()
{
}

TextBox::TextBox(pair<int, int> posion, int width, int box_HEIGHT)
{
	this->position_ = posion;
	this->width_ = width;
	this->height_ = box_HEIGHT;
}

TextBox::~TextBox()
{
}

void TextBox::Print()
{
	for (int y = 0; y < this->height_; y++)
	{
		setCursorPos(this->position_.first, this->position_.second + y);
		for (int x = 0; x < this->width_; x += 2)
		{
			if (x == 0 && y == 0)
			{
				cout << "„¬";
			}
			else if (x == this->width_ - 2 && y == 0)
			{
				cout << "„­";
			}
			else if (x == 0 && y == this->height_ - 1)
			{
				cout << "„¯";
			}
			else if (x == this->width_ - 2 && y == this->height_ - 1)
			{
				cout << "„®";
			}
			else if (x == 0 || x == this->width_ - 2)
			{
				cout << "„«";
			}
			else if (y == 0 || y == this->height_ - 1)
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
	for (int y = 0; y < this->height_; y++)
	{
		setCursorPos(this->position_.first, this->position_.second + y);
		for (int x = 0; x < this->width_; x += 2)
		{
			cout << "  ";
		}
	}
}
