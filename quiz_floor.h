#pragma once

#include <vector>
#include "typing.h"
#include "quiz.h"

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
	int quiz_floor_main();

private:
	vector<Quiz> qz_array;
};