#include "lmCore/lmCore.h"
#include <stdio.h>
#include <crtdbg.h>

using namespace Labyrinth;

void PrintVec4(const lmVec4& ac_rkArgIn)
{
	printf("X:%f Y:%f Z:%f W:%f \n",ac_rkArgIn.x,ac_rkArgIn.y,ac_rkArgIn.z,ac_rkArgIn.w);
}

int main()
{
	lmVec4 kVec0(1,1,1);
	lmVec4 kVec1(1,1,1);

	kVec0.Normalise();
	kVec1.Normalise();

	float fVAL = kVec0.DotProduct(kVec1);

	_CrtDumpMemoryLeaks();

	getchar();
	return 0;
}