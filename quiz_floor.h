#pragma once

#include <vector>
#include "typing.h"
#include "quiz_maker.h"

#include<fstream>
#include<iostream>
#include<string>
#include<sstream> //•¶šƒXƒgƒŠ[ƒ€

using namespace std;

class QuizFloor
{
public:
	QuizFloor();
	~QuizFloor();
	vector<Quiz>::iterator Quiz_floor_get_q_itr();
	int quiz_floor_main();

private:
	int qf_status = 0;
	vector<Quiz> qz_array;
	QuizMaker qm;
};