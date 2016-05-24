#pragma once

#include <time.h>

#define WALL -1							// �Ԑl
#define BOARD_WD 3						// �{�[�h��
#define BOARD_HT 7						// �{�[�h����
#define BOARD_ARY_WD (BOARD_WD + 2)		// �{�[�h�p�z���1�����ڂ̗v�f��
#define BOARD_ARY_HT (BOARD_HT + 2)		// �{�[�h�p�z���2�����ڂ̗v�f��
#define CELL_WIDTH 8					// �Z���\����

#define PLAYER_X ((BOARD_WD + 1) / 2)	// �v���C���[�̏���X���W
#define PLAYER_Y BOARD_HT				// �v���C���[�̏���Y���W
#define PLAYER_NEXT_X PLAYER_X			// �v���C���[�̎��̏���X���W
#define PLAYER_NEXT_Y (PLAYER_Y - 1)	// �v���C���[�̎��̏���Y���W
#define PLAYER_MAX_X BOARD_WD			// �v���C���[��X���W�̍ő�l
#define PLAYER_MIN_X 1					// �v���C���[��X���W�̍ŏ��l
#define PLAYER_MAX_Y BOARD_HT			// �v���C���[��Y���W�̍ő�l

#define TIME 600
#define QZ_FLOOR_SIZE 7

#define QZ_OPT_SIZE 6
#define QZ_DT_SIZE ((QZ_OPT_SIZE * 2) + 2)

typedef enum
{
	eItem_harf,
	eItem_time,

	eItem_length,
} eItem;