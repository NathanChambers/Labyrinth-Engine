#include "lmVec3.h"
#include "../lmCore/lmCore.h"

#include <math.h>

using namespace Labyrinth;

const lmVec3 lmVec3::ZERO = lmVec3(0,0,0);
const lmVec3 lmVec3::POSX = lmVec3(1,0,0);
const lmVec3 lmVec3::POSY = lmVec3(0,1,0);
const lmVec3 lmVec3::POSZ = lmVec3(0,0,1);
const lmVec3 lmVec3::NEGX = lmVec3(-1,0,0);
const lmVec3 lmVec3::NEGY = lmVec3(0,-1,0);
const lmVec3 lmVec3::NEGZ = lmVec3(0,0,-1);

void std_lmVec3Add(lmVec3& a_rkArgOut,const lmVec3& ac_rkArgL,const lmVec3& ac_rkArgR)
{
	a_rkArgOut.x = ac_rkArgL.x + ac_rkArgR.x;
	a_rkArgOut.y = ac_rkArgL.y + ac_rkArgR.y;
	a_rkArgOut.z = ac_rkArgL.z + ac_rkArgR.z;
}

void std_lmVec3Sub(lmVec3& a_rkArgOut,const lmVec3& ac_rkArgL,const lmVec3& ac_rkArgR)
{
	a_rkArgOut.x = ac_rkArgL.x - ac_rkArgR.x;
	a_rkArgOut.y = ac_rkArgL.y - ac_rkArgR.y;
	a_rkArgOut.z = ac_rkArgL.z - ac_rkArgR.z;
}

void std_lmVec3Mul(lmVec3& a_rkArgOut,const lmVec3& ac_rkArgL,const float ac_fArgR)
{
	a_rkArgOut.x = ac_rkArgL.x * ac_fArgR;
	a_rkArgOut.y = ac_rkArgL.y * ac_fArgR;
	a_rkArgOut.z = ac_rkArgL.z * ac_fArgR;
}

void std_lmVec3Div(lmVec3& a_rkArgOut,const lmVec3& ac_rkArgL,const float ac_fArgR)
{
	a_rkArgOut.x = ac_rkArgL.x / ac_fArgR;
	a_rkArgOut.y = ac_rkArgL.y / ac_fArgR;
	a_rkArgOut.z = ac_rkArgL.z / ac_fArgR;
}

void std_lmVec3Negative(lmVec3& a_rkArgOut,const lmVec3& ac_rkArgL)
{
	a_rkArgOut.x = -ac_rkArgL.x;
	a_rkArgOut.y = -ac_rkArgL.y;
	a_rkArgOut.z = -ac_rkArgL.z;
}

bool std_lmVec3Equals(const lmVec3& ac_rkArgL,const lmVec3& ac_rkArgR)
{
	return ac_rkArgL.x == ac_rkArgR.x &&
		ac_rkArgL.y == ac_rkArgR.y &&
		ac_rkArgL.z == ac_rkArgR.z;
}

bool std_lmVec3NotEquals(const lmVec3& ac_rkArgL,const lmVec3& ac_rkArgR)
{
	return ac_rkArgL.x != ac_rkArgR.x &&
		ac_rkArgL.y != ac_rkArgR.y &&
		ac_rkArgL.z != ac_rkArgR.z;
}

float std_lmVec3DotProduct(const lmVec3& ac_rkArgL,const lmVec3& ac_rkArgR)
{
	return ac_rkArgL.x * ac_rkArgR.x +
		ac_rkArgL.y * ac_rkArgR.y +
		ac_rkArgL.z * ac_rkArgR.z;
}

float std_lmVec3Length(const lmVec3& ac_rkArgL)
{
	return sqrt(ac_rkArgL.x * ac_rkArgL.x + 
		ac_rkArgL.y * ac_rkArgL.y + 
		ac_rkArgL.z * ac_rkArgL.z);
}

