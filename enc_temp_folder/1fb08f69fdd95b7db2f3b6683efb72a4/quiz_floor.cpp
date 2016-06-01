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
	Quiz quiz;
	while (getline(ifs, str)) {
		int option_count = 0;
		int data_count = 0;
		string token;
		istringstream stream(str);

		//1行のうち、文字列とコンマを分割する
		while (getline(stream, token, ',')) {
			if (data_count % QUIZ_DATA_SIZE < 2)
			{
				if (data_count % 2 == 0)
				{
					quiz.typing_str = token;
				}
				else
				{
					quiz.quiz_str = token;
				}
			}
			else
			{
				if (data_count % 2 == 0)
				{
					quiz.quiz_opt[option_count] = token;
				}
				else
				{
					int temp = stoi(token);
					quiz.answer_type[option_count] = temp;
					option_count++;
				}
			}
			data_count++;
		}
		for (int i = 0; i < QUIZ_OPTION_SIZE; i++)
		{
			int ran_num = (unsigned)rnd() % QUIZ_OPTION_SIZE;
			string quiz_opt_temp = quiz.quiz_opt[i];
			bool answer_type_temp = quiz.answer_type[i];
			quiz.quiz_opt[i] = quiz.quiz_opt[ran_num];
			quiz.answer_type[i] = quiz.answer_type[ran_num];
			quiz.quiz_opt[ran_num] = quiz_opt_temp;
			quiz.answer_type[ran_num] = answer_type_temp;
		}
		quiz_array_.push_back(quiz);
	}
	for (auto itr = quiz_array_.begin(); itr != quiz_array_.end(); itr++)
	{
		int ran_num = (unsigned)rnd() % quiz_array_.size();
		Quiz temp = *itr;
		*itr = quiz_array_[ran_num];
		quiz_array_[ran_num] = temp;
	}
}

QuizFloor::~QuizFloor()
{
}

int QuizFloor::QuizFloorMain()
{
	for (auto itr = quiz_array_.begin(); itr < quiz_array_.begin() + QUIZ_FLOOR_SIZE; itr++)
	{
		quiz_ = &(*itr);
		Player::GetInstance().PrintNowFloor();
		TypingMain();
		Player::GetInstance().PrintNowFloor();
		QuizMain();
		if (Timer::GetInstance().CheckTime())
		{
			Player::GetInstance().GoUpstairs();
		}
	}
	return 0;
}

void QuizFloor::TypingMain()
{
	mistake_ = 0;
	string typing_str = (*quiz_).typing_str;
	string input_str = "";
	changed_flag_ = true;
	for (auto itr = typing_str.begin(); itr != typing_str.end() && Timer::GetInstance().CheckTime();)
	{
		if (changed_flag_)
		{
			setCursorPos(0, 0);
			cout << "ミス" << mistake_ << "回\n\n\n";
			cout << "次の文章をタイピングしてください\n\n\n";
			cout << typing_str << "\n";
			cout << input_str;
			setColor(COL_WHITE, COL_CYAN);
			cout << " \n";
			setColor(COL_WHITE, COL_BLACK);
			changed_flag_ = false;
		}
		if (_kbhit())
		{
			int input_key = _getch();
			if (input_key == 0 || input_key == 224)
			{
				input_key = _getch();
			}
			if (input_key == (int)*itr)
			{
				input_str.push_back(*itr);
				itr++;
			}
			else
			{
				this->mistake_++;
				Timer::GetInstance().PenaltyTime(1);
			}
			changed_flag_ = true;
		}
	}
	system("cls");
	Timer::GetInstance().PrintTime();
}

void QuizFloor::QuizMain()
{
	changed_flag_ = true;
	goal_flag_ = false;
	next_menu_ = kBaseMenu;
	menu_ = (Menu*) new BaseMenu(this);

	setCursorPos(0, 0);
	cout << (*quiz_).quiz_str;


	PrintQuiz();
	while (Timer::GetInstance().CheckTime() && !goal_flag_)
	{
		UpdateQuizMenu();
		PrintQuiz();
	}
	system("cls");
	Timer::GetInstance().SwitchTimer(true);
	Timer::GetInstance().PrintTime();
	Player::GetInstance().EnableItem();
}

void QuizFloor::UpdateQuizMenu()
{
	if (next_menu_ != kNoneMenu)
	{
		menu_->Finitialize();
		delete menu_;
		switch (next_menu_)
		{
		case kBaseMenu:
			menu_ = (Menu*) new BaseMenu(this);
			break;
		case kItemMenu:
			menu_ = (Menu*) new ItemMenu(this, quiz_);
			break;
		case kAnswerMenu:
			menu_ = (Menu*) new AnswerMenu(this, quiz_);
			break;
		}
		next_menu_ = kNoneMenu;
		changed_flag_ = true;
	}
	if (!changed_flag_)
	{
		changed_flag_ = menu_->Update();
	}
}

void QuizFloor::CheckAnswer(int option_num)
{
	if ((*quiz_).enable_flag[option_num])
	{
		if ((*quiz_).answer_type[option_num])
		{
			goal_flag_ = true;
		}
		else
		{
			Timer::GetInstance().PenaltyTime(30);
		}
		(*quiz_).enable_flag[option_num] = false;
	}
}

void QuizFloor::SwitchMenu(MenuEnum next_menu)
{
	next_menu_ = next_menu;
}

void QuizFloor::PrintQuiz()
{
	if (changed_flag_)
	{
		menu_->Print();
		setCursorPos(0, QZ_START_Y);
		for (int i = 0; i < QUIZ_OPTION_SIZE; i++) {
			if ((*quiz_).enable_flag[i])
			{
				setColor(COL_WHITE, COL_BLACK);
			}
			else
			{
				setColor(COL_GRAY, COL_BLACK);
			}
			cout << " " << (char)('A' + i) << "." << (*quiz_).quiz_opt[i] << "\n";
			setColor(COL_WHITE, COL_BLACK);
		}
		changed_flag_ = false;
	}
}
