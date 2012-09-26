#include "lmVec4.h"
#include "lmCore.h"

const LmVec4 LmVec4::ZERO = LmVec4(0,0,0,1);
const LmVec4 LmVec4::POSX = LmVec4(1,0,0,1);
const LmVec4 LmVec4::POSY = LmVec4(0,1,0,1);
const LmVec4 LmVec4::POSZ = LmVec4(0,0,1,1);
const LmVec4 LmVec4::NEGX = LmVec4(-1,0,0,1);
const LmVec4 LmVec4::NEGY = LmVec4(0,-1,0,1);
const LmVec4 LmVec4::NEGZ = LmVec4(0,0,-1,1);

void std_lmVec4Add(LmVec4& a_rkArgOut,const LmVec4& ac_rkArgL,const LmVec4& ac_rkArgR)
{
	a_rkArgOut.x = ac_rkArgL.x + ac_rkArgR.x;
	a_rkArgOut.y = ac_rkArgL.y + ac_rkArgR.y;
	a_rkArgOut.z = ac_rkArgL.z + ac_rkArgR.z;
	a_rkArgOut.w = ac_rkArgL.w + ac_rkArgR.w;
}

void std_lmVec4Sub(LmVec4& a_rkArgOut,const LmVec4& ac_rkArgL,const LmVec4& ac_rkArgR)
{
	a_rkArgOut.x = ac_rkArgL.x - ac_rkArgR.x;
	a_rkArgOut.y = ac_rkArgL.y - ac_rkArgR.y;
	a_rkArgOut.z = ac_rkArgL.z - ac_rkArgR.z;
	a_rkArgOut.w = ac_rkArgL.w - ac_rkArgR.w;
}

void std_lmVec4Mul(LmVec4& a_rkArgOut,const LmVec4& ac_rkArgL,const float ac_fArgR)
{
	a_rkArgOut.x = ac_rkArgL.x * ac_fArgR;
	a_rkArgOut.y = ac_rkArgL.y * ac_fArgR;
	a_rkArgOut.z = ac_rkArgL.z * ac_fArgR;
	a_rkArgOut.w = ac_rkArgL.w * ac_fArgR;
}

void std_lmVec4Div(LmVec4& a_rkArgOut,const LmVec4& ac_rkArgL,const float ac_fArgR)
{
	a_rkArgOut.x = ac_rkArgL.x / ac_fArgR;
	a_rkArgOut.y = ac_rkArgL.y / ac_fArgR;
	a_rkArgOut.z = ac_rkArgL.z / ac_fArgR;
	a_rkArgOut.w = ac_rkArgL.w / ac_fArgR;
}

void std_lmVec4Negative(LmVec4& a_rkArgOut,const LmVec4& ac_rkArgL)
{
	a_rkArgOut.x = -ac_rkArgL.x;
	a_rkArgOut.y = -ac_rkArgL.y;
	a_rkArgOut.z = -ac_rkArgL.z;
	a_rkArgOut.w = -ac_rkArgL.w;
}

bool std_lmVec4Equals(const LmVec4& ac_rkArgL,const LmVec4& ac_rkArgR)
{
	return ac_rkArgL.x == ac_rkArgR.x &&
		ac_rkArgL.y == ac_rkArgR.y &&
		ac_rkArgL.z == ac_rkArgR.z &&
		ac_rkArgL.w == ac_rkArgR.w;
}

bool std_lmVec4NotEquals(const LmVec4& ac_rkArgL,const LmVec4& ac_rkArgR)
{
	return ac_rkArgL.x != ac_rkArgR.x &&
		ac_rkArgL.y != ac_rkArgR.y &&
		ac_rkArgL.z != ac_rkArgR.z &&
		ac_rkArgL.w != ac_rkArgR.w;
}

float std_lmVec4DotProduct(const LmVec4& ac_rkArgL,const LmVec4& ac_rkArgR)
{
	return ac_rkArgL.x * ac_rkArgR.x +
		ac_rkArgL.y * ac_rkArgR.y +
		ac_rkArgL.z * ac_rkArgR.z;
}

float std_lmVec4Length(const LmVec4& ac_rkArgL)
{
	return lmSqrt(ac_rkArgL.x * ac_rkArgL.x + 
		ac_rkArgL.y * ac_rkArgL.y + 
		ac_rkArgL.z * ac_rkArgL.z);
}

float std_lmVec4LengthSqr(const LmVec4& ac_rkArgL)
{
	return ac_rkArgL.x * ac_rkArgL.x + 
		ac_rkArgL.y * ac_rkArgL.y + 
		ac_rkArgL.z * ac_rkArgL.z;
}

