#pragma once

#include <vector>
#include "typing.h"
#include "quiz_maker.h"

#include<fstream>
#include<iostream>
#include<string>
#include<sstream> //�����X�g���[��

using namespace std;

class QuizFloor
{
public:
	QuizFloor();
	~QuizFloor();
	int quiz_floor_main();

private:
	vector<Quiz> qz_array;
	QuizMaker qm;
};