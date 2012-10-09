#include "lmCore.h"

static const LmBoot g_kBoot;
LM_INTRIN_SET g_kIntrinsic = LM_INTRIN_STD;
LM_INTRIN_SET g_kNextIntrinsic = LM_INTRIN_ERROR;

LM_INTRIN_SET lmGetIntrinsic()
{
	return g_kIntrinsic;
}

void lmSetIntrinsic(LM_INTRIN_SET a_kIntrinsic)
{
	g_kNextIntrinsic = a_kIntrinsic;
	g_kBoot.Reboot();
}

__declspec (naked) float __fastcall lmSqrt(float a_dArgIn)
{
	_asm fld dword ptr [esp+4]
	_asm fsqrt
	_asm ret 4
}