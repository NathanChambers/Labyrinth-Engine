#include "lmVec2.h"
#include "lmCore.h"

const lmVec2 lmVec2::ZERO = lmVec2(0,0);
const lmVec2 lmVec2::POSX = lmVec2(1,0);
const lmVec2 lmVec2::POSY = lmVec2(0,1);
const lmVec2 lmVec2::NEGX = lmVec2(-1,0);
const lmVec2 lmVec2::NEGY = lmVec2(0,-1);

void std_lmVec2Add(lmVec2& a_rkArgOut,const lmVec2& ac_rkArgL,const lmVec2& ac_rkArgR)
{
	a_rkArgOut.x = ac_rkArgL.x + ac_rkArgR.x;
	a_rkArgOut.y = ac_rkArgL.y + ac_rkArgR.y;
}

void std_lmVec2Sub(lmVec2& a_rkArgOut,const lmVec2& ac_rkArgL,const lmVec2& ac_rkArgR)
{
	a_rkArgOut.x = ac_rkArgL.x - ac_rkArgR.x;
	a_rkArgOut.y = ac_rkArgL.y - ac_rkArgR.y;
}

void std_lmVec2Mul(lmVec2& a_rkArgOut,const lmVec2& ac_rkArgL,const float ac_fArgR)
{
	a_rkArgOut.x = ac_rkArgL.x * ac_fArgR;
	a_rkArgOut.y = ac_rkArgL.y * ac_fArgR;
}

void std_lmVec2Div(lmVec2& a_rkArgOut,const lmVec2& ac_rkArgL,const float ac_fArgR)
{
	a_rkArgOut.x = ac_rkArgL.x / ac_fArgR;
	a_rkArgOut.y = ac_rkArgL.y / ac_fArgR;
}

void std_lmVec2Negative(lmVec2& a_rkArgOut,const lmVec2& ac_rkArgL)
{
	a_rkArgOut.x = -ac_rkArgL.x;
	a_rkArgOut.y = -ac_rkArgL.y;
}

bool std_lmVec2Equals(const lmVec2& ac_rkArgL,const lmVec2& ac_rkArgR)
{
	return ac_rkArgL.x == ac_rkArgR.x &&
		ac_rkArgL.y == ac_rkArgR.y;
}

bool std_lmVec2NotEquals(const lmVec2& ac_rkArgL,const lmVec2& ac_rkArgR)
{
	return ac_rkArgL.x != ac_rkArgR.x &&
		ac_rkArgL.y != ac_rkArgR.y;
}

float std_lmVec2DotProduct(const lmVec2& ac_rkArgL,const lmVec2& ac_rkArgR)
{
	return ac_rkArgL.x * ac_rkArgR.x +
		ac_rkArgL.y * ac_rkArgR.y;
}

float std_lmVec2Length(const lmVec2& ac_rkArgL)
{
	return lmSqrt(ac_rkArgL.x * ac_rkArgL.x + 
		ac_rkArgL.y * ac_rkArgL.y);
}

float std_lmVec2LengthSqr(const lmVec2& ac_rkArgL)
{
	return ac_rkArgL.x * ac_rkArgL.x + 
		ac_rkArgL.y * ac_rkArgL.y;
}

void std_lmVec2Normalise(lmVec2& a_rkArgOut,const lmVec2& ac_rkArgL)
{
	float fLength = ac_rkArgL.Length();
	a_rkArgOut.x = ac_rkArgL.x / fLength;
	a_rkArgOut.y = ac_rkArgL.y / fLength;
}

void std_lmVec2Maximise(lmVec2& a_rkArgOut,const lmVec2& ac_rkArgL)
{
	float fHighest = ac_rkArgL.x;
	for(unsigned int i = 1;i < 2;i++)
	{
		if(ac_rkArgL[i] > fHighest)
			fHighest = ac_rkArgL[i];
	}
	a_rkArgOut.Set(fHighest,fHighest);
}

void std_lmVec2Minimise(lmVec2& a_rkArgOut,const lmVec2& ac_rkArgL)
{
	float fLowest = ac_rkArgL.x;
	for(unsigned int i = 1;i < 2;i++)
	{
		if(ac_rkArgL[i] < fLowest)
			fLowest = ac_rkArgL[i];
	}
	a_rkArgOut.Set(fLowest,fLowest);
}

