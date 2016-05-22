#pragma once

#include <vector>
#include "typing.h"
#include "quiz_maker.h"
#include <new.h>

#include<fstream>
#include<iostream>
#include<string>
#include<sstream> //文字ストリーム

using namespace std;

class QuizFloor
{
public:
	QuizFloor();
	~QuizFloor();
	int quiz_floor_main();

private:
	bool qz_init_flag = true;
	bool qm_init_flag = true;
	int qf_status = 0;
	vector<Quiz> qz_array;
	vector<Quiz>::iterator itr;
	Typing t;
	QuizMaker qm;
};