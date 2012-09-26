#include "lmVec4.h"

inline
LmVec4::LmVec4()
{

}

inline
LmVec4::LmVec4(float a_fX ,float a_fY ,float a_fZ ,float a_fW)
	: x(a_fX),y(a_fY),z(a_fZ),w(a_fW)
{

}

inline
LmVec4::LmVec4(const LmVec4& ac_rkArgIn)
	:x(ac_rkArgIn.x),y(ac_rkArgIn.y),z(ac_rkArgIn.z),w(ac_rkArgIn.w)
{

}

inline
LmVec4::LmVec4(float* a_pfArgL)
	:x(a_pfArgL[0]),y(a_pfArgL[1]),z(a_pfArgL[2]),w(a_pfArgL[3])
{

}

inline
LmVec4::~LmVec4()
{

}

inline
void LmVec4::Set(float a_fX,float a_fY,float a_fZ,float a_fW)
{
	x = a_fX;
	y = a_fY;
	z = a_fZ;
	w = a_fW;
}

inline
LmVec4& LmVec4::operator = (const LmVec4& ac_pkArgL)
{
	x = ac_pkArgL.x;
	y = ac_pkArgL.y;
	z = ac_pkArgL.z;
	w = ac_pkArgL.w;
	return (*this);
}

inline
LmVec4& LmVec4::operator = (float* a_pfArgL)
{
	x = a_pfArgL[0];
	y = a_pfArgL[1];
	z = a_pfArgL[2];
	w = a_pfArgL[3];
	return (*this);
}

inline
LmVec4 LmVec4::operator + (const LmVec4& ac_rkArgL) const
{
	LmVec4 rkRetVec4;
	LmVec4Add(rkRetVec4,(*this),ac_rkArgL);
	return rkRetVec4;
}

inline
LmVec4 LmVec4::operator - (const LmVec4& ac_rkArgL) const
{
	LmVec4 rkRetVec4;
	LmVec4Sub(rkRetVec4,(*this),ac_rkArgL);
	return rkRetVec4;
}

inline
LmVec4& LmVec4::operator += (const LmVec4& ac_rkArgL)
{
	LmVec4Add((*this),(*this),ac_rkArgL);
	return (*this);
}

inline
LmVec4& LmVec4::operator -= (const LmVec4& ac_rkArgL)
{
	LmVec4Sub((*this),(*this),ac_rkArgL);
	return (*this);
}

inline
LmVec4 LmVec4::operator * (const float ac_fArg0) const
{
	LmVec4 rkRetVec4;
	LmVec4Mul(rkRetVec4,(*this),ac_fArg0);
	return rkRetVec4;
}

inline
LmVec4 LmVec4::operator / (const float ac_fArg0) const
{
	LmVec4 rkRetVec4;
	LmVec4Div(rkRetVec4,(*this),ac_fArg0);
	return rkRetVec4;
}

inline
LmVec4& LmVec4::operator *= (const float ac_fArg0)
{
	LmVec4Mul((*this),(*this),ac_fArg0);
	return (*this);
}

inline
LmVec4& LmVec4::operator /= (const float ac_fArg0)
{
	LmVec4Div((*this),(*this),ac_fArg0);
	return (*this);
}

inline
LmVec4 LmVec4::operator - ()
{
	LmVec4 rkRetVec4;
	LmVec4Negative(rkRetVec4,(*this));
	return rkRetVec4;
}

inline
float& LmVec4::operator [] (unsigned int a_uiIndex)
{
	return v[a_uiIndex];
}

inline
const float& LmVec4::operator [] (unsigned int a_uiIndex) const
{
	return v[a_uiIndex];
}

inline
bool LmVec4::operator == (const LmVec4& ac_rkArgL) const
{
	return LmVec4Equals((*this),ac_rkArgL);
}

inline
bool LmVec4::operator != (const LmVec4& ac_rkArgL) const
{
	return LmVec4NotEquals((*this),ac_rkArgL);
}

inline
float LmVec4::Length() const
{
	return LmVec4Length((*this));
}

inline
float LmVec4::LenghtSqr() const
{
	return LmVec4LengthSqr((*this));
}

inline
void LmVec4::Normalise()
{
	LmVec4Normalise((*this),(*this));
}

inline
void LmVec4::Maximize()
{
	LmVec4Maximise((*this),(*this));
}

inline
void LmVec4::Minimize()
{
	LmVec4Minimise((*this),(*this));
}

inline
float LmVec4::DotProduct(const LmVec4& ac_rkArgL) const
{
	return LmVec4DotProduct((*this),ac_rkArgL);
}

inline
LmVec4 LmVec4::CrossProduct(const LmVec4& ac_rkArgL) const
{
	LmVec4 kRetVec;
	LmVec4CrossProduct(kRetVec,(*this),ac_rkArgL);
	return kRetVec;
}