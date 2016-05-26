#include "quiz_floor.h"
#include "timer.h"

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
					int temp = stoi(token);
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
	for (auto itr = qz_array.begin(); itr < qz_array.begin() + QZ_FLOOR_SIZE; itr++)
	{
		if (!Timer::get_instance().timer_check()) break;
		t.typing_init((*itr).quiz_get_tp_str());
		t.typing_main();

		qm.quiz_maker_init(*itr);
		qm.quiz_maker_main(*itr);
	}
	return 0;
}