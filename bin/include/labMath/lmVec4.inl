#include "lmVec4.h"
#include "lmVec3.h"
#include "lmVec2.h"

inline
lmVec4::lmVec4()
{

}

inline
lmVec4::lmVec4(float a_fX ,float a_fY ,float a_fZ ,float a_fW)
	: x(a_fX),y(a_fY),z(a_fZ),w(a_fW)
{

}

inline
lmVec4::lmVec4(const lmVec4& ac_rkArgIn)
	:x(ac_rkArgIn.x),y(ac_rkArgIn.y),z(ac_rkArgIn.z),w(ac_rkArgIn.w)
{

}

inline
lmVec4::lmVec4(float* a_pfArgL)
	:x(a_pfArgL[0]),y(a_pfArgL[1]),z(a_pfArgL[2]),w(a_pfArgL[3])
{

}

inline
lmVec4::~lmVec4()
{

}

inline
void lmVec4::Set(float a_fX,float a_fY,float a_fZ,float a_fW)
{
	x = a_fX;
	y = a_fY;
	z = a_fZ;
	w = a_fW;
}

inline
lmVec4& lmVec4::operator = (const lmVec4& ac_pkArgL)
{
	x = ac_pkArgL.x;
	y = ac_pkArgL.y;
	z = ac_pkArgL.z;
	w = ac_pkArgL.w;
	return (*this);
}

inline
lmVec4& lmVec4::operator = (float* a_pfArgL)
{
	x = a_pfArgL[0];
 	y = a_pfArgL[1];
	z = a_pfArgL[2];
	w = a_pfArgL[3];
	return (*this);
}

inline
lmVec4 lmVec4::operator + (const lmVec4& ac_rkArgL) const
{
	lmVec4 rkRetVec4;
	lmVec4Add(rkRetVec4,(*this),ac_rkArgL);
	return rkRetVec4;
}

inline
lmVec4 lmVec4::operator - (const lmVec4& ac_rkArgL) const
{
	lmVec4 rkRetVec4;
	lmVec4Sub(rkRetVec4,(*this),ac_rkArgL);
	return rkRetVec4;
}

inline
lmVec4& lmVec4::operator += (const lmVec4& ac_rkArgL)
{
	lmVec4Add((*this),(*this),ac_rkArgL);
	return (*this);
}

inline
lmVec4& lmVec4::operator -= (const lmVec4& ac_rkArgL)
{
	lmVec4Sub((*this),(*this),ac_rkArgL);
	return (*this);
}

inline
lmVec4 lmVec4::operator * (const float ac_fArg0) const
{
	lmVec4 rkRetVec4;
	lmVec4Mul(rkRetVec4,(*this),ac_fArg0);
	return rkRetVec4;
}

inline
lmVec4 lmVec4::operator / (const float ac_fArg0) const
{
	lmVec4 rkRetVec4;
	lmVec4Div(rkRetVec4,(*this),ac_fArg0);
	return rkRetVec4;
}

inline
lmVec4& lmVec4::operator *= (const float ac_fArg0)
{
	lmVec4Mul((*this),(*this),ac_fArg0);
	return (*this);
}

inline
lmVec4& lmVec4::operator /= (const float ac_fArg0)
{
	lmVec4Div((*this),(*this),ac_fArg0);
	return (*this);
}

inline
lmVec4 lmVec4::operator - ()
{
	lmVec4 rkRetVec4;
	lmVec4Negative(rkRetVec4,(*this));
	return rkRetVec4;
}

inline
float& lmVec4::operator [] (unsigned int a_uiIndex)
{
	return v[a_uiIndex];
}

inline
const float& lmVec4::operator [] (unsigned int a_uiIndex) const
{
	return v[a_uiIndex];
}

inline
bool lmVec4::operator == (const lmVec4& ac_rkArgL) const
{
	return lmVec4Equals((*this),ac_rkArgL);
}

inline
bool lmVec4::operator != (const lmVec4& ac_rkArgL) const
{
	return lmVec4NotEquals((*this),ac_rkArgL);
}

inline
lmVec4::operator const float *() const
{
	return (const float*)v;
}

inline 
lmVec4::operator float *()
{
	return v;
}

//inline
//lmVec4::operator lmVec3() const
//{
//	return lmVec3((*this));
//}
//
//inline
//lmVec4::operator lmVec2() const
//{
//	return lmVec2((*this));
//}

inline
float lmVec4::Length() const
{
	return lmVec4Length((*this));
}

inline
float lmVec4::LenghtSqr() const
{
	return lmVec4LengthSqr((*this));
}

inline
void lmVec4::Normalise()
{
	lmVec4Normalise((*this),(*this));
}

inline
void lmVec4::Maximize()
{
	lmVec4Maximise((*this),(*this));
}

inline
void lmVec4::Minimize()
{
	lmVec4Minimise((*this),(*this));
}

inline
float lmVec4::DotProduct(const lmVec4& ac_rkArgL) const
{
	return lmVec4DotProduct((*this),ac_rkArgL);
}

inline
lmVec4 lmVec4::CrossProduct(const lmVec4& ac_rkArgL,const lmVec4& ac_rkArgR) const
{
	lmVec4 rkRetVec4;
	lmVec4CrossProduct(rkRetVec4,ac_rkArgL,ac_rkArgR);
	return rkRetVec4;
}

inline
lmVec4 lmVec4::Lerp(const lmVec4& ac_rkArgL,float a_fLerp)
{
	lmVec4 rkRetVec4;
	lmVec4Lerp(rkRetVec4,(*this),ac_rkArgL,a_fLerp);
	return rkRetVec4;
}