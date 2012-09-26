#include "LmVec3.h"
#include "lmCore.h"

const LmVec3 LmVec3::ZERO = LmVec3(0,0,0);
const LmVec3 LmVec3::POSX = LmVec3(1,0,0);
const LmVec3 LmVec3::POSY = LmVec3(0,1,0);
const LmVec3 LmVec3::POSZ = LmVec3(0,0,1);
const LmVec3 LmVec3::NEGX = LmVec3(-1,0,0);
const LmVec3 LmVec3::NEGY = LmVec3(0,-1,0);
const LmVec3 LmVec3::NEGZ = LmVec3(0,0,-1);

void std_lmVec3Add(LmVec3& a_rkArgOut,const LmVec3& ac_rkArgL,const LmVec3& ac_rkArgR)
{
	a_rkArgOut.x = ac_rkArgL.x + ac_rkArgR.x;
	a_rkArgOut.y = ac_rkArgL.y + ac_rkArgR.y;
	a_rkArgOut.z = ac_rkArgL.z + ac_rkArgR.z;
}

void std_lmVec3Sub(LmVec3& a_rkArgOut,const LmVec3& ac_rkArgL,const LmVec3& ac_rkArgR)
{
	a_rkArgOut.x = ac_rkArgL.x - ac_rkArgR.x;
	a_rkArgOut.y = ac_rkArgL.y - ac_rkArgR.y;
	a_rkArgOut.z = ac_rkArgL.z - ac_rkArgR.z;
}

void std_lmVec3Mul(LmVec3& a_rkArgOut,const LmVec3& ac_rkArgL,const float ac_fArgR)
{
	a_rkArgOut.x = ac_rkArgL.x * ac_fArgR;
	a_rkArgOut.y = ac_rkArgL.y * ac_fArgR;
	a_rkArgOut.z = ac_rkArgL.z * ac_fArgR;
}

void std_lmVec3Div(LmVec3& a_rkArgOut,const LmVec3& ac_rkArgL,const float ac_fArgR)
{
	a_rkArgOut.x = ac_rkArgL.x / ac_fArgR;
	a_rkArgOut.y = ac_rkArgL.y / ac_fArgR;
	a_rkArgOut.z = ac_rkArgL.z / ac_fArgR;
}

void std_lmVec3Negative(LmVec3& a_rkArgOut,const LmVec3& ac_rkArgL)
{
	a_rkArgOut.x = -ac_rkArgL.x;
	a_rkArgOut.y = -ac_rkArgL.y;
	a_rkArgOut.z = -ac_rkArgL.z;
}

bool std_lmVec3Equals(const LmVec3& ac_rkArgL,const LmVec3& ac_rkArgR)
{
	return ac_rkArgL.x == ac_rkArgR.x &&
		ac_rkArgL.y == ac_rkArgR.y &&
		ac_rkArgL.z == ac_rkArgR.z;
}

bool std_lmVec3NotEquals(const LmVec3& ac_rkArgL,const LmVec3& ac_rkArgR)
{
	return ac_rkArgL.x != ac_rkArgR.x &&
		ac_rkArgL.y != ac_rkArgR.y &&
		ac_rkArgL.z != ac_rkArgR.z;
}

float std_lmVec3DotProduct(const LmVec3& ac_rkArgL,const LmVec3& ac_rkArgR)
{
	return ac_rkArgL.x * ac_rkArgR.x +
		ac_rkArgL.y * ac_rkArgR.y +
		ac_rkArgL.z * ac_rkArgR.z;
}

float std_lmVec3Length(const LmVec3& ac_rkArgL)
{
	return lmSqrt(ac_rkArgL.x * ac_rkArgL.x + 
		ac_rkArgL.y * ac_rkArgL.y + 
		ac_rkArgL.z * ac_rkArgL.z);
}

float std_lmVec3LengthSqr(const LmVec3& ac_rkArgL)
{
	return ac_rkArgL.x * ac_rkArgL.x + 
		ac_rkArgL.y * ac_rkArgL.y + 
		ac_rkArgL.z * ac_rkArgL.z;
}

