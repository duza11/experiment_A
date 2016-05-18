#pragma once

#include <new.h>
#include <iostream>
#include <sstream>      // std::ostringstream
#include <string>
#include "consoleUtil.h"
#include "field_room.h"
#include "common.h"

using namespace std;

class Field
{
public:
	Field();
	~Field();
	void field_print_line(int y, bool printVal);
	void field_print();

private:
	FieldRoom fr[BOARD_WD + 2][BOARD_HT + 2];
};