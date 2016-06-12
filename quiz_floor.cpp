#include "quiz_floor.h"

QuizFloor::QuizFloor()
{
	vector<Quiz> easy_quiz_array;
	vector<Quiz> hard_quiz_array;
	SetQuizArray("csv/easy_quiz.csv", easy_quiz_array);
	SetQuizArray("csv/hard_quiz.csv", hard_quiz_array);
	quiz_array_ = {easy_quiz_array[0], easy_quiz_array[1], easy_quiz_array[2], hard_quiz_array[0], hard_quiz_array[1], hard_quiz_array[2], hard_quiz_array[3]};
	this->text_position_ = { MESSAGE_BOX_X, MESSAGE_BOX_Y };
	this->text_box_ = new TextBox(text_position_, MESSAGE_BOX_WIDTH, MESSAGE_BOX_HEIGHT);
}

int QuizFloor::QuizFloorMain()
{
	for (auto itr = quiz_array_.begin(); itr < quiz_array_.begin() + QUIZ_FLOOR_SIZE; itr++)
	{
		this->quiz_ = &(*itr);
		Player::GetInstance().PrintNowFloor();
		TypingMain();
		Player::GetInstance().PrintNowFloor();
		QuizMain();
		if (Timer::GetInstance().CheckTime())
		{
			Player::GetInstance().GoUpstairs();
		}
		else
		{
			break;
		}
	}
	delete text_box_;
	return 0;
}

void QuizFloor::TypingMain()
{
	this->mistake_ = 0;
	string typing_str = (*quiz_).typing_str;
	string input_str = "";
	this->changed_flag_ = true;
	this->message_.clear();

	for (auto itr = typing_str.begin(); itr != typing_str.end() && Timer::GetInstance().CheckTime();)
	{
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
				this->message_.clear();
			}
			else
			{
				this->mistake_++;
				Timer::GetInstance().PenaltyTime(5);
				this->message_ = "�^�C�s���O�~�X�ł�";
			}
			this->changed_flag_ = true;
		}
		if (changed_flag_)
		{
			SetCursorPosition(70, 5);
			cout << "�~�X�F" << this->mistake_ << "��";
			SetCursorPosition(0, 0);
			cout << "���̕��͂��^�C�s���O���Ă�������\n";
			cout << "1��^�C�s���O�~�X���邲�ƂɃy�i���e�B�Ƃ��Ďc�莞�Ԃ�-5����܂�\n\n\n\n\n\n";
			cout << typing_str << "\n\n";
			cout << input_str;
			SetColor(COL_WHITE, COL_CYAN);
			cout << " ";
			SetColor(COL_WHITE, COL_BLACK);

			this->changed_flag_ = false;
			text_box_->Print();
			SetCursorPosition(MESSAGE_X, MESSAGE_Y);
			cout << this->message_;
		}
	}
	PrintGoalMessage();
}

void QuizFloor::QuizMain()
{
	this->changed_flag_ = true;
	this->goal_flag_ = false;
	this->next_menu_ = kBaseMenu;
	this->menu_ = (Menu*) new BaseMenu(this);
	this->message_.clear();

	SetCursorPosition(0, 0);
	cout << "�N�C�Y�ɐ������Ă�������\n";
	cout << "�ԈႦ�邲�ƂɃy�i���e�B�Ƃ��Ďc�莞�Ԃ�-20�b����܂�\n\n\n\n\n";
	cout << "Q." << (*quiz_).quiz_str;
	SetCursorPosition(70, 9); // �J�[�\����(70, 9)�Ɉړ�
	cout << "�ړ��F[��][��]";
	SetCursorPosition(70, 10); // �J�[�\����(70, 10)�Ɉړ�
	cout << "����F[ENTER]";
	SetCursorPosition(70, 11); // �J�[�\����(70, 11)�Ɉړ�
	cout << "�߂�F[BACKSPACE]";

	PrintQuiz();
	while (Timer::GetInstance().CheckTime() && !goal_flag_)
	{
		UpdateQuizMenu();
		PrintQuiz();
	}
	Timer::GetInstance().SwitchTimer(true);
	Player::GetInstance().EnableItem();
	PrintGoalMessage();
	Timer::GetInstance().PrintTime();
}