void std_lmVec3Normalise(LmVec3& a_rkArgOut,const LmVec3& ac_rkArgL)
{
	float fLength = ac_rkArgL.Length();
	a_rkArgOut.x = ac_rkArgL.x / fLength;
	a_rkArgOut.y = ac_rkArgL.y / fLength;
	a_rkArgOut.z = ac_rkArgL.z / fLength;
}

void std_lmVec3Maximise(LmVec3& a_rkArgOut,const LmVec3& ac_rkArgL)
{
	float fHighest = ac_rkArgL.x;
	for(unsigned int i = 1;i < 3;i++)
	{
		if(ac_rkArgL[i] > fHighest)
			fHighest = ac_rkArgL[i];
	}
	a_rkArgOut.Set(fHighest,fHighest,fHighest);
}

void std_lmVec3Minimise(LmVec3& a_rkArgOut,const LmVec3& ac_rkArgL)
{
	float fLowest = ac_rkArgL.x;
	for(unsigned int i = 1;i < 3;i++)
	{
		if(ac_rkArgL[i] < fLowest)
			fLowest = ac_rkArgL[i];
	}
	a_rkArgOut.Set(fLowest,fLowest,fLowest);
}

void std_lmVec3CrossProduct(LmVec3& a_rkArgOut,const LmVec3& ac_rkArgL,const LmVec3& ac_rkArgR)
{
	a_rkArgOut.Set((ac_rkArgL.y * ac_rkArgR.z) - (ac_rkArgL.z * ac_rkArgR.y),
		(ac_rkArgL.z * ac_rkArgR.x) - (ac_rkArgL.x* ac_rkArgR.z),
		(ac_rkArgL.x * ac_rkArgR.y) - (ac_rkArgL.y * ac_rkArgR.x));
}

//bool(const LmVec3&, const LmVec3&)
lmVec3_Bool_CVec3_CVec3 LmVec3Equals = nullptr;
lmVec3_Bool_CVec3_CVec3 LmVec3NotEquals = nullptr;

//void (LmVec3&, const LmVec3&)
lmVec3_Void_Vec3_CVec3 LmVec3Normalise = nullptr;
lmVec3_Void_Vec3_CVec3 LmVec3Maximise = nullptr;
lmVec3_Void_Vec3_CVec3 LmVec3Minimise = nullptr;
lmVec3_Void_Vec3_CVec3 LmVec3Negative = nullptr;

//void (LmVec3&, const LmVec3&, float)
lmVec3_Void_Vec3_CVec3_Float LmVec3Mul = nullptr;
lmVec3_Void_Vec3_CVec3_Float LmVec3Div = nullptr;

//void (LmVec3&, const LmVec3&, const LmVec3&)
lmVec3_Void_Vec3_CVec3_CVec3 LmVec3Add = nullptr;
lmVec3_Void_Vec3_CVec3_CVec3 LmVec3Sub = nullptr;
lmVec3_Void_Vec3_CVec3_CVec3 LmVec3CrossProduct = nullptr;

//float (const LmVec3&)
lmVec3_Float_CVec3 LmVec3Length = nullptr;
lmVec3_Float_CVec3 LmVec3LengthSqr = nullptr;

//float (cosnt LmVec3&, const LmVec3&)
lmVec3_Float_CVec3_CVec3 LmVec3DotProduct = nullptr;

void LmVec3::Construct()
{
	LmVec3Equals = &std_lmVec3Equals;
	LmVec3NotEquals = &std_lmVec3NotEquals;

	LmVec3Normalise = &std_lmVec3Normalise;
	LmVec3Maximise = &std_lmVec3Maximise;
	LmVec3Minimise = &std_lmVec3Minimise;
	LmVec3Negative = &std_lmVec3Negative;

	LmVec3Mul = &std_lmVec3Mul;
	LmVec3Div = &std_lmVec3Div;

	LmVec3Add = &std_lmVec3Add;
	LmVec3Sub = &std_lmVec3Sub;
	
	LmVec3Length = &std_lmVec3Length;
	LmVec3LengthSqr = &std_lmVec3LengthSqr;

	LmVec3DotProduct = &std_lmVec3DotProduct;
	LmVec3CrossProduct = &std_lmVec3CrossProduct;
}