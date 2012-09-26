#ifndef __LMMATRIX3_H_
#define __LMMATRIX3_H_

#include "lmVec3.h"

class lmMatrix3
{
public:
	lmMatrix3();
	lmMatrix3(const lmMatrix3&);
	lmMatrix3(float a_f00,float a_f01,float a_f02,float a_f10,float a_f11,float a_f12,float a_f20,float a_f21,float a_f22);
	~lmMatrix3();

	void operator = (const lmMatrix3& a_rkCopy);

	void Set(float a_f00,float a_f01,float a_f02,float a_f10,float a_f11,float a_f12,float a_f20,float a_f21,float a_f22);

	union
	{
		struct
		{
			float m_f00;
			float m_f01;
			float m_f02;

			float m_f10;
			float m_f11;
			float m_f12;

			float m_f20;
			float m_f21;
			float m_f22;
		};

		struct
		{
			LmVec3 m_kRowX;
			LmVec3 m_kRowY;
			LmVec3 m_kRowZ;
		};

		float m_m[3][3];
		float m_v[9];
	};

private:
	void Construct();

};

typedef void (*lmMatrix3_void_lmMatrix3_ClmMatrix3_ClmMatrix3)(lmMatrix3&,const lmMatrix3&,const lmMatrix3&);
typedef void (*lmMatrix3_void_lmMatrix3_ClmMatrix3_float)(lmMatrix3&,const lmMatrix3&,float);
typedef void (*lmMatrix3_void_lmMatrix3_float_float_float)(lmMatrix3&,float,float,float);
typedef void (*lmMatrix3_void_lmMatrix3_float)(lmMatrix3&,float);
typedef void (*lmMatrix3_void_lmMatrix3_ClmVec3)(lmMatrix3&,const LmVec3&);
typedef void (*lmMatrix3_void_lmVec3_ClmMatrix3_ClmVec3)(LmVec3&,const lmMatrix3,const LmVec3);

//void(lmMatrix3&,const lmMatrix3,const lmMatrix3);
//lmMatrix3_void_lmMatrix3_ClmMatrix3_ClmMatrix3 lmMatrix3Mul;

//void(lmMatrix3&,float)
extern lmMatrix3_void_lmMatrix3_float lmMatrix3MakeXRot;
extern lmMatrix3_void_lmMatrix3_float lmMatrix3MakeYRot;
extern lmMatrix3_void_lmMatrix3_float lmMatrix3MakeZRot;

////void(lmMatrix3&,float,float,float)
//lmMatrix3_void_lmMatrix3_float_float_float lmMatrix3MakeEuler;
//
////void(lmMatrix3&,float)
//lmMatrix3_void_lmMatrix3_float lmMatrix3MakeScale;
//
////void(lmMatrix3&,const lmVec3&)
//lmMatrix3_void_lmMatrix3_ClmVec3 lmMatrixMakeEuler;
//
////void(lmVec3&,const lmMatrix3&,const lmVec3&)
//lmMatrix3Func lmMatrix3Transform;

#include "lmMatrix3.inl"

#endif//__LMMATRIX3_H_