#include "lmVec3.h"
#include "lmCore.h"

const lmVec3 lmVec3::ZERO = lmVec3(0,0,0);
const lmVec3 lmVec3::POSX = lmVec3(1,0,0);
const lmVec3 lmVec3::POSY = lmVec3(0,1,0);
const lmVec3 lmVec3::POSZ = lmVec3(0,0,1);
const lmVec3 lmVec3::NEGX = lmVec3(-1,0,0);
const lmVec3 lmVec3::NEGY = lmVec3(0,-1,0);
const lmVec3 lmVec3::NEGZ = lmVec3(0,0,-1);

////////////////////////////////////////////////////////////////////////////////

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
	return lmSqrt(ac_rkArgL.x * ac_rkArgL.x + 
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
	for(unsigned int i = 1;i < 3;i++)
	{
		if(ac_rkArgL[i] > fHighest)
			fHighest = ac_rkArgL[i];
	}
	a_rkArgOut.Set(fHighest,fHighest,fHighest);
}

void std_lmVec3Minimise(lmVec3& a_rkArgOut,const lmVec3& ac_rkArgL)
{
	float fLowest = ac_rkArgL.x;
	for(unsigned int i = 1;i < 3;i++)
	{
		if(ac_rkArgL[i] < fLowest)
			fLowest = ac_rkArgL[i];
	}
	a_rkArgOut.Set(fLowest,fLowest,fLowest);
}

void std_lmVec3CrossProduct(lmVec3& a_rkArgOut,const lmVec3& ac_rkArgL,const lmVec3& ac_rkArgR)
{
	a_rkArgOut.Set((ac_rkArgL.y * ac_rkArgR.z) - (ac_rkArgL.z * ac_rkArgR.y),
		(ac_rkArgL.z * ac_rkArgR.x) - (ac_rkArgL.x* ac_rkArgR.z),
		(ac_rkArgL.x * ac_rkArgR.y) - (ac_rkArgL.y * ac_rkArgR.x));
}

////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
extern "C" 
{
	#endif // __cplusplus
		extern void ispcVec3Add(float* a_pkArgOut,const float* ac_pkArgL,const float* ac_pkArgR);
		extern void ispcVec3Sub(float* a_pkArgOut,const float* ac_pkArgL,const float* ac_pkArgR);
		extern void ispcVec3Mul(float* a_pkArgOut,const float* ac_pkArgL,const float ac_fArgR);
		extern void ispcVec3Div(float* a_pkArgOut,const float* ac_pkArgL,const float ac_fArgR);
		extern void ispcVec3Negative(float* a_pkArgOut,const float* ac_pkArgL);
		extern bool ispcVec3Equals(const float* ac_pkArgL,const float* ac_pkArgR);
		extern bool ispcVec3NotEquals(const float* ac_pkArgL,const float* ac_pkArgR);
		extern float ispcVec3DotProduct(const float* ac_pkArgL,const float* ac_pkArgR);
		extern float ispcVec3Length(const float* ac_pkArgL);
		extern float ispcVec3LengthSqr(const float* ac_pkArgL);
		extern void ispcVec3Normalise(float* a_pkArgOut,const float* ac_pkArgL);
		extern void ispcVec3Maximise(float* a_pkArgOut,const float* ac_pkArgL);
		extern void ispcVec3Minimise(float* a_pkArgOut,const float* ac_pkArgL);
		extern void ispcVec3CrossProduct(float* a_pkArgOut,const float* ac_pkArgL,const float* ac_pkArgR);
	#ifdef __cplusplus
}
#endif // __cplusplus

void ispc_lmVec3Add(lmVec3& a_rkArgOut,const lmVec3& ac_rkArgL,const lmVec3& ac_rkArgR)
{
	ispcVec3Add(a_rkArgOut,ac_rkArgL,ac_rkArgR);
}

void ispc_lmVec3Sub(lmVec3& a_rkArgOut,const lmVec3& ac_rkArgL,const lmVec3& ac_rkArgR)
{
	ispcVec3Sub(a_rkArgOut,ac_rkArgL,ac_rkArgR);
}

void ispc_lmVec3Mul(lmVec3& a_rkArgOut,const lmVec3& ac_rkArgL,const float ac_fArgR)
{
	ispcVec3Mul(a_rkArgOut,ac_rkArgL,ac_fArgR);
}

void ispc_lmVec3Div(lmVec3& a_rkArgOut,const lmVec3& ac_rkArgL,const float ac_fArgR)
{
	ispcVec3Div(a_rkArgOut,ac_rkArgL,ac_fArgR);
}

void ispc_lmVec3Negative(lmVec3& a_rkArgOut,const lmVec3& ac_rkArgL)
{
	ispcVec3Negative(a_rkArgOut,ac_rkArgL);
}

bool ispc_lmVec3Equals(const lmVec3& ac_rkArgL,const lmVec3& ac_rkArgR)
{
	return ispcVec3Equals(ac_rkArgL,ac_rkArgR);
}

