#ifndef __LMMATRIX4_H_
#define __LMMATRIX4_H_

#include "lmVec4.h"

class lmMatrix4
{
	friend LmBoot;
public:
	lmMatrix4();
	lmMatrix4(const lmMatrix4&);
	lmMatrix4(float a_f00,float a_f01,float a_f02,float a_f03,
		float a_f10,float a_f11,float a_f12,float a_f13,
		float a_f20,float a_f21,float a_f22,float a_f23,
		float a_f30,float a_f31,float a_f32,float a_f33);

	~lmMatrix4();

	void operator = (const lmMatrix4& a_rkCopy);

	void Set(float a_f00,float a_f01,float a_f02,float a_f03,
		float a_f10,float a_f11,float a_f12,float a_f13,
		float a_f20,float a_f21,float a_f22,float a_f23,
		float a_f30,float a_f31,float a_f32,float a_f33);

	union
	{
		struct
		{
			float m_f00;
			float m_f01;
			float m_f02;
			float m_f03;

			float m_f10;
			float m_f11;
			float m_f12;
			float m_f13;

			float m_f20;
			float m_f21;
			float m_f22;
			float m_f23;

			float m_f30;
			float m_f31;
			float m_f32;
			float m_f33;
		};

		struct
		{
			LmVec4 m_kRowX;
			LmVec4 m_kRowY;
			LmVec4 m_kRowZ;
			LmVec4 m_kRowW;
		};

		float m_m[4][4];
		float m_v[16];
		
	};

	void MakeXRotate(float a_fTheta);
	void MakeYRotate(float a_fTheta);
	void MakeZRotate(float a_fTheta);

	lmMatrix4 operator * (const lmMatrix4& a_rkArgL);
	lmMatrix4& operator *= (const lmMatrix4& a_rkArgL);

	static const lmMatrix4 IDENTITY;

private:
	static void Construct();
};

typedef void (*lmMatrix4_void_lmMatrix4_float)(lmMatrix4&,float);
typedef void (*lmMatrix4_void_lmMatrix4_ClmMatrix4_ClmMatrix4)(lmMatrix4&,const lmMatrix4&,const lmMatrix4&);

//void(lmMatrix4&,const lmMatrix4&,const lmMatrix4&)
extern lmMatrix4_void_lmMatrix4_ClmMatrix4_ClmMatrix4 lmMatrix4Mul;

//void(lmMatrix4&,float)
extern lmMatrix4_void_lmMatrix4_float lmMatrix4MakeXRot;
extern lmMatrix4_void_lmMatrix4_float lmMatrix4MakeYRot;
extern lmMatrix4_void_lmMatrix4_float lmMatrix4MakeZRot;

#include "lmMatrix4.inl"

#endif//__LMMATRIX3_H_