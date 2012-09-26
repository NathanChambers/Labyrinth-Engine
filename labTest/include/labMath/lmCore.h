#ifndef __LAB_CORE_H_
#define	__LAB_CORE_H_

#include <math.h>

#include "lmBoot.h"

#include "lmVec2.h"
#include "lmVec3.h"
#include "lmVec4.h"

#include "lmMatrix3.h"
#include "lmMatrix4.h"

static const LmBoot g_kBoot;

static const float LM_PI		= 3.14159265f;
static const float LM_PI_HALF	= 1.57079632f;
static const float LM_PI_TWO	= 6.28318530f;

float __fastcall lmSqrt(float a_dArgIn);

#endif//__LAB_MATH_H_