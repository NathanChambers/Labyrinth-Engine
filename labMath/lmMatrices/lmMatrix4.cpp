#include "lmMatrix4.h"
#include "lmCore.h"

const lmMatrix4 lmMatrix4::IDENTITY = lmMatrix4(1.0f,0.0f,0.0f,0.0f,	//X
												0.0f,1.0f,0.0f,0.0f,	//Y
												0.0f,0.0f,1.0f,0.0f,	//Z
												0.0f,0.0f,0.0f,1.0f);	//T

void std_lmMatrix4Mul(lmMatrix4& a_rkArgOut,const lmMatrix4& a_rkArgL,const lmMatrix4& a_rkArgR)
{
	lmMatrix4 kOut;
	kOut.m_f11 = a_rkArgL.m_f11 * a_rkArgR.m_f11 + a_rkArgL.m_f12 * a_rkArgR.m_f21 + a_rkArgL.m_f13 * a_rkArgR.m_f31 + a_rkArgL.m_f14 * a_rkArgR.m_f41;
	kOut.m_f12 = a_rkArgL.m_f11 * a_rkArgR.m_f12 + a_rkArgL.m_f12 * a_rkArgR.m_f22 + a_rkArgL.m_f13 * a_rkArgR.m_f32 + a_rkArgL.m_f14 * a_rkArgR.m_f42;
	kOut.m_f13 = a_rkArgL.m_f11 * a_rkArgR.m_f13 + a_rkArgL.m_f12 * a_rkArgR.m_f23 + a_rkArgL.m_f13 * a_rkArgR.m_f33 + a_rkArgL.m_f14 * a_rkArgR.m_f43;
	kOut.m_f14 = a_rkArgL.m_f11 * a_rkArgR.m_f14 + a_rkArgL.m_f12 * a_rkArgR.m_f24 + a_rkArgL.m_f13 * a_rkArgR.m_f34 + a_rkArgL.m_f14 * a_rkArgR.m_f44;

	kOut.m_f21 = a_rkArgL.m_f21 * a_rkArgR.m_f11 + a_rkArgL.m_f22 * a_rkArgR.m_f21 + a_rkArgL.m_f23 * a_rkArgR.m_f31 + a_rkArgL.m_f24 * a_rkArgR.m_f41;
	kOut.m_f22 = a_rkArgL.m_f21 * a_rkArgR.m_f12 + a_rkArgL.m_f22 * a_rkArgR.m_f22 + a_rkArgL.m_f23 * a_rkArgR.m_f32 + a_rkArgL.m_f24 * a_rkArgR.m_f42;
	kOut.m_f23 = a_rkArgL.m_f21 * a_rkArgR.m_f13 + a_rkArgL.m_f22 * a_rkArgR.m_f23 + a_rkArgL.m_f23 * a_rkArgR.m_f33 + a_rkArgL.m_f24 * a_rkArgR.m_f43;
	kOut.m_f24 = a_rkArgL.m_f21 * a_rkArgR.m_f14 + a_rkArgL.m_f22 * a_rkArgR.m_f24 + a_rkArgL.m_f23 * a_rkArgR.m_f34 + a_rkArgL.m_f24 * a_rkArgR.m_f44;

	kOut.m_f31 = a_rkArgL.m_f31 * a_rkArgR.m_f11 + a_rkArgL.m_f32 * a_rkArgR.m_f21 + a_rkArgL.m_f33 * a_rkArgR.m_f31 + a_rkArgL.m_f34 * a_rkArgR.m_f41;
	kOut.m_f32 = a_rkArgL.m_f31 * a_rkArgR.m_f12 + a_rkArgL.m_f32 * a_rkArgR.m_f22 + a_rkArgL.m_f33 * a_rkArgR.m_f32 + a_rkArgL.m_f34 * a_rkArgR.m_f42;
	kOut.m_f33 = a_rkArgL.m_f31 * a_rkArgR.m_f13 + a_rkArgL.m_f32 * a_rkArgR.m_f23 + a_rkArgL.m_f33 * a_rkArgR.m_f33 + a_rkArgL.m_f34 * a_rkArgR.m_f43;
	kOut.m_f34 = a_rkArgL.m_f31 * a_rkArgR.m_f14 + a_rkArgL.m_f32 * a_rkArgR.m_f24 + a_rkArgL.m_f33 * a_rkArgR.m_f34 + a_rkArgL.m_f34 * a_rkArgR.m_f44;

	kOut.m_f41 = a_rkArgL.m_f41 * a_rkArgR.m_f11 + a_rkArgL.m_f42 * a_rkArgR.m_f21 + a_rkArgL.m_f43 * a_rkArgR.m_f31 + a_rkArgL.m_f44 * a_rkArgR.m_f41;
	kOut.m_f42 = a_rkArgL.m_f41 * a_rkArgR.m_f12 + a_rkArgL.m_f42 * a_rkArgR.m_f22 + a_rkArgL.m_f43 * a_rkArgR.m_f32 + a_rkArgL.m_f44 * a_rkArgR.m_f42;
	kOut.m_f43 = a_rkArgL.m_f41 * a_rkArgR.m_f13 + a_rkArgL.m_f42 * a_rkArgR.m_f23 + a_rkArgL.m_f43 * a_rkArgR.m_f33 + a_rkArgL.m_f44 * a_rkArgR.m_f43;
	kOut.m_f44 = a_rkArgL.m_f41 * a_rkArgR.m_f14 + a_rkArgL.m_f42 * a_rkArgR.m_f24 + a_rkArgL.m_f43 * a_rkArgR.m_f34 + a_rkArgL.m_f44 * a_rkArgR.m_f44;

	a_rkArgOut = kOut;
}

