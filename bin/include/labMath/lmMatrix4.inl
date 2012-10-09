#include "lmMatrix4.h"

inline
lmMatrix4::lmMatrix4()
{

}

inline
lmMatrix4::lmMatrix4(const lmMatrix4& a_rkCopy)
	: m_f00(a_rkCopy.m_f00),m_f01(a_rkCopy.m_f01),m_f02(a_rkCopy.m_f02),m_f03(a_rkCopy.m_f03),m_f10(a_rkCopy.m_f10),m_f11(a_rkCopy.m_f11),m_f12(a_rkCopy.m_f12),m_f13(a_rkCopy.m_f13),
	m_f20(a_rkCopy.m_f20),m_f21(a_rkCopy.m_f21),m_f22(a_rkCopy.m_f22),m_f23(a_rkCopy.m_f23),m_f30(a_rkCopy.m_f30),m_f31(a_rkCopy.m_f31),m_f32(a_rkCopy.m_f32),m_f33(a_rkCopy.m_f33)
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
	for(int r = 0;r < 4;++r)
	{
		for(int c = 0;c < 4;++c)
		{
			m_m[r][c] = a_rkCopy.m_m[r][c];
		}
	}
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

inline
lmVec4 lmMatrix4::GetRow(int a_iRowIndex)
{
	lmVec4 kRetVec(m_m[a_iRowIndex][0],m_m[a_iRowIndex][1],m_m[a_iRowIndex][2],m_m[a_iRowIndex][3]);
	return kRetVec;
}

inline
lmVec4 lmMatrix4::GetCol(int a_iColIndex)
{
	lmVec4 kRetVec(m_m[0][a_iColIndex],m_m[1][a_iColIndex],m_m[2][a_iColIndex],m_m[3][a_iColIndex]);
	return kRetVec;
}

inline
void lmMatrix4::SetRow(const lmVec4& a_rkRow,int a_iRowIndex)
{

}

inline
void lmMatrix4::SetCol(const lmVec4& a_rkCol,int a_iColIndex)
{

}