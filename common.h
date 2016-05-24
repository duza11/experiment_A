#pragma once

#include <time.h>

#define WALL -1							// 番人
#define BOARD_WD 3						// ボード幅
#define BOARD_HT 7						// ボード高さ
#define BOARD_ARY_WD (BOARD_WD + 2)		// ボード用配列の1次元目の要素数
#define BOARD_ARY_HT (BOARD_HT + 2)		// ボード用配列の2次元目の要素数
#define CELL_WIDTH 8					// セル表示幅

#define PLAYER_X ((BOARD_WD + 1) / 2)	// プレイヤーの初期X座標
#define PLAYER_Y BOARD_HT				// プレイヤーの初期Y座標
#define PLAYER_NEXT_X PLAYER_X			// プレイヤーの次の初期X座標
#define PLAYER_NEXT_Y (PLAYER_Y - 1)	// プレイヤーの次の初期Y座標
#define PLAYER_MAX_X BOARD_WD			// プレイヤーのX座標の最大値
#define PLAYER_MIN_X 1					// プレイヤーのX座標の最小値
#define PLAYER_MAX_Y BOARD_HT			// プレイヤーのY座標の最大値

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