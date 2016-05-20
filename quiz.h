#pragma once

#include <string>
#include <fstream>

#define QZ_OPT_SIZE 6
#define QZ_DT_SIZE ((QZ_OPT_SIZE * 2) + 2)

using namespace std;

class Quiz
{
public:
	Quiz();
	~Quiz();
	void quiz_set_tp_str(string tp_str);
	void quiz_set_qz(string qz_str);
	void quiz_set_qz_opt(int index, string qz_opt);
	void quiz_set_ans_type(int index, bool ans_type);
	string quiz_get_tp_str();
	string quiz_get_qz();
	string quiz_get_qz_opt(int index);
	bool quiz_get_ans_type(int index);

private:
	string tp_str;
	string qz_str;
	string qz_opt[QZ_OPT_SIZE];
	bool ans_type[QZ_OPT_SIZE];
	bool qz_opt_flag[QZ_OPT_SIZE];
};