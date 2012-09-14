#include "lmVec4.h"
#include "../lmCore.h"

using namespace Labyrinth;

const lmVec4 lmVec4::ZERO = lmVec4(0,0,0,1);
const lmVec4 lmVec4::POSX = lmVec4(1,0,0,1);
const lmVec4 lmVec4::POSY = lmVec4(0,1,0,1);
const lmVec4 lmVec4::POSZ = lmVec4(0,0,1,1);
const lmVec4 lmVec4::NEGX = lmVec4(-1,0,0,1);
const lmVec4 lmVec4::NEGY = lmVec4(0,-1,0,1);
const lmVec4 lmVec4::NEGZ = lmVec4(0,0,-1,1);

void std_lmVec4Add(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL,const lmVec4& ac_rkArgR)
{
	a_rkArgOut.x = ac_rkArgL.x + ac_rkArgR.x;
	a_rkArgOut.y = ac_rkArgL.y + ac_rkArgR.y;
	a_rkArgOut.z = ac_rkArgL.z + ac_rkArgR.z;
	a_rkArgOut.w = ac_rkArgL.w + ac_rkArgR.w;
}

void std_lmVec4Sub(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL,const lmVec4& ac_rkArgR)
{
	a_rkArgOut.x = ac_rkArgL.x - ac_rkArgR.x;
	a_rkArgOut.y = ac_rkArgL.y - ac_rkArgR.y;
	a_rkArgOut.z = ac_rkArgL.z - ac_rkArgR.z;
	a_rkArgOut.w = ac_rkArgL.w - ac_rkArgR.w;
}

void std_lmVec4Mul(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL,const float ac_fArgR)
{
	a_rkArgOut.x = ac_rkArgL.x * ac_fArgR;
	a_rkArgOut.y = ac_rkArgL.y * ac_fArgR;
	a_rkArgOut.z = ac_rkArgL.z * ac_fArgR;
	a_rkArgOut.w = ac_rkArgL.w * ac_fArgR;
}

void std_lmVec4Div(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL,const float ac_fArgR)
{
	a_rkArgOut.x = ac_rkArgL.x / ac_fArgR;
	a_rkArgOut.y = ac_rkArgL.y / ac_fArgR;
	a_rkArgOut.z = ac_rkArgL.z / ac_fArgR;
	a_rkArgOut.w = ac_rkArgL.w / ac_fArgR;
}

void std_lmVec4Negative(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL)
{
	a_rkArgOut.x = -ac_rkArgL.x;
	a_rkArgOut.y = -ac_rkArgL.y;
	a_rkArgOut.z = -ac_rkArgL.z;
	a_rkArgOut.w = -ac_rkArgL.w;
}

bool std_lmVec4Equals(const lmVec4& ac_rkArgL,const lmVec4& ac_rkArgR)
{
	return ac_rkArgL.x == ac_rkArgR.x &&
		ac_rkArgL.y == ac_rkArgR.y &&
		ac_rkArgL.z == ac_rkArgR.z &&
		ac_rkArgL.w == ac_rkArgR.w;
}

bool std_lmVec4NotEquals(const lmVec4& ac_rkArgL,const lmVec4& ac_rkArgR)
{
	return ac_rkArgL.x != ac_rkArgR.x &&
		ac_rkArgL.y != ac_rkArgR.y &&
		ac_rkArgL.z != ac_rkArgR.z &&
		ac_rkArgL.w != ac_rkArgR.w;
}

float std_lmVec4DotProduct(const lmVec4& ac_rkArgL,const lmVec4& ac_rkArgR)
{
	return ac_rkArgL.x * ac_rkArgR.x +
		ac_rkArgL.y * ac_rkArgR.y +
		ac_rkArgL.z * ac_rkArgR.z +
		ac_rkArgL.w * ac_rkArgR.w;
}

