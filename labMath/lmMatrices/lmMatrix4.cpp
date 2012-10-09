#include "lmMatrix4.h"
#include "lmCore.h"

const lmMatrix4 lmMatrix4::IDENTITY = lmMatrix4(1,0,0,0,
												0,1,0,0,
												0,0,1,0,
												0,0,0,1);

void std_lmMatrix4Mul(lmMatrix4& a_rkArgOut,const lmMatrix4& a_rkArgL,const lmMatrix4& a_rkArgR)
{
	a_rkArgOut.m_f00 = a_rkArgL.m_f00 * a_rkArgR.m_f00 + a_rkArgL.m_f10 * a_rkArgR.m_f01 + a_rkArgL.m_f20 * a_rkArgR.m_f02 + a_rkArgL.m_f30 * a_rkArgR.m_f03;
	a_rkArgOut.m_f01 = a_rkArgL.m_f10 * a_rkArgR.m_f00 + a_rkArgL.m_f11 * a_rkArgR.m_f01 + a_rkArgL.m_f21 * a_rkArgR.m_f02 + a_rkArgL.m_f31 * a_rkArgR.m_f03;
	a_rkArgOut.m_f02 = a_rkArgL.m_f20 * a_rkArgR.m_f00 + a_rkArgL.m_f12 * a_rkArgR.m_f01 + a_rkArgL.m_f22 * a_rkArgR.m_f02 + a_rkArgL.m_f32 * a_rkArgR.m_f03;
	a_rkArgOut.m_f03 = a_rkArgL.m_f30 * a_rkArgR.m_f00 + a_rkArgL.m_f13 * a_rkArgR.m_f01 + a_rkArgL.m_f23 * a_rkArgR.m_f02 + a_rkArgL.m_f33 * a_rkArgR.m_f03;

	a_rkArgOut.m_f10 = a_rkArgL.m_f00 * a_rkArgR.m_f10 + a_rkArgL.m_f10 * a_rkArgR.m_f11 + a_rkArgL.m_f20 * a_rkArgR.m_f12 + a_rkArgL.m_f30 * a_rkArgR.m_f13;
	a_rkArgOut.m_f11 = a_rkArgL.m_f10 * a_rkArgR.m_f10 + a_rkArgL.m_f11 * a_rkArgR.m_f11 + a_rkArgL.m_f21 * a_rkArgR.m_f12 + a_rkArgL.m_f31 * a_rkArgR.m_f13;
	a_rkArgOut.m_f12 = a_rkArgL.m_f20 * a_rkArgR.m_f10 + a_rkArgL.m_f12 * a_rkArgR.m_f11 + a_rkArgL.m_f22 * a_rkArgR.m_f12 + a_rkArgL.m_f32 * a_rkArgR.m_f13;
	a_rkArgOut.m_f13 = a_rkArgL.m_f30 * a_rkArgR.m_f10 + a_rkArgL.m_f13 * a_rkArgR.m_f11 + a_rkArgL.m_f23 * a_rkArgR.m_f12 + a_rkArgL.m_f33 * a_rkArgR.m_f13;

	a_rkArgOut.m_f20 = a_rkArgL.m_f00 * a_rkArgR.m_f20 + a_rkArgL.m_f10 * a_rkArgR.m_f21 + a_rkArgL.m_f20 * a_rkArgR.m_f22 + a_rkArgL.m_f30 * a_rkArgR.m_f23;
	a_rkArgOut.m_f21 = a_rkArgL.m_f10 * a_rkArgR.m_f20 + a_rkArgL.m_f11 * a_rkArgR.m_f21 + a_rkArgL.m_f21 * a_rkArgR.m_f22 + a_rkArgL.m_f31 * a_rkArgR.m_f23;
	a_rkArgOut.m_f22 = a_rkArgL.m_f20 * a_rkArgR.m_f20 + a_rkArgL.m_f12 * a_rkArgR.m_f21 + a_rkArgL.m_f22 * a_rkArgR.m_f22 + a_rkArgL.m_f32 * a_rkArgR.m_f23;
	a_rkArgOut.m_f23 = a_rkArgL.m_f30 * a_rkArgR.m_f20 + a_rkArgL.m_f13 * a_rkArgR.m_f21 + a_rkArgL.m_f23 * a_rkArgR.m_f22 + a_rkArgL.m_f33 * a_rkArgR.m_f23;

	a_rkArgOut.m_f30 = a_rkArgL.m_f00 * a_rkArgR.m_f30 + a_rkArgL.m_f10 * a_rkArgR.m_f31 + a_rkArgL.m_f20 * a_rkArgR.m_f32 + a_rkArgL.m_f30 * a_rkArgR.m_f33;
	a_rkArgOut.m_f31 = a_rkArgL.m_f10 * a_rkArgR.m_f30 + a_rkArgL.m_f11 * a_rkArgR.m_f31 + a_rkArgL.m_f21 * a_rkArgR.m_f32 + a_rkArgL.m_f31 * a_rkArgR.m_f33;
	a_rkArgOut.m_f32 = a_rkArgL.m_f20 * a_rkArgR.m_f30 + a_rkArgL.m_f12 * a_rkArgR.m_f31 + a_rkArgL.m_f22 * a_rkArgR.m_f32 + a_rkArgL.m_f32 * a_rkArgR.m_f33;
	a_rkArgOut.m_f33 = a_rkArgL.m_f30 * a_rkArgR.m_f30 + a_rkArgL.m_f13 * a_rkArgR.m_f31 + a_rkArgL.m_f23 * a_rkArgR.m_f32 + a_rkArgL.m_f33 * a_rkArgR.m_f33;
}

