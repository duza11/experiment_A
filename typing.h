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
	int typing_main(string word);

private:
	int key = 0;
	int score = 0;
	int mistake = 0;
	string word;
	string input;
};