float std_lmVec3LengthSqr(const lmVec3& ac_rkArgL)
{
	return ac_rkArgL.x * ac_rkArgL.x + 
		ac_rkArgL.y * ac_rkArgL.y + 
		ac_rkArgL.z * ac_rkArgL.z;
}

void std_lmVec3Normalise(lmVec3& a_rkArgOut,const lmVec3& ac_rkArgL)
{
	float fLength = ac_rkArgL.Length();
	a_rkArgOut.x = ac_rkArgL.x / fLength;
	a_rkArgOut.y = ac_rkArgL.y / fLength;
	a_rkArgOut.z = ac_rkArgL.z / fLength;
}

void std_lmVec3Maximise(lmVec3& a_rkArgOut,const lmVec3& ac_rkArgL)
{
	float fHighest = ac_rkArgL.x;
	for(unsigned int i = 1;i < 4;i++)
	{
		if(ac_rkArgL[i] > fHighest)
			fHighest = ac_rkArgL[i];
	}
	a_rkArgOut.Set(fHighest,fHighest,fHighest);
}

void std_lmVec3Minimise(lmVec3& a_rkArgOut,const lmVec3& ac_rkArgL)
{
	float fLowest = ac_rkArgL.x;
	for(unsigned int i = 1;i < 4;i++)
	{
		if(ac_rkArgL[i] < fLowest)
			fLowest = ac_rkArgL[i];
	}
	a_rkArgOut.Set(fLowest,fLowest,fLowest);
}

//bool(const lmVec3&, const lmVec3&)
lmVec3_Bool_CVec3_CVec3 Labyrinth::lmVec3Equals = nullptr;
lmVec3_Bool_CVec3_CVec3 Labyrinth::lmVec3NotEquals = nullptr;

//void (lmVec3&, const lmVec3&)
lmVec3_Void_Vec3_CVec3 Labyrinth::lmVec3Normalise = nullptr;
lmVec3_Void_Vec3_CVec3 Labyrinth::lmVec3Maximise = nullptr;
lmVec3_Void_Vec3_CVec3 Labyrinth::lmVec3Minimise = nullptr;
lmVec3_Void_Vec3_CVec3 Labyrinth::lmVec3Negative = nullptr;

//void (lmVec3&, const lmVec3&, float)
lmVec3_Void_Vec3_CVec3_Float Labyrinth::lmVec3Mul = nullptr;
lmVec3_Void_Vec3_CVec3_Float Labyrinth::lmVec3Div = nullptr;

//void (lmVec3&, const lmVec3&, const lmVec3&)
lmVec3_Void_Vec3_CVec3_CVec3 Labyrinth::lmVec3Add = nullptr;
lmVec3_Void_Vec3_CVec3_CVec3 Labyrinth::lmVec3Sub = nullptr;

//float (const lmVec3&)
lmVec3_Float_CVec3 Labyrinth::lmVec3Length = nullptr;
lmVec3_Float_CVec3 Labyrinth::lmVec3LengthSqr = nullptr;

//float (cosnt lmVec3&, const lmVec3&)
lmVec3_Float_CVec3_CVec3 Labyrinth::lmVec3DotProduct = nullptr;

void lmVec3::Construct()
{
	lmVec3Equals = &std_lmVec3Equals;
	lmVec3NotEquals = &std_lmVec3NotEquals;

	lmVec3Normalise = &std_lmVec3Normalise;
	lmVec3Maximise = &std_lmVec3Maximise;
	lmVec3Minimise = &std_lmVec3Minimise;
	lmVec3Negative = &std_lmVec3Negative;

	lmVec3Mul = &std_lmVec3Mul;
	lmVec3Div = &std_lmVec3Div;

	lmVec3Add = &std_lmVec3Add;
	lmVec3Sub = &std_lmVec3Sub;
	
	lmVec3Length = &std_lmVec3Length;
	lmVec3LengthSqr = &std_lmVec3LengthSqr;

	lmVec3DotProduct = &std_lmVec3DotProduct;
}