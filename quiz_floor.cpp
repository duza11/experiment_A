#include "quiz_floor.h"

QuizFloor::QuizFloor()
{
	//�t�@�C���̓ǂݍ���
	ifstream ifs("../csv/quiz.csv");
	if (!ifs) {
		return;
	}

	//csv�t�@�C����1�s���ǂݍ���
	string str;
	while (getline(ifs, str)) {
		int optCnt = 0;
		int dtCnt = 0;
		Quiz q;
		string token;
		istringstream stream(str);

		//1�s�̂����A������ƃR���}�𕪊�����
		while (getline(stream, token, ',')) {
			if (dtCnt % QZ_DT_SIZE < 2)
			{
				if (dtCnt % 2 == 0)
				{
					q.quiz_set_tp_str(token);
				}
				else
				{
					q.quiz_set_qz(token);
				}
			}
			else
			{
				if (dtCnt % 2 == 0)
				{
					q.quiz_set_qz_opt(optCnt, token);
				}
				else
				{
					int temp = stof(token);
					q.quiz_set_ans_type(optCnt % QZ_OPT_SIZE, temp);
					optCnt++;
				}
			}
			dtCnt++;
		}
		qz_array.push_back(q);
	}
}

QuizFloor::~QuizFloor()
{
}

int QuizFloor::quiz_floor_main()
{
	for (auto itr = qz_array.begin(); itr < qz_array.end(); itr++)
	{
		Typing t;
		t.typing_main((*itr).quiz_get_tp_str());
		qm.quiz_maker_main(*itr);
	}
	return 0;
}