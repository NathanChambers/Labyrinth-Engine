#include "lmVec4.h"
#include "lmCore.h"

extern bool g_bCoreRunning = true;

const lmVec4 lmVec4::ZERO = lmVec4(0,0,0,1);
const lmVec4 lmVec4::POSX = lmVec4(1,0,0,1);
const lmVec4 lmVec4::POSY = lmVec4(0,1,0,1);
const lmVec4 lmVec4::POSZ = lmVec4(0,0,1,1);
const lmVec4 lmVec4::NEGX = lmVec4(-1,0,0,1);
const lmVec4 lmVec4::NEGY = lmVec4(0,-1,0,1);
const lmVec4 lmVec4::NEGZ = lmVec4(0,0,-1,1);

////////////////////////////////////////////////////////////////////////////////

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
	if(fLength != 0)
	{
		a_rkArgOut.x = ac_rkArgL.x / fLength;
		a_rkArgOut.y = ac_rkArgL.y / fLength;
		a_rkArgOut.z = ac_rkArgL.z / fLength;
		a_rkArgOut.w = ac_rkArgL.w / fLength;
		return;
	}
	a_rkArgOut.Set(0.0f,0.0f,0.0f,0.0f);
}

void std_lmVec4Maximise(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL)
{
	float fHighest = ac_rkArgL.x;
	for(unsigned int i = 2;i < 4;i++)
	{
		if(ac_rkArgL[i] > fHighest)
			fHighest = ac_rkArgL[i];
	}
	a_rkArgOut.Set(fHighest,fHighest,fHighest,fHighest);
}

void std_lmVec4Minimise(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL)
{
	float fLowest = ac_rkArgL.x;
	for(unsigned int i = 2;i < 4;i++)
	{
		if(ac_rkArgL[i] < fLowest)
			fLowest = ac_rkArgL[i];
	}
	a_rkArgOut.Set(fLowest,fLowest,fLowest,fLowest);
}

void std_lmVec4CrossProduct(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL,const lmVec4& ac_rkArgR)
{
	a_rkArgOut.Set((ac_rkArgL.y * ac_rkArgR.z) - (ac_rkArgL.z * ac_rkArgR.y),
		(ac_rkArgL.z * ac_rkArgR.x) - (ac_rkArgL.x* ac_rkArgR.z),
		(ac_rkArgL.x * ac_rkArgR.y) - (ac_rkArgL.y * ac_rkArgR.x));
}

void std_lmVec4Lerp(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL,const lmVec4& ac_rkArgR,float a_fLerp)
{
	a_rkArgOut.x = (ac_rkArgL.x - (ac_rkArgR.x * a_fLerp));
	a_rkArgOut.y = (ac_rkArgL.y - (ac_rkArgR.y * a_fLerp));
	a_rkArgOut.z = (ac_rkArgL.z - (ac_rkArgR.z * a_fLerp));
	a_rkArgOut.w = (ac_rkArgL.w - (ac_rkArgR.w * a_fLerp));
}

////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C" 
{
	#endif // __cplusplus
		extern void ispcVec4Add(float* a_pkArgOut,const float* ac_pkArgL,const float* ac_pkArgR);
		extern void ispcVec4Sub(float* a_pkArgOut,const float* ac_pkArgL,const float* ac_pkArgR);
		extern void ispcVec4Mul(float* a_pkArgOut,const float* ac_pkArgL,const float ac_fArgR);
		extern void ispcVec4Div(float* a_pkArgOut,const float* ac_pkArgL,const float ac_fArgR);
		extern void ispcVec4Negative(float* a_pkArgOut,const float* ac_pkArgL);
		extern bool ispcVec4Equals(const float* ac_pkArgL,const float* ac_pkArgR);
		extern bool ispcVec4NotEquals(const float* ac_pkArgL,const float* ac_pkArgR);
		extern float ispcVec4DotProduct(const float* ac_pkArgL,const float* ac_pkArgR);
		extern float ispcVec4Length(const float* ac_pkArgL);
		extern float ispcVec4LengthSqr(const float* ac_pkArgL);
		extern void ispcVec4Normalise(float* a_pkArgOut,const float* ac_pkArgL);
		extern void ispcVec4Maximise(float* a_pkArgOut,const float* ac_pkArgL);
		extern void ispcVec4Minimise(float* a_pkArgOut,const float* ac_pkArgL);
		extern void ispcVec4CrossProduct(float* a_pkArgOut,const float* ac_pkArgL,const float* ac_pkArgR);
		extern void ispcVec4Lerp(float* a_pkArgOut,const float* ac_pkArgL,const float* ac_pkArgR,float a_fLerp);
	#ifdef __cplusplus
}
#endif // __cplusplus

void ispc_lmVec4Add(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL,const lmVec4& ac_rkArgR)
{
	ispcVec4Add(a_rkArgOut,ac_rkArgL,ac_rkArgR);
}

void ispc_lmVec4Sub(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL,const lmVec4& ac_rkArgR)
{
	ispcVec4Sub(a_rkArgOut,ac_rkArgL,ac_rkArgR);
}

void ispc_lmVec4Mul(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL,const float ac_fArgR)
{
	ispcVec4Mul(a_rkArgOut,ac_rkArgL,ac_fArgR);
}

void ispc_lmVec4Div(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL,const float ac_fArgR)
{
	ispcVec4Div(a_rkArgOut,ac_rkArgL,ac_fArgR);
}

void ispc_lmVec4Negative(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL)
{
	ispcVec4Negative(a_rkArgOut,ac_rkArgL);
}

