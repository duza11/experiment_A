#pragma once

#include <string>
#include <vector>

using namespace std;

/*1F�֘A*/
#define WALL -1	// ��
#define ITEM_FLOOR_WIDTH 3 // 1F�̃_���W�����̉���
#define ITEM_FLOOR_HEIGT 7 // 1F�̃_���W�����̏c��
#define CELL_WIDTH 8 // �Z���\����
#define PLAYER_X (ITEM_FLOOR_WIDTH / 2) // �v���C���[�̏���X���W
#define PLAYER_Y ITEM_FLOOR_HEIGT - 1 // �v���C���[�̏���Y���W
#define PLAYER_NEXT_X PLAYER_X // �v���C���[�̎��̏���X���W
#define PLAYER_NEXT_Y (PLAYER_Y - 1) // �v���C���[�̎��̏���Y���W
/*�^�C�}�[�֘A*/
#define REMAINING_TIME 600 // ��������
/*2F�ȍ~�֘A*/
#define QUIZ_START_Y 10// �N�C�Y�̑I�����̊J�nY���W
#define QUIZ_FLOOR_SIZE 7 // �N�C�Y���o�肷��K��
#define QUIZ_OPTION_SIZE 6 // �N�C�Y�̑I�����̐�
#define QUIZ_DATA_SIZE ((QUIZ_OPTION_SIZE * 2) + 2) // CVS�ɂ�����N�C�Y1��̃f�[�^��
/*��{���j���[�֘A*/
#define BASE_MENU_BOX_X 0
#define BASE_MENU_BOX_Y 22
#define BASE_MENU_OPTION_X (BASE_MENU_BOX_X + 3)
#define BASE_MENU_OPTION_Y (BASE_MENU_BOX_Y + 1)
#define BASE_MENU_BOX_WIDTH 16
#define BASE_MENU_BOX_HEIGHT 4
/*�񓚃��j���[�֘A*/
#define ANSWER_MENU_BOX_X 10
#define ANSWER_MENU_BOX_Y 18
#define ANSWER_MENU_OPTION_X (ANSWER_MENU_BOX_X + 3)
#define ANSWER_MENU_OPTION_Y (ANSWER_MENU_BOX_Y + 1)
#define ANSWER_MENU_BOX_WIDTH 40
#define ANSWER_MENU_BOX_HEIGHT 8
/*�A�C�e�����j���[�֘A*/
#define ITEM_MENU_BOX_X 10
#define ITEM_MENU_BOX_Y 22
#define ITEM_MENU_OPTION_X (ITEM_MENU_BOX_X + 3)
#define ITEM_MENU_OPTION_Y (ITEM_MENU_BOX_Y + 1)
#define ITEM_MENU_BOX_WIDTH 32
#define ITEM_MENU_BOX_HEIGHT 4
#define ITEM_EXPLAIN_BOX_X 40
#define ITEM_EXPLAIN_BOX_Y 18
#define ITEM_EXPLAIN_X (ITEM_EXPLAIN_BOX_X + 2)
#define ITEM_EXPLAIN_Y (ITEM_EXPLAIN_BOX_Y + 1)
#define ITEM_EXPLAIN_WIDTH 24
#define ITEM_EXPLAIN_HEIGHT 8

/*���b�Z�[�W�{�b�N�X�֘A*/
#define MESSAGE_BOX_X 0
#define MESSAGE_BOX_Y 26
#define MESSAGE_BOX_WIDTH 44
#define MESSAGE_BOX_HEIGHT 3
#define MESSAGE_X (MESSAGE_BOX_X + 2)
#define MESSAGE_Y (MESSAGE_BOX_Y + 1)

//�A�C�e���p�̗񋓌^
typedef enum
{
	kFiftyFifty,
	kStopTimer,

	kItemKind,
} ItemNum;

typedef struct
{
	string typing_str;
	string quiz_str;
	string quiz_opt[QUIZ_OPTION_SIZE];
	bool answer_type[QUIZ_OPTION_SIZE];
	bool enable_flag[QUIZ_OPTION_SIZE];
} Quiz;

typedef struct
{
	string player_name;
	int score;
	string time;
	string grade;
} Ranking;

void SplitString(string & input_str, vector<string> & str_array, int length); // �k��T��