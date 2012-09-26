#include "lmCore.h"

__declspec (naked) float __fastcall lmSqrt(float a_dArgIn)
{
	_asm fld dword ptr [esp+4]
	_asm fsqrt
	_asm ret 4
}