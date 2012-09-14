#include "lmCore.h"

using namespace Labyrinth;

float Labyrinth::lmSqrt(float a_fVal)
{
	_asm
	{
		fld a_fVal;
		fsqrt;
		fst a_fVal;
	}
	return a_fVal;
}