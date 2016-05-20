#include "quiz.h"

Quiz::Quiz()
{
	for (int i = 0; i < QZ_OPT_SIZE; i++)
	{
		this->qz_opt_flag[i] = true;
	}
}

Quiz::~Quiz()
{
}

void Quiz::quiz_set_tp_str(string tp_str)
{
	this->tp_str = tp_str;
}

void Quiz::quiz_set_qz(string qz_str)
{
	this->qz_str = qz_str;
}

void Quiz::quiz_set_qz_opt(int index, string qz_opt)
{
	this->qz_opt[index] = qz_opt;
}

void Quiz::quiz_set_ans_type(int index, bool ans_type)
{
	this->ans_type[index] = ans_type;
}

string Quiz::quiz_get_tp_str()
{
	return this->tp_str;
}

string Quiz::quiz_get_qz()
{
	return this->qz_str;
}

string Quiz::quiz_get_qz_opt(int index)
{
	return this->qz_opt[index];
}

bool Quiz::quiz_get_ans_type(int index)
{
	return this->ans_type[index];
}