void std_lmVec4Normalise(LmVec4& a_rkArgOut,const LmVec4& ac_rkArgL)
{
	float fLength = ac_rkArgL.Length();
	a_rkArgOut.x = ac_rkArgL.x / fLength;
	a_rkArgOut.y = ac_rkArgL.y / fLength;
	a_rkArgOut.z = ac_rkArgL.z / fLength;
}

void std_lmVec4Maximise(LmVec4& a_rkArgOut,const LmVec4& ac_rkArgL)
{
	float fHighest = ac_rkArgL.x;
	for(unsigned int i = 1;i < 4;i++)
	{
		if(ac_rkArgL[i] > fHighest)
			fHighest = ac_rkArgL[i];
	}
	a_rkArgOut.Set(fHighest,fHighest,fHighest,fHighest);
}

void std_lmVec4Minimise(LmVec4& a_rkArgOut,const LmVec4& ac_rkArgL)
{
	float fLowest = ac_rkArgL.x;
	for(unsigned int i = 1;i < 4;i++)
	{
		if(ac_rkArgL[i] < fLowest)
			fLowest = ac_rkArgL[i];
	}
	a_rkArgOut.Set(fLowest,fLowest,fLowest,fLowest);
}

void std_lmVec4CrossProduct(LmVec4& a_rkArgOut,const LmVec4& ac_rkArgL,const LmVec4& ac_rkArgR)
{
	a_rkArgOut.Set((ac_rkArgL.y * ac_rkArgR.z) - (ac_rkArgL.z * ac_rkArgR.y),
		(ac_rkArgL.z * ac_rkArgR.x) - (ac_rkArgL.x* ac_rkArgR.z),
		(ac_rkArgL.x * ac_rkArgR.y) - (ac_rkArgL.y * ac_rkArgR.x));
}

extern void ispc_lmVec4Add(LmVec4&,const LmVec4&,const LmVec4&);

//bool(const LmVec4&, const LmVec4&)
lmVec4_Bool_CVec4_CVec4 LmVec4Equals = nullptr;
lmVec4_Bool_CVec4_CVec4 LmVec4NotEquals = nullptr;

//void (LmVec4&, const LmVec4&)
lmVec4_Void_Vec4_CVec4 LmVec4Normalise = nullptr;
lmVec4_Void_Vec4_CVec4 LmVec4Maximise = nullptr;
lmVec4_Void_Vec4_CVec4 LmVec4Minimise = nullptr;
lmVec4_Void_Vec4_CVec4 LmVec4Negative = nullptr;

//void (LmVec4&, const LmVec4&, float)
lmVec4_Void_Vec4_CVec4_Float LmVec4Mul = nullptr;
lmVec4_Void_Vec4_CVec4_Float LmVec4Div = nullptr;

//void (LmVec4&, const LmVec4&, const LmVec4&)
lmVec4_Void_Vec4_CVec4_CVec4 LmVec4Add = nullptr;
lmVec4_Void_Vec4_CVec4_CVec4 LmVec4Sub = nullptr;
lmVec4_Void_Vec4_CVec4_CVec4 LmVec4CrossProduct = nullptr;

//float (const LmVec4&)
lmVec4_Float_CVec4 LmVec4Length = nullptr;
lmVec4_Float_CVec4 LmVec4LengthSqr = nullptr;

//float (cosnt LmVec4&, const LmVec4&)
lmVec4_Float_CVec4_CVec4 LmVec4DotProduct = nullptr;

void LmVec4::Construct()
{
	LmVec4Equals = &std_lmVec4Equals;
	LmVec4NotEquals = &std_lmVec4NotEquals;

	LmVec4Normalise = &std_lmVec4Normalise;
	LmVec4Maximise = &std_lmVec4Maximise;
	LmVec4Minimise = &std_lmVec4Minimise;
	LmVec4Negative = &std_lmVec4Negative;

	LmVec4Mul = &std_lmVec4Mul;
	LmVec4Div = &std_lmVec4Div;

	LmVec4Add = &std_lmVec4Add;
	LmVec4Sub = &std_lmVec4Sub;
	
	LmVec4Length = &std_lmVec4Length;
	LmVec4LengthSqr = &std_lmVec4LengthSqr;

	LmVec4DotProduct = &std_lmVec4DotProduct;
	LmVec4CrossProduct = &std_lmVec4CrossProduct;
}