void std_lmMatrix4MakeXRot(lmMatrix4& a_rkArgOut,float a_fTheta)
{
	float fCos = cosf(a_fTheta);
	float fSin = sinf(a_fTheta);
	a_rkArgOut.m_f00 = 1;	a_rkArgOut.m_f01 = 0;		a_rkArgOut.m_f02 = 0;			a_rkArgOut.m_f03 = 0;
	a_rkArgOut.m_f10 = 0;	a_rkArgOut.m_f11 = fCos;	a_rkArgOut.m_f12 = fSin;		a_rkArgOut.m_f13 = 0;
	a_rkArgOut.m_f20 = 0;	a_rkArgOut.m_f21 = -fSin;	a_rkArgOut.m_f22 = fCos;		a_rkArgOut.m_f23 = 0;
	a_rkArgOut.m_f30 = 0;	a_rkArgOut.m_f31 = 0;		a_rkArgOut.m_f32 = 0;			a_rkArgOut.m_f33 = 1;
}

void std_lmMatrix4MakeYRot(lmMatrix4& a_rkArgOut,float a_fTheta)
{	
	float fCos = cosf(a_fTheta);
	float fSin = sinf(a_fTheta);
	a_rkArgOut.m_f00 = fCos;	a_rkArgOut.m_f01 = 0;		a_rkArgOut.m_f02 = fSin;	a_rkArgOut.m_f03 = 0;
	a_rkArgOut.m_f10 = 0;		a_rkArgOut.m_f11 = 1;		a_rkArgOut.m_f12 = 0;		a_rkArgOut.m_f13 = 0;
	a_rkArgOut.m_f20 = -fSin;	a_rkArgOut.m_f21 = 0;		a_rkArgOut.m_f22 = fCos;	a_rkArgOut.m_f23 = 0;
	a_rkArgOut.m_f30 = 0;		a_rkArgOut.m_f31 = 0;		a_rkArgOut.m_f32 = 0;		a_rkArgOut.m_f33 = 1;
}

void std_lmMatrix4MakeZRot(lmMatrix4& a_rkArgOut,float a_fTheta)
{
	float fCos = cosf(a_fTheta);
	float fSin = sinf(a_fTheta);
	a_rkArgOut.m_f00 = fCos;	a_rkArgOut.m_f01 = fSin;	a_rkArgOut.m_f02 = 0;		a_rkArgOut.m_f03 = 0;
	a_rkArgOut.m_f10 = -fSin;	a_rkArgOut.m_f11 = fCos;	a_rkArgOut.m_f12 = 0;		a_rkArgOut.m_f13 = 0;
	a_rkArgOut.m_f20 = 0;		a_rkArgOut.m_f21 = 0;		a_rkArgOut.m_f22 = 1;		a_rkArgOut.m_f23 = 0;
	a_rkArgOut.m_f30 = 0;		a_rkArgOut.m_f31 = 0;		a_rkArgOut.m_f32 = 0;		a_rkArgOut.m_f33 = 1;
}

//void(lmMatrix4&,const lmMatrix4&,const lmMatrix4&)
lmMatrix4_void_lmMatrix4_ClmMatrix4_ClmMatrix4 lmMatrix4Mul = nullptr;

//void(lmMatrix4&,float)
lmMatrix4_void_lmMatrix4_float lmMatrix4MakeXRot = nullptr;
lmMatrix4_void_lmMatrix4_float lmMatrix4MakeYRot = nullptr;
lmMatrix4_void_lmMatrix4_float lmMatrix4MakeZRot = nullptr;

void lmMatrix4::Construct()
{
	lmMatrix4Mul = &std_lmMatrix4Mul;

	lmMatrix4MakeXRot = &std_lmMatrix4MakeXRot;
	lmMatrix4MakeYRot = &std_lmMatrix4MakeYRot;
	lmMatrix4MakeZRot = &std_lmMatrix4MakeZRot;
}