void QuizFloor::UpdateQuizMenu()
{
	if (this->next_menu_ != kNoneMenu)
	{
		menu_->Finitialize();
		delete menu_;
		switch (this->next_menu_)
		{
		case kBaseMenu:
			this->menu_ = (Menu*) new BaseMenu(this);
			break;
		case kItemMenu:
			this->menu_ = (Menu*) new ItemMenu(this, quiz_);
			break;
		case kAnswerMenu:
			this->menu_ = (Menu*) new AnswerMenu(this, quiz_);
			break;
		}
		this->next_menu_ = kNoneMenu;
		this->changed_flag_ = true;
	}
	if (!changed_flag_)
	{
		this->changed_flag_ = menu_->Update();
	}
}

void QuizFloor::CheckAnswer(int option_num)
{
	if ((*quiz_).enable_flag[option_num])
	{
		if ((*quiz_).answer_type[option_num])
		{
			this->goal_flag_ = true;
		}
		else
		{
			Timer::GetInstance().PenaltyTime(20);
			this->message_ = "�s�����ł�";
		}
		(*quiz_).enable_flag[option_num] = false;
	}
	else
	{
		this->message_ = "���̉𓚂͑I���ł��܂���";
	}
}

void QuizFloor::set_message(string message)
{
	this->message_ = message;
}

void QuizFloor::SwitchMenu(MenuEnum next_menu)
{
	this->next_menu_ = next_menu;
}

void QuizFloor::PrintQuiz()
{
	if (changed_flag_)
	{
		Timer::GetInstance().PrintTime();
		this->menu_->Print();
		SetCursorPosition(0, QUIZ_START_Y);
		for (int i = 0; i < QUIZ_OPTION_SIZE; i++) {
			if ((*quiz_).enable_flag[i])
			{
				SetColor(COL_WHITE, COL_BLACK);
			}
			else if ((*quiz_).answer_type[i])
			{
				SetColor(COL_GREEN, COL_BLACK);
			}
			else
			{
				SetColor(COL_RED, COL_BLACK);
			}
			cout << " " << (char)('A' + i) << "." << (*quiz_).quiz_opt[i] << "\n";
			SetColor(COL_WHITE, COL_BLACK);
		}
		this->changed_flag_ = false;
		text_box_->Print();
		SetCursorPosition(MESSAGE_X, MESSAGE_Y);
		cout << this->message_;
	}
}

void QuizFloor::PrintGoalMessage()
{
	text_box_->Print();
	SetCursorPosition(MESSAGE_X, MESSAGE_Y);
	cout << "�N���A�ł� [ENTER]�Ŏ��ɐi��";
	while (Timer::GetInstance().CheckTime())
	{
		if (_kbhit())
		{
			int input_key = _getch();
			if (input_key == KEY_ENTER)
			{
				break;
			}
			else if (input_key == 0 || input_key == 224)
			{
				_getch();
			}
		}
	}
	system("cls");
}

void QuizFloor::SetQuizArray(string file_name, vector<Quiz> &quiz_array)
{
	//�t�@�C���̓ǂݍ���
	ifstream ifs(file_name);
	if (!ifs) {
		return;
	}

	//csv�t�@�C����1�s���ǂݍ���
	string str;
	Quiz quiz;
	while (getline(ifs, str)) {
		int option_count = 0;
		int data_count = 0;
		string token;
		istringstream stream(str);

		//1�s�̂����A������ƃR���}�𕪊�����
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
		quiz_array.push_back(quiz);
	}
	for (auto itr = quiz_array.begin(); itr != quiz_array.end(); itr++)
	{
		int ran_num = (unsigned)rnd() % quiz_array.size();
		Quiz temp = *itr;
		*itr = quiz_array[ran_num];
		quiz_array[ran_num] = temp;
	}
}
