#include "lmVec2.h"

inline
lmVec2::lmVec2()
{

}

inline
lmVec2::lmVec2(float a_fX ,float a_fY)
	: x(a_fX),y(a_fY)
{

}

inline
lmVec2::lmVec2(const lmVec2& ac_rkArgIn)
	:x(ac_rkArgIn.x),y(ac_rkArgIn.y)
{

}

inline
lmVec2::lmVec2(float* a_pfArgL)
	:x(a_pfArgL[0]),y(a_pfArgL[1])
{

}

inline
lmVec2::~lmVec2()
{

}

inline
void lmVec2::Set(float a_fX,float a_fY)
{
	x = a_fX;
	y = a_fY;
}

inline
lmVec2& lmVec2::operator = (const lmVec2& ac_pkArgL)
{
	x = ac_pkArgL.x;
	y = ac_pkArgL.y;
	return (*this);
}

inline
lmVec2& lmVec2::operator = (float* a_pfArgL)
{
	x = a_pfArgL[0];
	y = a_pfArgL[1];
	return (*this);
}

inline
lmVec2 lmVec2::operator + (const lmVec2& ac_rkArgL) const
{
	lmVec2 rkRetVec2;
	lmVec2Add(rkRetVec2,(*this),ac_rkArgL);
	return rkRetVec2;
}

inline
lmVec2 lmVec2::operator - (const lmVec2& ac_rkArgL) const
{
	lmVec2 rkRetVec2;
	lmVec2Sub(rkRetVec2,(*this),ac_rkArgL);
	return rkRetVec2;
}

inline
lmVec2& lmVec2::operator += (const lmVec2& ac_rkArgL)
{
	lmVec2Add((*this),(*this),ac_rkArgL);
	return (*this);
}

inline
lmVec2& lmVec2::operator -= (const lmVec2& ac_rkArgL)
{
	lmVec2Sub((*this),(*this),ac_rkArgL);
	return (*this);
}

inline
lmVec2 lmVec2::operator * (const float ac_fArg0) const
{
	lmVec2 rkRetVec2;
	lmVec2Mul(rkRetVec2,(*this),ac_fArg0);
	return rkRetVec2;
}

inline
lmVec2 lmVec2::operator / (const float ac_fArg0) const
{
	lmVec2 rkRetVec2;
	lmVec2Div(rkRetVec2,(*this),ac_fArg0);
	return rkRetVec2;
}

inline
lmVec2& lmVec2::operator *= (const float ac_fArg0)
{
	lmVec2Mul((*this),(*this),ac_fArg0);
	return (*this);
}

inline
lmVec2& lmVec2::operator /= (const float ac_fArg0)
{
	lmVec2Div((*this),(*this),ac_fArg0);
	return (*this);
}

inline
lmVec2 lmVec2::operator - ()
{
	lmVec2 rkRetVec2;
	lmVec2Negative(rkRetVec2,(*this));
	return rkRetVec2;
}

inline
float& lmVec2::operator [] (unsigned int a_uiIndex)
{
	return v[a_uiIndex];
}

inline
const float& lmVec2::operator [] (unsigned int a_uiIndex) const
{
	return v[a_uiIndex];
}

inline
	lmVec2::operator float *()
{
	return v;
}

inline
	lmVec2::operator const float * () const
{
	return (const float*)v;
}

inline
bool lmVec2::operator == (const lmVec2& ac_rkArgL) const
{
	return lmVec2Equals((*this),ac_rkArgL);
}

inline
bool lmVec2::operator != (const lmVec2& ac_rkArgL) const
{
	return lmVec2NotEquals((*this),ac_rkArgL);
}

inline
float lmVec2::Length() const
{
	return lmVec2Length((*this));
}

inline
float lmVec2::LengthSqr() const
{
	return lmVec2LengthSqr((*this));
}

inline
void lmVec2::Normalise()
{
	lmVec2Normalise((*this),(*this));
}

inline
void lmVec2::Maximize()
{
	lmVec2Maximise((*this),(*this));
}

inline
void lmVec2::Minimize()
{
	lmVec2Minimise((*this),(*this));
}

inline
float lmVec2::DotProduct(const lmVec2& ac_rkArgL) const
{
	return lmVec2DotProduct((*this),ac_rkArgL);
}