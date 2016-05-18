#pragma once

#include <new.h>
#include "field_room.h"
#include "common.h"

class Field
{
public:
	Field();
	~Field();

private:
	FieldRoom r[BOARD_WD + 2][BOARD_HT + 2];
};