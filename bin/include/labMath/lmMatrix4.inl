#include "lmMatrix4.h"

inline
lmMatrix4::lmMatrix4()
{

}

inline
lmMatrix4::lmMatrix4(const lmMatrix4& a_rkCopy)
	:m_kRowX(a_rkCopy.m_kRowX),m_kRowY(a_rkCopy.m_kRowY),m_kRowZ(a_rkCopy.m_kRowZ),m_kRowW(a_rkCopy.m_kRowW)
{

}

inline
lmMatrix4::lmMatrix4(float a_f00,float a_f01,float a_f02,float a_f03,float a_f10,float a_f11,float a_f12,float a_f13,
float a_f20,float a_f21,float a_f22,float a_f23,float a_f30,float a_f31,float a_f32,float a_f33)
	: m_f00(a_f00),m_f01(a_f01),m_f02(a_f02),m_f03(a_f03),m_f10(a_f10),m_f11(a_f11),m_f12(a_f12),m_f13(a_f13),
	m_f20(a_f20),m_f21(a_f21),m_f22(a_f22),m_f23(a_f23),m_f30(a_f30),m_f31(a_f31),m_f32(a_f32),m_f33(a_f33)
{

}

inline
lmMatrix4::~lmMatrix4()
{

}

inline
void lmMatrix4::operator = (const lmMatrix4& a_rkCopy)
{
	m_kRowX = a_rkCopy.m_kRowX;
	m_kRowY = a_rkCopy.m_kRowY;
	m_kRowZ = a_rkCopy.m_kRowZ;
	m_kRowW = a_rkCopy.m_kRowW;
}

inline
void lmMatrix4::Set(float a_f00,float a_f01,float a_f02,float a_f03,float a_f10,float a_f11,float a_f12,float a_f13,
float a_f20,float a_f21,float a_f22,float a_f23,float a_f30,float a_f31,float a_f32,float a_f33)
{
	m_f00 = a_f00;
	m_f01 = a_f01;
	m_f02 = a_f02;
	m_f03 = a_f03;

	m_f10 = a_f10;
	m_f11 = a_f11;
	m_f12 = a_f12;
	m_f13 = a_f13;

	m_f20 = a_f20;
	m_f21 = a_f21;
	m_f22 = a_f22;
	m_f23 = a_f23;

	m_f30 = a_f30;
	m_f31 = a_f31;
	m_f32 = a_f32;
	m_f33 = a_f33;
}

inline
lmMatrix4 lmMatrix4::operator * (const lmMatrix4& a_rkArgL)
{
	lmMatrix4 kRet;
	return kRet;
}

inline
void lmMatrix4::MakeXRotate(float a_fTheta)
{
	lmMatrix4MakeXRot((*this),a_fTheta);
}

inline
void lmMatrix4::MakeYRotate(float a_fTheta)
{
	lmMatrix4MakeYRot((*this),a_fTheta);
}

inline
void lmMatrix4::MakeZRotate(float a_fTheta)
{
	lmMatrix4MakeZRot((*this),a_fTheta);
}