bool ispc_lmVec4Equals(const lmVec4& ac_rkArgL,const lmVec4& ac_rkArgR)
{
	return ispcVec4Equals(ac_rkArgL,ac_rkArgR);
}

bool ispc_lmVec4NotEquals(const lmVec4& ac_rkArgL,const lmVec4& ac_rkArgR)
{
	return ispcVec4NotEquals(ac_rkArgL,ac_rkArgR);
}

float ispc_lmVec4DotProduct(const lmVec4& ac_rkArgL,const lmVec4& ac_rkArgR)
{
	return ispcVec4DotProduct(ac_rkArgL,ac_rkArgR);
}

float ispc_lmVec4Length(const lmVec4& ac_rkArgL)
{
	return ispcVec4Length(ac_rkArgL);
}

float ispc_lmVec4LengthSqr(const lmVec4& ac_rkArgL)
{
	return ispcVec4LengthSqr(ac_rkArgL);
}

void ispc_lmVec4Normalise(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL)
{
	ispcVec4Normalise(a_rkArgOut,ac_rkArgL);
}

void ispc_lmVec4Maximise(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL)
{
	ispcVec4Maximise(a_rkArgOut,ac_rkArgL);
}

void ispc_lmVec4Minimise(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL)
{
	ispcVec4Minimise(a_rkArgOut,ac_rkArgL);
}

void ispc_lmVec4CrossProject(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL,const lmVec4& ac_rkArgR)
{
	ispcVec4CrossProduct(a_rkArgOut,ac_rkArgL,ac_rkArgR);
}

void ispc_lmVec4Lerp(lmVec4& a_rkArgOut,const lmVec4& ac_rkArgL,const lmVec4& ac_rkArgR,float a_fLerp)
{
	ispcVec4Lerp(a_rkArgOut,ac_rkArgL,ac_rkArgR,a_fLerp);
}

////////////////////////////////////////////////////////////////////////////////

//bool(const lmVec4&, const lmVec4&)
lmVec4_Bool_CVec4_CVec4 lmVec4Equals = nullptr;
lmVec4_Bool_CVec4_CVec4 lmVec4NotEquals = nullptr;

//void (lmVec4&, const lmVec4&)
lmVec4_Void_Vec4_CVec4 lmVec4Normalise = nullptr;
lmVec4_Void_Vec4_CVec4 lmVec4Maximise = nullptr;
lmVec4_Void_Vec4_CVec4 lmVec4Minimise = nullptr;
lmVec4_Void_Vec4_CVec4 lmVec4Negative = nullptr;

//void (lmVec4&, const lmVec4&, float)
lmVec4_Void_Vec4_CVec4_Float lmVec4Mul = nullptr;
lmVec4_Void_Vec4_CVec4_Float lmVec4Div = nullptr;

//void (lmVec4&, const lmVec4&, const lmVec4&)
lmVec4_Void_Vec4_CVec4_CVec4 lmVec4Add = nullptr;
lmVec4_Void_Vec4_CVec4_CVec4 lmVec4Sub = nullptr;
lmVec4_Void_Vec4_CVec4_CVec4 lmVec4CrossProduct = nullptr;

//float (const lmVec4&)
lmVec4_Float_CVec4 lmVec4Length = nullptr;
lmVec4_Float_CVec4 lmVec4LengthSqr = nullptr;

//float (cosnt lmVec4&, const lmVec4&)
lmVec4_Float_CVec4_CVec4 lmVec4DotProduct = nullptr;

//void (lmVec4&, const lmVec4&, const lmVec4&, float)
lmVec4_Void_Vec4_CVec4_CVec4_Float lmVec4Lerp = nullptr;

void lmVec4::Construct()
{
	switch(lmGetIntrinsic())
	{
	case LM_INTRIN_STD:
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
			lmVec4CrossProduct = &std_lmVec4CrossProduct;
			lmVec4Lerp = &std_lmVec4Lerp;
			break;
		}

	case LM_INTRIN_ISPC:
		{
			lmVec4Equals = &ispc_lmVec4Equals;
			lmVec4NotEquals = &ispc_lmVec4NotEquals;

			lmVec4Normalise = &ispc_lmVec4Normalise;
			lmVec4Maximise = &ispc_lmVec4Maximise;
			lmVec4Minimise = &ispc_lmVec4Minimise;
			lmVec4Negative = &ispc_lmVec4Negative;

			lmVec4Mul = &ispc_lmVec4Mul;
			lmVec4Div = &ispc_lmVec4Div;

			lmVec4Add = &ispc_lmVec4Add;
			lmVec4Sub = &ispc_lmVec4Sub;
	
			lmVec4Length = &ispc_lmVec4Length;
			lmVec4LengthSqr = &ispc_lmVec4LengthSqr;

			lmVec4DotProduct = &ispc_lmVec4DotProduct;
			lmVec4CrossProduct = &ispc_lmVec4CrossProject;
			lmVec4Lerp = &ispc_lmVec4Lerp;
			break;
		}
	default:
		{
			lmVec4Equals = nullptr;
			lmVec4NotEquals = nullptr;

			lmVec4Normalise = nullptr;
			lmVec4Maximise = nullptr;
			lmVec4Minimise = nullptr;
			lmVec4Negative = nullptr;

			lmVec4Mul = nullptr;
			lmVec4Div = nullptr;

			lmVec4Add = nullptr;
			lmVec4Sub = nullptr;
	
			lmVec4Length = nullptr;
			lmVec4LengthSqr = nullptr;

			lmVec4DotProduct = nullptr;
			lmVec4CrossProduct = nullptr;
			lmVec4Lerp = nullptr;
			break;
		}
	}
}