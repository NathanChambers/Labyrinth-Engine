#include "lmVec2.h"

inline
LmVec2::LmVec2()
{

}

inline
LmVec2::LmVec2(float a_fX ,float a_fY)
	: x(a_fX),y(a_fY)
{

}

inline
LmVec2::LmVec2(const LmVec2& ac_rkArgIn)
	:x(ac_rkArgIn.x),y(ac_rkArgIn.y)
{

}

inline
LmVec2::LmVec2(float* a_pfArgL)
	:x(a_pfArgL[0]),y(a_pfArgL[1])
{

}

inline
LmVec2::~LmVec2()
{

}

inline
void LmVec2::Set(float a_fX,float a_fY)
{
	x = a_fX;
	y = a_fY;
}

inline
LmVec2& LmVec2::operator = (const LmVec2& ac_pkArgL)
{
	x = ac_pkArgL.x;
	y = ac_pkArgL.y;
	return (*this);
}

inline
LmVec2& LmVec2::operator = (float* a_pfArgL)
{
	x = a_pfArgL[0];
	y = a_pfArgL[1];
	return (*this);
}

inline
LmVec2 LmVec2::operator + (const LmVec2& ac_rkArgL) const
{
	LmVec2 rkRetVec2;
	LmVec2Add(rkRetVec2,(*this),ac_rkArgL);
	return rkRetVec2;
}

inline
LmVec2 LmVec2::operator - (const LmVec2& ac_rkArgL) const
{
	LmVec2 rkRetVec2;
	LmVec2Sub(rkRetVec2,(*this),ac_rkArgL);
	return rkRetVec2;
}

inline
LmVec2& LmVec2::operator += (const LmVec2& ac_rkArgL)
{
	LmVec2Add((*this),(*this),ac_rkArgL);
	return (*this);
}

inline
LmVec2& LmVec2::operator -= (const LmVec2& ac_rkArgL)
{
	LmVec2Sub((*this),(*this),ac_rkArgL);
	return (*this);
}

inline
LmVec2 LmVec2::operator * (const float ac_fArg0) const
{
	LmVec2 rkRetVec2;
	LmVec2Mul(rkRetVec2,(*this),ac_fArg0);
	return rkRetVec2;
}

inline
LmVec2 LmVec2::operator / (const float ac_fArg0) const
{
	LmVec2 rkRetVec2;
	LmVec2Div(rkRetVec2,(*this),ac_fArg0);
	return rkRetVec2;
}

inline
LmVec2& LmVec2::operator *= (const float ac_fArg0)
{
	LmVec2Mul((*this),(*this),ac_fArg0);
	return (*this);
}

inline
LmVec2& LmVec2::operator /= (const float ac_fArg0)
{
	LmVec2Div((*this),(*this),ac_fArg0);
	return (*this);
}

inline
LmVec2 LmVec2::operator - ()
{
	LmVec2 rkRetVec2;
	LmVec2Negative(rkRetVec2,(*this));
	return rkRetVec2;
}

inline
float& LmVec2::operator [] (unsigned int a_uiIndex)
{
	return v[a_uiIndex];
}

inline
const float& LmVec2::operator [] (unsigned int a_uiIndex) const
{
	return v[a_uiIndex];
}

inline
bool LmVec2::operator == (const LmVec2& ac_rkArgL) const
{
	return LmVec2Equals((*this),ac_rkArgL);
}

inline
bool LmVec2::operator != (const LmVec2& ac_rkArgL) const
{
	return LmVec2NotEquals((*this),ac_rkArgL);
}

inline
float LmVec2::Length() const
{
	return LmVec2Length((*this));
}

inline
float LmVec2::LenghtSqr() const
{
	return LmVec2LengthSqr((*this));
}

inline
void LmVec2::Normalise()
{
	LmVec2Normalise((*this),(*this));
}

inline
void LmVec2::Maximize()
{
	LmVec2Maximise((*this),(*this));
}

inline
void LmVec2::Minimize()
{
	LmVec2Minimise((*this),(*this));
}

inline
float LmVec2::DotProduct(const LmVec2& ac_rkArgL) const
{
	return LmVec2DotProduct((*this),ac_rkArgL);
}