////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
extern "C" 
{
	#endif // __cplusplus
		extern void ispcVec2Add(float* a_pkArgOut,const float* ac_pkArgL,const float* ac_pkArgR);
		extern void ispcVec2Sub(float* a_pkArgOut,const float* ac_pkArgL,const float* ac_pkArgR);
		extern void ispcVec2Mul(float* a_pkArgOut,const float* ac_pkArgL,const float ac_fArgR);
		extern void ispcVec2Div(float* a_pkArgOut,const float* ac_pkArgL,const float ac_fArgR);
		extern void ispcVec2Negative(float* a_pkArgOut,const float* ac_pkArgL);
		extern bool ispcVec2Equals(const float* ac_pkArgL,const float* ac_pkArgR);
		extern bool ispcVec2NotEquals(const float* ac_pkArgL,const float* ac_pkArgR);
		extern float ispcVec2DotProduct(const float* ac_pkArgL,const float* ac_pkArgR);
		extern float ispcVec2Length(const float* ac_pkArgL);
		extern float ispcVec2LengthSqr(const float* ac_pkArgL);
		extern void ispcVec2Normalise(float* a_pkArgOut,const float* ac_pkArgL);
		extern void ispcVec2Maximise(float* a_pkArgOut,const float* ac_pkArgL);
		extern void ispcVec2Minimise(float* a_pkArgOut,const float* ac_pkArgL);
	#ifdef __cplusplus
}
#endif // __cplusplus

void ispc_lmVec2Add(lmVec2& a_rkArgOut,const lmVec2& ac_rkArgL,const lmVec2& ac_rkArgR)
{
	ispcVec2Add(a_rkArgOut,ac_rkArgL,ac_rkArgR);
}

void ispc_lmVec2Sub(lmVec2& a_rkArgOut,const lmVec2& ac_rkArgL,const lmVec2& ac_rkArgR)
{
	ispcVec2Sub(a_rkArgOut,ac_rkArgL,ac_rkArgR);
}

void ispc_lmVec2Mul(lmVec2& a_rkArgOut,const lmVec2& ac_rkArgL,const float ac_fArgR)
{
	ispcVec2Mul(a_rkArgOut,ac_rkArgL,ac_fArgR);
}

void ispc_lmVec2Div(lmVec2& a_rkArgOut,const lmVec2& ac_rkArgL,const float ac_fArgR)
{
	ispcVec2Div(a_rkArgOut,ac_rkArgL,ac_fArgR);
}

void ispc_lmVec2Negative(lmVec2& a_rkArgOut,const lmVec2& ac_rkArgL)
{
	ispcVec2Negative(a_rkArgOut,ac_rkArgL);
}

bool ispc_lmVec2Equals(const lmVec2& ac_rkArgL,const lmVec2& ac_rkArgR)
{
	return ispcVec2Equals(ac_rkArgL,ac_rkArgR);
}

bool ispc_lmVec2NotEquals(const lmVec2& ac_rkArgL,const lmVec2& ac_rkArgR)
{
	return ispcVec2NotEquals(ac_rkArgL,ac_rkArgR);
}

float ispc_lmVec2DotProduct(const lmVec2& ac_rkArgL,const lmVec2& ac_rkArgR)
{
	return ispcVec2DotProduct(ac_rkArgL,ac_rkArgR);
}

float ispc_lmVec2Length(const lmVec2& ac_rkArgL)
{
	return ispcVec2Length(ac_rkArgL);
}

float ispc_lmVec2LengthSqr(const lmVec2& ac_rkArgL)
{
	return ispcVec2LengthSqr(ac_rkArgL);
}

void ispc_lmVec2Normalise(lmVec2& a_rkArgOut,const lmVec2& ac_rkArgL)
{
	ispcVec2Normalise(a_rkArgOut,ac_rkArgL);
}

void ispc_lmVec2Maximise(lmVec2& a_rkArgOut,const lmVec2& ac_rkArgL)
{
	ispcVec2Maximise(a_rkArgOut,ac_rkArgL);
}