bool ispc_lmVec3NotEquals(const lmVec3& ac_rkArgL,const lmVec3& ac_rkArgR)
{
	return ispcVec3NotEquals(ac_rkArgL,ac_rkArgR);
}

float ispc_lmVec3DotProduct(const lmVec3& ac_rkArgL,const lmVec3& ac_rkArgR)
{
	return ispcVec3DotProduct(ac_rkArgL,ac_rkArgR);
}

float ispc_lmVec3Length(const lmVec3& ac_rkArgL)
{
	return ispcVec3Length(ac_rkArgL);
}

float ispc_lmVec3LengthSqr(const lmVec3& ac_rkArgL)
{
	return ispcVec3LengthSqr(ac_rkArgL);
}

void ispc_lmVec3Normalise(lmVec3& a_rkArgOut,const lmVec3& ac_rkArgL)
{
	ispcVec3Normalise(a_rkArgOut,ac_rkArgL);
}

void ispc_lmVec3Maximise(lmVec3& a_rkArgOut,const lmVec3& ac_rkArgL)
{
	ispcVec3Maximise(a_rkArgOut,ac_rkArgL);
}

void ispc_lmVec3Minimise(lmVec3& a_rkArgOut,const lmVec3& ac_rkArgL)
{
	ispcVec3Minimise(a_rkArgOut,ac_rkArgL);
}

void ispc_lmVec3CrossProduct(lmVec3& a_rkArgOut,const lmVec3& ac_rkArgL,const lmVec3& ac_rkArgR)
{
	ispcVec3CrossProduct(a_rkArgOut,ac_rkArgL,ac_rkArgR);
}

////////////////////////////////////////////////////////////////////////////////

//bool(const lmVec3&, const lmVec3&)
lmVec3_Bool_CVec3_CVec3 lmVec3Equals = nullptr;
lmVec3_Bool_CVec3_CVec3 lmVec3NotEquals = nullptr;

//void (lmVec3&, const lmVec3&)
lmVec3_Void_Vec3_CVec3 lmVec3Normalise = nullptr;
lmVec3_Void_Vec3_CVec3 lmVec3Maximise = nullptr;
lmVec3_Void_Vec3_CVec3 lmVec3Minimise = nullptr;
lmVec3_Void_Vec3_CVec3 lmVec3Negative = nullptr;

//void (lmVec3&, const lmVec3&, float)
lmVec3_Void_Vec3_CVec3_Float lmVec3Mul = nullptr;
lmVec3_Void_Vec3_CVec3_Float lmVec3Div = nullptr;

//void (lmVec3&, const lmVec3&, const lmVec3&)
lmVec3_Void_Vec3_CVec3_CVec3 lmVec3Add = nullptr;
lmVec3_Void_Vec3_CVec3_CVec3 lmVec3Sub = nullptr;
lmVec3_Void_Vec3_CVec3_CVec3 lmVec3CrossProduct = nullptr;

//float (const lmVec3&)
lmVec3_Float_CVec3 lmVec3Length = nullptr;
lmVec3_Float_CVec3 lmVec3LengthSqr = nullptr;

//float (cosnt lmVec3&, const lmVec3&)
lmVec3_Float_CVec3_CVec3 lmVec3DotProduct = nullptr;

void lmVec3::Construct()
{
	switch(lmGetIntrinsic())
	{
	case LM_INTRIN_STD:
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
			lmVec3CrossProduct = &std_lmVec3CrossProduct;
			break;
		}

	case LM_INTRIN_ISPC:
		{
			lmVec3Equals = &ispc_lmVec3Equals;
			lmVec3NotEquals = &ispc_lmVec3NotEquals;

			lmVec3Normalise = &ispc_lmVec3Normalise;
			lmVec3Maximise = &ispc_lmVec3Maximise;
			lmVec3Minimise = &ispc_lmVec3Minimise;
			lmVec3Negative = &ispc_lmVec3Negative;

			lmVec3Mul = &ispc_lmVec3Mul;
			lmVec3Div = &ispc_lmVec3Div;

			lmVec3Add = &ispc_lmVec3Add;
			lmVec3Sub = &ispc_lmVec3Sub;
	
			lmVec3Length = &ispc_lmVec3Length;
			lmVec3LengthSqr = &ispc_lmVec3LengthSqr;

			lmVec3DotProduct = &ispc_lmVec3DotProduct;
			lmVec3CrossProduct = &ispc_lmVec3CrossProduct;
			break;
		}
	default:
		{
			lmVec3Equals = nullptr;
			lmVec3NotEquals = nullptr;

			lmVec3Normalise = nullptr;
			lmVec3Maximise = nullptr;
			lmVec3Minimise = nullptr;
			lmVec3Negative = nullptr;

			lmVec3Mul = nullptr;
			lmVec3Div = nullptr;

			lmVec3Add = nullptr;
			lmVec3Sub = nullptr;
	
			lmVec3Length = nullptr;
			lmVec3LengthSqr = nullptr;

			lmVec3DotProduct = nullptr;
			lmVec3CrossProduct = nullptr;
			break;
		}
	}
}