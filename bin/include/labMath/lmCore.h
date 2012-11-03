#ifndef __LAB_CORE_H_
#define	__LAB_CORE_H_

#include <math.h>

//Boot Code
#include "lmBoot.h"

//Matrices
#include "lmMatrix4.h"

//Vectors
#include "lmVec2.h"
#include "lmVec3.h"
#include "lmVec4.h"

static const lmBoot gs_klmBoot;

//Math Intrinsics
enum LM_INTRIN_SET
{
	LM_INTRIN_STD,
	LM_INTRIN_ISPC,
	LM_INTRIN_NONE,
	LM_INTRIN_ERROR,
	LM_INTRIN_COUNT
};

static const float LM_PI		= 3.14159265f;
static const float LM_PI_HALF	= 1.57079632f;
static const float LM_PI_TWO	= 6.28318530f;

LM_INTRIN_SET lmGetIntrinsic();
void lmSetIntrinsic(LM_INTRIN_SET a_kIntrinsic);

float __fastcall lmSqrt(float a_dArgIn);

#endif//__LAB_MATH_H_