void ispc_lmVec2Minimise(lmVec2& a_rkArgOut,const lmVec2& ac_rkArgL)
{
	ispcVec2Minimise(a_rkArgOut,ac_rkArgL);
}

////////////////////////////////////////////////////////////////////////////////

//bool(const lmVec2&, const lmVec2&)
lmVec2_Bool_CVec2_CVec2 lmVec2Equals = nullptr;
lmVec2_Bool_CVec2_CVec2 lmVec2NotEquals = nullptr;

//void (lmVec2&, const lmVec2&)
lmVec2_Void_Vec2_CVec2 lmVec2Normalise = nullptr;
lmVec2_Void_Vec2_CVec2 lmVec2Maximise = nullptr;
lmVec2_Void_Vec2_CVec2 lmVec2Minimise = nullptr;
lmVec2_Void_Vec2_CVec2 lmVec2Negative = nullptr;

//void (lmVec2&, const lmVec2&, float)
lmVec2_Void_Vec2_CVec2_Float lmVec2Mul = nullptr;
lmVec2_Void_Vec2_CVec2_Float lmVec2Div = nullptr;

//void (lmVec2&, const lmVec2&, const lmVec2&)
lmVec2_Void_Vec2_CVec2_CVec2 lmVec2Add = nullptr;
lmVec2_Void_Vec2_CVec2_CVec2 lmVec2Sub = nullptr;

//float (const lmVec2&)
lmVec2_Float_CVec2 lmVec2Length = nullptr;
lmVec2_Float_CVec2 lmVec2LengthSqr = nullptr;

//float (cosnt lmVec2&, const lmVec2&)
lmVec2_Float_CVec2_CVec2 lmVec2DotProduct = nullptr;

void lmVec2::Construct()
{
	switch(lmGetIntrinsic())
	{
	case LM_INTRIN_STD:
		{
			lmVec2Equals = &std_lmVec2Equals;
			lmVec2NotEquals = &std_lmVec2NotEquals;

			lmVec2Normalise = &std_lmVec2Normalise;
			lmVec2Maximise = &std_lmVec2Maximise;
			lmVec2Minimise = &std_lmVec2Minimise;
			lmVec2Negative = &std_lmVec2Negative;

			lmVec2Mul = &std_lmVec2Mul;
			lmVec2Div = &std_lmVec2Div;

			lmVec2Add = &std_lmVec2Add;
			lmVec2Sub = &std_lmVec2Sub;
	
			lmVec2Length = &std_lmVec2Length;
			lmVec2LengthSqr = &std_lmVec2LengthSqr;

			lmVec2DotProduct = &std_lmVec2DotProduct;
			break;
		}

	case LM_INTRIN_ISPC:
		{
			lmVec2Equals = &ispc_lmVec2Equals;
			lmVec2NotEquals = &ispc_lmVec2NotEquals;

			lmVec2Normalise = &ispc_lmVec2Normalise;
			lmVec2Maximise = &ispc_lmVec2Maximise;
			lmVec2Minimise = &ispc_lmVec2Minimise;
			lmVec2Negative = &ispc_lmVec2Negative;

			lmVec2Mul = &ispc_lmVec2Mul;
			lmVec2Div = &ispc_lmVec2Div;

			lmVec2Add = &ispc_lmVec2Add;
			lmVec2Sub = &ispc_lmVec2Sub;
	
			lmVec2Length = &ispc_lmVec2Length;
			lmVec2LengthSqr = &ispc_lmVec2LengthSqr;

			lmVec2DotProduct = &ispc_lmVec2DotProduct;
			break;
		}
	default:
		{
			lmVec2Equals = nullptr;
			lmVec2NotEquals = nullptr;

			lmVec2Normalise = nullptr;
			lmVec2Maximise = nullptr;
			lmVec2Minimise = nullptr;
			lmVec2Negative = nullptr;

			lmVec2Mul = nullptr;
			lmVec2Div = nullptr;

			lmVec2Add = nullptr;
			lmVec2Sub = nullptr;
	
			lmVec2Length = nullptr;
			lmVec2LengthSqr = nullptr;

			lmVec2DotProduct = nullptr;
			break;
		}
	}
}