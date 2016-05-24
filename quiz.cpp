#include "quiz.h"

Quiz::Quiz()
{
	for (int i = 0; i < QZ_OPT_SIZE; i++)
	{
		this->answered_flag[i] = false;
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

bool Quiz::quiz_get_answered_flag(int index)
{
	return this->answered_flag[index];
}

bool Quiz::quiz_ans_check(int index)
{
	if (!this->answered_flag[index])
	{
		if (!this->ans_type[index])
		{
			Timer::get_instance().timer_penalty(30);
		}
		this->answered_flag[index] = true;
	}
	return this->ans_type[index];
}