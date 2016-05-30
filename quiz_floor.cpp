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
	Quiz quiz_;
	while (getline(ifs, str)) {
		int option_count = 0;
		int data_count = 0;
		string token;
		istringstream stream(str);

		//1行のうち、文字列とコンマを分割する
		while (getline(stream, token, ',')) {
			if (data_count % QZ_DT_SIZE < 2)
			{
				if (data_count % 2 == 0)
				{
					quiz_.typing_str = token;
				}
				else
				{
					quiz_.quiz_str = token;
				}
			}
			else
			{
				if (data_count % 2 == 0)
				{
					quiz_.quiz_opt[option_count] = token;
				}
				else
				{
					int temp = stoi(token);
					quiz_.answer_type[option_count] = temp;
					option_count++;
				}
			}
			data_count++;
		}
		quiz_array_.push_back(quiz_);
	}
}

QuizFloor::~QuizFloor()
{
}

int QuizFloor::quiz_floor_main()
{
	for (auto itr = quiz_array_.begin(); itr < quiz_array_.begin() + QZ_FLOOR_SIZE; itr++)
	{
		Player::GetInstance().PrintNowFloor();
		TypingMain((*itr).typing_str);
		Player::GetInstance().PrintNowFloor();
		QuizMain((*itr));
		if (Timer::get_instance().timer_check())
		{
			Player::GetInstance().GoUpstairs();
		}
	}
	return 0;
}

void QuizFloor::TypingMain(string &sentence)
{
	mistake_ = 0;
	string typing_str = sentence;
	string input_str = "";
	changed_flag_ = true;
	for (auto itr = typing_str.begin(); itr != typing_str.end() && Timer::get_instance().timer_check();)
	{
		if (changed_flag_)
		{
			setCursorPos(0, 0);
			cout << "ミス" << mistake_ << "回\n\n";
			cout << typing_str << "\n";
			cout << input_str;
			setColor(COL_WHITE, COL_CYAN);
			cout << " \n";
			setColor(COL_WHITE, COL_BLACK);
			changed_flag_ = false;
		}
		if (_kbhit())
		{
			input_key_ = _getch();
			if (input_key_ == 0 || input_key_ == 224) input_key_ = _getch();
			{
				if (input_key_ == (int)*itr)
				{
					input_str.push_back(*itr);
					itr++;
				}
				else
				{
					this->mistake_++;
					Timer::get_instance().timer_penalty(1);
				}
				changed_flag_ = true;
			}
		}
	}
	system("cls");
	Timer::get_instance().timer_print();
}

void QuizFloor::QuizMain(Quiz & quiz)
{
	changed_flag_ = true;
	goal_flag_ = false;
	next_menu_ = kBaseMenu;
	bm = (Menu*) new BaseMenu(this);

	setCursorPos(0, 0);
	cout << quiz.quiz_str;

	
	PrintQuiz(quiz);
	while (Timer::get_instance().timer_check() && !goal_flag_)
	{
		UpdateQuizMenu(quiz);
		PrintQuiz(quiz);
	}
	system("cls");
	Timer::get_instance().timer_switch(true);
	Timer::get_instance().timer_print();
	Player::GetInstance().EnableItem();
}

void QuizFloor::UpdateQuizMenu(Quiz &quiz)
{
	if (next_menu_ != kNoneMenu)
	{
		bm->Finitialize();
		delete bm;
		switch (next_menu_)
		{
		case kBaseMenu:
			bm = (Menu*) new BaseMenu(this);
			break;
		case kItemMenu:
			bm = (Menu*) new ItemMenu(this, &quiz);
			break;
		case kAnswerMenu:
			bm = (Menu*) new AnswerMenu(this, &quiz);
			break;
		}
		next_menu_ = kNoneMenu;
		changed_flag_ = true;
	}
	if (!changed_flag_)
	{
		changed_flag_ = bm->Update();
	}
}

void QuizFloor::CheckAnswer(Quiz &quiz, int option_num)
{
	if (quiz.enable_flag[option_num])
	{
		if (quiz.answer_type[option_num])
		{
			goal_flag_ = true;
		}
		else
		{
			Timer::get_instance().timer_penalty(30);
		}
		quiz.enable_flag[option_num] = false;
	}
}

void QuizFloor::SwitchMenu(MenuEnum next_menu)
{
	next_menu_ = next_menu;
}

void QuizFloor::PrintQuiz(Quiz &quiz)
{
	if (changed_flag_)
	{
		bm->Print();
		setCursorPos(0, QZ_START_Y);
		for (int i = 0; i < QZ_OPT_SIZE; i++) {
			if (quiz.enable_flag[i])
			{
				setColor(COL_WHITE, COL_BLACK);
			}
			else
			{
				setColor(COL_GRAY, COL_BLACK);
			}
			cout << " " << (char)('A' + i) << "." << quiz.quiz_opt[i] << "\n";
			setColor(COL_WHITE, COL_BLACK);
		}
		changed_flag_ = false;
	}
}
