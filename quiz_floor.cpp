#include "quiz_floor.h"

QuizFloor::QuizFloor()
{
	//ファイルの読み込み
	ifstream ifs("csv/quiz.csv");
	if (!ifs) {
		return;
	}

	//csvファイルを1行ずつ読み込む
	string str;
	while (getline(ifs, str)) {
		int optCnt = 0;
		int dtCnt = 0;
		Quiz q;
		string token;
		istringstream stream(str);

		//1行のうち、文字列とコンマを分割する
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
	this->itr = qz_array.begin();
}

QuizFloor::~QuizFloor()
{
}


int QuizFloor::quiz_floor_main()
{
	if (itr < qz_array.end())
	{
		switch (this->qf_status)
		{
		case 0:
		{
			if (this->qz_init_flag)
			{
				t.typing_init((*itr).quiz_get_tp_str());
				this->qz_init_flag = false;
			}
			this->qf_status = t.typing_main();
			break;
		}
		case 1:
			if (this->qm_init_flag)
			{
				qm.quiz_maker_init(*itr);
				this->qm_init_flag = false;
			}
			this->qf_status = qm.quiz_maker_main(*itr);
			break;
		case 2:
			this->itr++;
			this->qf_status = 0;
			this->qz_init_flag = true;
			this->qm_init_flag = true;
			return 1;
			break;
		}
		
	}
	return 0;
}