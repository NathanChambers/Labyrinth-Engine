#include "lmMatrix3.h"
#include <math.h>

void std_lmMatrix3MakeXRot(lmMatrix3& a_rkArgOut,float a_fTheta)
{
	float c = cosf(a_fTheta);
	float s = sinf(a_fTheta);
	a_rkArgOut.m_f00 = 1; a_rkArgOut.m_f01 = 0; a_rkArgOut.m_f01 = 0;
	a_rkArgOut.m_f00 = 0; a_rkArgOut.m_f01 = c; a_rkArgOut.m_f01 = s;
	a_rkArgOut.m_f00 = 0; a_rkArgOut.m_f01 = -s; a_rkArgOut.m_f01 = c;
}

void std_lmMatrix3MakeYRot(lmMatrix3& a_rkArgOut,float a_fTheta)
{
	float c = cosf(a_fTheta);
	float s = sinf(a_fTheta);
	a_rkArgOut.m_f00 = c; a_rkArgOut.m_f01 = 0; a_rkArgOut.m_f01 = s;
	a_rkArgOut.m_f00 = 0; a_rkArgOut.m_f01 = 1; a_rkArgOut.m_f01 = 0;
	a_rkArgOut.m_f00 = -s; a_rkArgOut.m_f01 = 0; a_rkArgOut.m_f01 = c;
}

void std_lmMatrix3MakeZRot(lmMatrix3& a_rkArgOut,float a_fTheta)
{
	float c = cosf(a_fTheta);
	float s = sinf(a_fTheta);
	a_rkArgOut.m_f00 = c; a_rkArgOut.m_f01 = s; a_rkArgOut.m_f01 = 0;
	a_rkArgOut.m_f00 = -s; a_rkArgOut.m_f01 = c; a_rkArgOut.m_f01 = 0;
	a_rkArgOut.m_f00 = 0; a_rkArgOut.m_f01 = 0; a_rkArgOut.m_f01 = 1;
}

//void(lmMatrix3&,float)
lmMatrix3_void_lmMatrix3_float lmMatrix3MakeXRot = nullptr;
lmMatrix3_void_lmMatrix3_float lmMatrix3MakeYRot = nullptr;
lmMatrix3_void_lmMatrix3_float lmMatrix3MakeZRot = nullptr;

void lmMatrix3::Construct()
{
	lmMatrix3MakeXRot = &std_lmMatrix3MakeXRot;
	lmMatrix3MakeYRot = &std_lmMatrix3MakeYRot;
	lmMatrix3MakeZRot = &std_lmMatrix3MakeZRot;
}