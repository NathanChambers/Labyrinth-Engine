#include "lmVec3.h"

inline
LmVec3::LmVec3()
{

}

inline
LmVec3::LmVec3(float a_fX ,float a_fY ,float a_fZ)
	: x(a_fX),y(a_fY),z(a_fZ)
{

}

inline
LmVec3::LmVec3(const LmVec3& ac_rkArgIn)
	:x(ac_rkArgIn.x),y(ac_rkArgIn.y),z(ac_rkArgIn.z)
{

}

inline
LmVec3::LmVec3(float* a_pfArgL)
	:x(a_pfArgL[0]),y(a_pfArgL[1]),z(a_pfArgL[2])
{

}

inline
LmVec3::~LmVec3()
{

}

inline
void LmVec3::Set(float a_fX,float a_fY,float a_fZ)
{
	x = a_fX;
	y = a_fY;
	z = a_fZ;
}

inline
LmVec3& LmVec3::operator = (const LmVec3& ac_pkArgL)
{
	x = ac_pkArgL.x;
	y = ac_pkArgL.y;
	z = ac_pkArgL.z;
	return (*this);
}

inline
LmVec3& LmVec3::operator = (float* a_pfArgL)
{
	x = a_pfArgL[0];
	y = a_pfArgL[1];
	z = a_pfArgL[2];
	return (*this);
}

inline
LmVec3 LmVec3::operator + (const LmVec3& ac_rkArgL) const
{
	LmVec3 rkRetVec3;
	LmVec3Add(rkRetVec3,(*this),ac_rkArgL);
	return rkRetVec3;
}

inline
LmVec3 LmVec3::operator - (const LmVec3& ac_rkArgL) const
{
	LmVec3 rkRetVec3;
	LmVec3Sub(rkRetVec3,(*this),ac_rkArgL);
	return rkRetVec3;
}

inline
LmVec3& LmVec3::operator += (const LmVec3& ac_rkArgL)
{
	LmVec3Add((*this),(*this),ac_rkArgL);
	return (*this);
}

inline
LmVec3& LmVec3::operator -= (const LmVec3& ac_rkArgL)
{
	LmVec3Sub((*this),(*this),ac_rkArgL);
	return (*this);
}

inline
LmVec3 LmVec3::operator * (const float ac_fArg0) const
{
	LmVec3 rkRetVec3;
	LmVec3Mul(rkRetVec3,(*this),ac_fArg0);
	return rkRetVec3;
}

inline
LmVec3 LmVec3::operator / (const float ac_fArg0) const
{
	LmVec3 rkRetVec3;
	LmVec3Div(rkRetVec3,(*this),ac_fArg0);
	return rkRetVec3;
}

inline
LmVec3& LmVec3::operator *= (const float ac_fArg0)
{
	LmVec3Mul((*this),(*this),ac_fArg0);
	return (*this);
}

inline
LmVec3& LmVec3::operator /= (const float ac_fArg0)
{
	LmVec3Div((*this),(*this),ac_fArg0);
	return (*this);
}

inline
LmVec3 LmVec3::operator - ()
{
	LmVec3 rkRetVec3;
	LmVec3Negative(rkRetVec3,(*this));
	return rkRetVec3;
}

inline
float& LmVec3::operator [] (unsigned int a_uiIndex)
{
	return v[a_uiIndex];
}

inline
const float& LmVec3::operator [] (unsigned int a_uiIndex) const
{
	return v[a_uiIndex];
}

inline
bool LmVec3::operator == (const LmVec3& ac_rkArgL) const
{
	return LmVec3Equals((*this),ac_rkArgL);
}

inline
bool LmVec3::operator != (const LmVec3& ac_rkArgL) const
{
	return LmVec3NotEquals((*this),ac_rkArgL);
}

inline
float LmVec3::Length() const
{
	return LmVec3Length((*this));
}

inline
float LmVec3::LenghtSqr() const
{
	return LmVec3LengthSqr((*this));
}

inline
void LmVec3::Normalise()
{
	LmVec3Normalise((*this),(*this));
}

inline
void LmVec3::Maximize()
{
	LmVec3Maximise((*this),(*this));
}

inline
void LmVec3::Minimize()
{
	LmVec3Minimise((*this),(*this));
}

inline
float LmVec3::DotProduct(const LmVec3& ac_rkArgL) const
{
	return LmVec3DotProduct((*this),ac_rkArgL);
}

inline
LmVec3 LmVec3::CrossProduct(const LmVec3& ac_rkArgL) const
{
	LmVec3 kRetVec;
	LmVec3CrossProduct(kRetVec,(*this),ac_rkArgL);
	return kRetVec;
}