#include "lmCore.h"
#include <stdio.h>
#include <crtdbg.h>

using namespace Labyrinth;

void PrintVec4(const lmVec4& ac_rkArgIn)
{
	printf("X:%f Y:%f Z:%f W:%f \n",ac_rkArgIn.x,ac_rkArgIn.y,ac_rkArgIn.z,ac_rkArgIn.w);
}

int main()
{
	lmVec4 kVec0(1,2,3);
	lmVec4 kVec1(1,2,3);

	float fSameDir = kVec0.DotProduct(kVec1);

	kVec1.Set(3,2,1);
	float fOppDir = kVec0.DotProduct(kVec1);

	_CrtDumpMemoryLeaks();

	getchar();
	return 0;
}