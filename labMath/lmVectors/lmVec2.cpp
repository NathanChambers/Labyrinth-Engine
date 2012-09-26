#include "lmVec2.h"
#include "lmCore.h"

const LmVec2 LmVec2::ZERO = LmVec2(0,0);
const LmVec2 LmVec2::POSX = LmVec2(1,0);
const LmVec2 LmVec2::POSY = LmVec2(0,1);
const LmVec2 LmVec2::NEGX = LmVec2(-1,0);
const LmVec2 LmVec2::NEGY = LmVec2(0,-1);

void std_lmVec2Add(LmVec2& a_rkArgOut,const LmVec2& ac_rkArgL,const LmVec2& ac_rkArgR)
{
	a_rkArgOut.x = ac_rkArgL.x + ac_rkArgR.x;
	a_rkArgOut.y = ac_rkArgL.y + ac_rkArgR.y;
}

void std_lmVec2Sub(LmVec2& a_rkArgOut,const LmVec2& ac_rkArgL,const LmVec2& ac_rkArgR)
{
	a_rkArgOut.x = ac_rkArgL.x - ac_rkArgR.x;
	a_rkArgOut.y = ac_rkArgL.y - ac_rkArgR.y;
}

void std_lmVec2Mul(LmVec2& a_rkArgOut,const LmVec2& ac_rkArgL,const float ac_fArgR)
{
	a_rkArgOut.x = ac_rkArgL.x * ac_fArgR;
	a_rkArgOut.y = ac_rkArgL.y * ac_fArgR;
}

void std_lmVec2Div(LmVec2& a_rkArgOut,const LmVec2& ac_rkArgL,const float ac_fArgR)
{
	a_rkArgOut.x = ac_rkArgL.x / ac_fArgR;
	a_rkArgOut.y = ac_rkArgL.y / ac_fArgR;
}

void std_lmVec2Negative(LmVec2& a_rkArgOut,const LmVec2& ac_rkArgL)
{
	a_rkArgOut.x = -ac_rkArgL.x;
	a_rkArgOut.y = -ac_rkArgL.y;
}

bool std_lmVec2Equals(const LmVec2& ac_rkArgL,const LmVec2& ac_rkArgR)
{
	return ac_rkArgL.x == ac_rkArgR.x &&
		ac_rkArgL.y == ac_rkArgR.y;
}

bool std_lmVec2NotEquals(const LmVec2& ac_rkArgL,const LmVec2& ac_rkArgR)
{
	return ac_rkArgL.x != ac_rkArgR.x &&
		ac_rkArgL.y != ac_rkArgR.y;
}

float std_lmVec2DotProduct(const LmVec2& ac_rkArgL,const LmVec2& ac_rkArgR)
{
	return ac_rkArgL.x * ac_rkArgR.x +
		ac_rkArgL.y * ac_rkArgR.y;
}

float std_lmVec2Length(const LmVec2& ac_rkArgL)
{
	return lmSqrt(ac_rkArgL.x * ac_rkArgL.x + 
		ac_rkArgL.y * ac_rkArgL.y);
}

float std_lmVec2LengthSqr(const LmVec2& ac_rkArgL)
{
	return ac_rkArgL.x * ac_rkArgL.x + 
		ac_rkArgL.y * ac_rkArgL.y;
}

void std_lmVec2Normalise(LmVec2& a_rkArgOut,const LmVec2& ac_rkArgL)
{
	float fLength = ac_rkArgL.Length();
	a_rkArgOut.x = ac_rkArgL.x / fLength;
	a_rkArgOut.y = ac_rkArgL.y / fLength;
}

void std_lmVec2Maximise(LmVec2& a_rkArgOut,const LmVec2& ac_rkArgL)
{
	float fHighest = ac_rkArgL.x;
	for(unsigned int i = 1;i < 2;i++)
	{
		if(ac_rkArgL[i] > fHighest)
			fHighest = ac_rkArgL[i];
	}
	a_rkArgOut.Set(fHighest,fHighest);
}

void std_lmVec2Minimise(LmVec2& a_rkArgOut,const LmVec2& ac_rkArgL)
{
	float fLowest = ac_rkArgL.x;
	for(unsigned int i = 1;i < 2;i++)
	{
		if(ac_rkArgL[i] < fLowest)
			fLowest = ac_rkArgL[i];
	}
	a_rkArgOut.Set(fLowest,fLowest);
}

//bool(const LmVec2&, const LmVec2&)
lmVec2_Bool_CVec2_CVec2 LmVec2Equals = nullptr;
lmVec2_Bool_CVec2_CVec2 LmVec2NotEquals = nullptr;

//void (LmVec2&, const LmVec2&)
lmVec2_Void_Vec2_CVec2 LmVec2Normalise = nullptr;
lmVec2_Void_Vec2_CVec2 LmVec2Maximise = nullptr;
lmVec2_Void_Vec2_CVec2 LmVec2Minimise = nullptr;
lmVec2_Void_Vec2_CVec2 LmVec2Negative = nullptr;

//void (LmVec2&, const LmVec2&, float)
lmVec2_Void_Vec2_CVec2_Float LmVec2Mul = nullptr;
lmVec2_Void_Vec2_CVec2_Float LmVec2Div = nullptr;

//void (LmVec2&, const LmVec2&, const LmVec2&)
lmVec2_Void_Vec2_CVec2_CVec2 LmVec2Add = nullptr;
lmVec2_Void_Vec2_CVec2_CVec2 LmVec2Sub = nullptr;

//float (const LmVec2&)
lmVec2_Float_CVec2 LmVec2Length = nullptr;
lmVec2_Float_CVec2 LmVec2LengthSqr = nullptr;

//float (cosnt LmVec2&, const LmVec2&)
lmVec2_Float_CVec2_CVec2 LmVec2DotProduct = nullptr;

void LmVec2::Construct()
{
	LmVec2Equals = &std_lmVec2Equals;
	LmVec2NotEquals = &std_lmVec2NotEquals;

	LmVec2Normalise = &std_lmVec2Normalise;
	LmVec2Maximise = &std_lmVec2Maximise;
	LmVec2Minimise = &std_lmVec2Minimise;
	LmVec2Negative = &std_lmVec2Negative;

	LmVec2Mul = &std_lmVec2Mul;
	LmVec2Div = &std_lmVec2Div;

	LmVec2Add = &std_lmVec2Add;
	LmVec2Sub = &std_lmVec2Sub;
	
	LmVec2Length = &std_lmVec2Length;
	LmVec2LengthSqr = &std_lmVec2LengthSqr;

	LmVec2DotProduct = &std_lmVec2DotProduct;
}