void std_lmMatrix4MakeXRot(lmMatrix4& a_rkArgOut,float a_fTheta)
{
	float fSin = sinf(a_fTheta);
	float fCos = cosf(a_fTheta);

	a_rkArgOut.m_f11 = 1;		a_rkArgOut.m_f12 = 0;			a_rkArgOut.m_f13 = 0;		a_rkArgOut.m_f14 = 0;
	a_rkArgOut.m_f21 = 0;		a_rkArgOut.m_f22 = fCos;		a_rkArgOut.m_f23 = fSin;	a_rkArgOut.m_f24 = 0;
	a_rkArgOut.m_f31 = 0;		a_rkArgOut.m_f32 = -fSin;		a_rkArgOut.m_f33 = fCos;	a_rkArgOut.m_f34 = 0;
	a_rkArgOut.m_f41 = 0;		a_rkArgOut.m_f42 = 0;			a_rkArgOut.m_f43 = 0;		a_rkArgOut.m_f44 = 1;
}

void std_lmMatrix4MakeYRot(lmMatrix4& a_rkArgOut,float a_fTheta)
{	
	float fSin = sinf(a_fTheta);
	float fCos = cosf(a_fTheta);

	a_rkArgOut.m_f11 = fCos;		a_rkArgOut.m_f12 = 0;		a_rkArgOut.m_f13 = fSin;	a_rkArgOut.m_f14 = 0;
	a_rkArgOut.m_f21 = 0;			a_rkArgOut.m_f22 = 1;		a_rkArgOut.m_f23 = 0;		a_rkArgOut.m_f24 = 0;
	a_rkArgOut.m_f31 = -fSin;		a_rkArgOut.m_f32 = 0;		a_rkArgOut.m_f33 = fCos;	a_rkArgOut.m_f34 = 0;
	a_rkArgOut.m_f41 = 0;			a_rkArgOut.m_f42 = 0;		a_rkArgOut.m_f43 = 0;		a_rkArgOut.m_f44 = 1;
}

void std_lmMatrix4MakeZRot(lmMatrix4& a_rkArgOut,float a_fTheta)
{
	float fSin = sinf(a_fTheta);
	float fCos = cosf(a_fTheta);

	a_rkArgOut.m_f11 = fCos;		a_rkArgOut.m_f12 = fSin;	a_rkArgOut.m_f13 = 0;		a_rkArgOut.m_f14 = 0;
	a_rkArgOut.m_f21 = -fSin;		a_rkArgOut.m_f22 = fCos;	a_rkArgOut.m_f23 = 0;		a_rkArgOut.m_f24 = 0;
	a_rkArgOut.m_f31 = 0;			a_rkArgOut.m_f32 = 0;		a_rkArgOut.m_f33 = 1;		a_rkArgOut.m_f34 = 0;
	a_rkArgOut.m_f41 = 0;			a_rkArgOut.m_f42 = 0;		a_rkArgOut.m_f43 = 0;		a_rkArgOut.m_f44 = 1;
}

#ifdef __cplusplus
extern "C" 
{
	#endif // __cplusplus
		extern void ispcMatrix4Mul(float* a_pkArgOut,const float* ac_pkArgL,const float* ac_pkArgR);
	#ifdef __cplusplus
}
#endif // __cplusplus

void ispc_lmMatrix4Mul(lmMatrix4& a_rkArgOut,const lmMatrix4& ac_rkArgL,const lmMatrix4& ac_rkArgR)
{
	ispcMatrix4Mul(a_rkArgOut,ac_rkArgL,ac_rkArgR);
}

//void(lmMatrix4&,const lmMatrix4&,const lmMatrix4&)
lmMatrix4_void_lmMatrix4_ClmMatrix4_ClmMatrix4 lmMatrix4Mul = nullptr;

//void(lmMatrix4&,float)
lmMatrix4_void_lmMatrix4_float lmMatrix4MakeXRot = nullptr;
lmMatrix4_void_lmMatrix4_float lmMatrix4MakeYRot = nullptr;
lmMatrix4_void_lmMatrix4_float lmMatrix4MakeZRot = nullptr;

void lmMatrix4::Construct()
{
	lmMatrix4Mul = &ispc_lmMatrix4Mul;

	lmMatrix4MakeXRot = &std_lmMatrix4MakeXRot;
	lmMatrix4MakeYRot = &std_lmMatrix4MakeYRot;
	lmMatrix4MakeZRot = &std_lmMatrix4MakeZRot;
}