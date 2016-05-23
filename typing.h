#pragma once

#include <conio.h>
#include <iostream>
#include <string>
#include "common.h"
#include "consoleUtil.h"

using namespace std;

class Typing
{
public:
	Typing();
	~Typing();
	void typing_init(string word);
	int typing_main();

private:
	int key = 0;
	int mistake = 0;
	bool moved = true;
	bool clear_flag = false;
	string word;
	string input;
};