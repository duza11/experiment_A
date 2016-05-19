//----------------------------------------------------------------------
//		2048
//		Copyright (C) 2048 by N.Tsuda
//		License: CDDL 1.0 (http://opensource.org/licenses/CDDL-1.0)
//----------------------------------------------------------------------

#include <time.h>			//	time
#include <string>
#include "item_floor.h"
#include "common.h"

int	g_score = 0;
//int	g_nBlank;		//	ãÛóìâ”èäêî

//----------------------------------------------------------------------

int main()
{
	ItemFloor itf;
	itf.item_floor_main();
	return 0;
}