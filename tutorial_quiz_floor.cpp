#include "tutorial_quiz_floor.h"

TutorialQuizFloor::TutorialQuizFloor()
{
}

int TutorialQuizFloor::QuizFloorMain()
{
	Quiz quiz;
	quiz.typing_str = "typing test";
	quiz.quiz_str = "1+1‚Í‰½‚Å‚µ‚å‚¤‚©?";
	for (int i = 0; i < QUIZ_OPTION_SIZE; i++) {
		quiz.quiz_opt[i] = to_string(i);
		quiz.enable_flag[i] = true;
		if (i == 2)
		{
			quiz.answer_type[i] = true;
		}
		else
		{
			quiz.answer_type[i] = false;
		}
	}
	this->quiz_ = &quiz;
	Player::GetInstance().PrintNowFloor();
	TypingMain();
	Player::GetInstance().PrintNowFloor();
	QuizMain();
	delete text_box_;
	return 0;
}