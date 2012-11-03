#ifndef __LMMATRIX4_H_
#define __LMMATRIX4_H_

#include "lmVec4.h"

class lmMatrix4
{
	friend class lmBoot;
public:
	lmMatrix4();
	lmMatrix4(	float a_f11,float a_f12,float a_f13,float a_f14,
				float a_f21,float a_f22,float a_f23,float a_f24,
				float a_f31,float a_f32,float a_f33,float a_f34,
				float a_f41,float a_f42,float a_f43,float a_f44);

	~lmMatrix4();

	union
	{
		struct
		{
			float m_f11;
			float m_f12;
			float m_f13;
			float m_f14;

			float m_f21;
			float m_f22;
			float m_f23;
			float m_f24;

			float m_f31;
			float m_f32;
			float m_f33;
			float m_f34;

			float m_f41;
			float m_f42;
			float m_f43;
			float m_f44;
		};
		
		float m_v[16];
		float m_m[4][4];
	
	};

	void MakeXRotate(float a_fTheta);
	void MakeYRotate(float a_fTheta);
	void MakeZRotate(float a_fTheta);

	operator float* ();
	operator const float* () const;

	lmMatrix4 operator * (const lmMatrix4&);
	lmMatrix4& operator *= (const lmMatrix4&);

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