float std_lmVec4Length(const lmVec4& ac_rkArgL)
{
	return lmSqrt(ac_rkArgL.x * ac_rkArgL.x + 
		ac_rkArgL.y * ac_rkArgL.y + 
		ac_rkArgL.z * ac_rkArgL.z + 
		ac_rkArgL.w * ac_rkArgL.w);
}

float std_lmVec4LengthSqr(const lmVec4& ac_rkArgL)
{
	return ac_rkArgL.x * ac_rkArgL.x + 
		ac_rkArgL.y * ac_rkArgL.y + 
		ac_rkArgL.z * ac_rkArgL.z + 
		ac_rkArgL.w * ac_rkArgL.w;
}

void std_lmVec4Normalise(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL)
{
	float fLength = ac_rkArgL.Length();
	a_rkArgOut = ac_rkArgL / fLength;
}

void std_lmVec4Maximise(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL)
{
	float fHighest = ac_rkArgL.x;
	for(unsigned int i = 1;i < 4;i++)
	{
		if(ac_rkArgL[i] > fHighest)
			fHighest = ac_rkArgL[i];
	}
	a_rkArgOut.Set(fHighest,fHighest,fHighest,fHighest);
}

void std_lmVec4Minimise(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL)
{
	float fLowest = ac_rkArgL.x;
	for(unsigned int i = 1;i < 4;i++)
	{
		if(ac_rkArgL[i] < fLowest)
			fLowest = ac_rkArgL[i];
	}
	a_rkArgOut.Set(fLowest,fLowest,fLowest,fLowest);
}

//bool(const lmVec4&, const lmVec4&)
lmVec4_Bool_CVec4_CVec4 Labyrinth::lmVec4Equals = nullptr;
lmVec4_Bool_CVec4_CVec4 Labyrinth::lmVec4NotEquals = nullptr;

//void (lmVec4&, const lmVec4&)
lmVec4_Void_Vec4_CVec4 Labyrinth::lmVec4Normalise = nullptr;
lmVec4_Void_Vec4_CVec4 Labyrinth::lmVec4Maximise = nullptr;
lmVec4_Void_Vec4_CVec4 Labyrinth::lmVec4Minimise = nullptr;
lmVec4_Void_Vec4_CVec4 Labyrinth::lmVec4Negative = nullptr;

//void (lmVec4&, const lmVec4&, float)
lmVec4_Void_Vec4_CVec4_Float Labyrinth::lmVec4Mul = nullptr;
lmVec4_Void_Vec4_CVec4_Float Labyrinth::lmVec4Div = nullptr;

//void (lmVec4&, const lmVec4&, const lmVec4&)
lmVec4_Void_Vec4_CVec4_CVec4 Labyrinth::lmVec4Add = nullptr;
lmVec4_Void_Vec4_CVec4_CVec4 Labyrinth::lmVec4Sub = nullptr;

//float (const lmVec4&)
lmVec4_Float_CVec4 Labyrinth::lmVec4Length = nullptr;
lmVec4_Float_CVec4 Labyrinth::lmVec4LengthSqr = nullptr;

//float (cosnt lmVec4&, const lmVec4&)
lmVec4_Float_CVec4_CVec4 Labyrinth::lmVec4DotProduct = nullptr;

void lmVec4::Construct()
{
	lmVec4Equals = &std_lmVec4Equals;
	lmVec4NotEquals = &std_lmVec4NotEquals;

	lmVec4Normalise = &std_lmVec4Normalise;
	lmVec4Maximise = &std_lmVec4Maximise;
	lmVec4Minimise = &std_lmVec4Minimise;
	lmVec4Negative = &std_lmVec4Negative;

	lmVec4Mul = &std_lmVec4Mul;
	lmVec4Div = &std_lmVec4Div;

	lmVec4Add = &std_lmVec4Add;
	lmVec4Sub = &std_lmVec4Sub;
	
	lmVec4Length = &std_lmVec4Length;
	lmVec4LengthSqr = &std_lmVec4LengthSqr;

	lmVec4DotProduct = &std_lmVec4DotProduct;
}