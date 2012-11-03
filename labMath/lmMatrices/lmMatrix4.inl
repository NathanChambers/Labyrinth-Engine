#include "lmMatrix4.h"

inline
lmMatrix4::lmMatrix4()
{

}

inline
lmMatrix4::~lmMatrix4()
{

}

inline
lmMatrix4::lmMatrix4(	float a_f11,float a_f12,float a_f13,float a_f14,
						float a_f21,float a_f22,float a_f23,float a_f24,
						float a_f31,float a_f32,float a_f33,float a_f34,
						float a_f41,float a_f42,float a_f43,float a_f44)
:	m_f11(a_f11),m_f12(a_f12),m_f13(a_f13),m_f14(a_f14),
	m_f21(a_f21),m_f22(a_f22),m_f23(a_f23),m_f24(a_f24),
	m_f31(a_f31),m_f32(a_f32),m_f33(a_f33),m_f34(a_f34),
	m_f41(a_f41),m_f42(a_f42),m_f43(a_f43),m_f44(a_f44)
{

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
lmMatrix4 lmMatrix4::operator * (const lmMatrix4& ac_kArgL)
{
	lmMatrix4 kRetMat;
	lmMatrix4Mul(kRetMat,(*this),ac_kArgL);
	return kRetMat;
}

inline
lmMatrix4& lmMatrix4::operator *= (const lmMatrix4& ac_kArgL)
{
	lmMatrix4Mul((*this),(*this),ac_kArgL);
}

inline
lmMatrix4::operator float *()
{
	return m_v;
}

inline 
lmMatrix4::operator const float *() const
{
	return m_v;
}