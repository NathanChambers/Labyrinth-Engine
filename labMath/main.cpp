#include "lmCore.h"
#include <stdio.h>
#include <crtdbg.h>
#include <math.h>

void PrintVec4(const LmVec4& ac_rkArgIn)
{
	printf("X:%f Y:%f Z:%f W:%f \n",ac_rkArgIn.x,ac_rkArgIn.y,ac_rkArgIn.z,ac_rkArgIn.w);
}

int main()
{
	_CrtDumpMemoryLeaks();

	getchar();
	return 0;
}