#include "lmMatrix3.h"

inline
lmMatrix3::lmMatrix3()
{

}

inline
lmMatrix3::lmMatrix3(const lmMatrix3& a_rkCopy)
	:m_kRowX(a_rkCopy.m_kRowX),m_kRowY(a_rkCopy.m_kRowY),m_kRowZ(a_rkCopy.m_kRowZ)
{

}

inline
lmMatrix3::lmMatrix3(float a_f00,float a_f01,float a_f02,float a_f10,float a_f11,float a_f12,float a_f20,float a_f21,float a_f22)
	: m_f00(a_f00),m_f01(a_f01),m_f02(a_f02),m_f10(a_f10),m_f11(a_f11),m_f12(a_f12),m_f20(a_f20),m_f21(a_f21),m_f22(a_f22)
{

}

inline
lmMatrix3::~lmMatrix3()
{

}

inline
void lmMatrix3::operator = (const lmMatrix3& a_rkCopy)
{
	m_f00 = a_rkCopy.m_f00;
	m_f01 = a_rkCopy.m_f01;
	m_f02 = a_rkCopy.m_f02;

	m_f10 = a_rkCopy.m_f10;
	m_f11 = a_rkCopy.m_f11;
	m_f12 = a_rkCopy.m_f12;

	m_f20 = a_rkCopy.m_f20;
	m_f21 = a_rkCopy.m_f21;
	m_f22 = a_rkCopy.m_f22;
}

inline
void lmMatrix3::Set(float a_f00,float a_f01,float a_f02,float a_f10,float a_f11,float a_f12,float a_f20,float a_f21,float a_f22)
{
	m_f00 = a_f00;
	m_f01 = a_f01;
	m_f02 = a_f02;

	m_f10 = a_f10;
	m_f11 = a_f11;
	m_f12 = a_f12;

	m_f20 = a_f20;
	m_f21 = a_f21;
	m_f22 = a_f22;
}