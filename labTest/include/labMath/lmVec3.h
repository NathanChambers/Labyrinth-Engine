#ifndef __LMVEC3_H_
#define __LMVEC3_H_

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//lmVec3 Dec
class lmVec3
{
	friend class LmBoot;
public:
	//Constructors
	lmVec3();
	lmVec3(float a_fX, float a_fY, float a_fZ);
	lmVec3(const lmVec3& ac_rkCopy);
	lmVec3(float* a_afVector);
	lmVec3& operator = (const lmVec3& ac_rkCopy);
	lmVec3& operator = (float* a_afVector);
	~lmVec3();

	//Class Data
	union
	{
		struct
		{
			float x;
			float y;
			float z;
		};
		float v[3];
	};

	//Static Variables
	static const lmVec3 ZERO;
	static const lmVec3 POSX;
	static const lmVec3 POSY;
	static const lmVec3 POSZ;
	static const lmVec3 NEGX;
	static const lmVec3 NEGY;
	static const lmVec3 NEGZ;

	//Regular Functions
	void Set(float a_fX, float a_fY, float a_fZ);

	void Normalise();
	void Maximize();
	void Minimize();

	float DotProduct(const lmVec3&) const;
	lmVec3 CrossProduct(const lmVec3&) const;

	float Length() const;
	float LengthSqr() const;

	//Operators
	lmVec3 operator + (const lmVec3&) const;
	lmVec3 operator - (const lmVec3&) const;
	lmVec3& operator += (const lmVec3&);
	lmVec3& operator -= (const lmVec3&);

	lmVec3 operator * (float) const;
	lmVec3 operator / (float) const;
	lmVec3& operator *= (float);
	lmVec3& operator /= (float);

	lmVec3 operator - ();

	float& operator [] (unsigned int);
	const float& operator [] (unsigned int) const;

	operator const float*() const;
	operator float*();

	bool operator == (const lmVec3&) const;
	bool operator != (const lmVec3&) const;

private:
	static void Construct();
};

////////////////////////////////////////////////////////////////////////////////
//Function Pointer Dec
typedef bool (*lmVec3_Bool_CVec3_CVec3)(const lmVec3&,const lmVec3&);

typedef void (*lmVec3_Void_Vec3_CVec3)(lmVec3&,const lmVec3&);
typedef void (*lmVec3_Void_Vec3_CVec3_Float)(lmVec3&,const lmVec3&,float);
typedef void (*lmVec3_Void_Vec3_CVec3_CVec3)(lmVec3&,const lmVec3&,const lmVec3&);		

typedef float (*lmVec3_Float_CVec3)(const lmVec3&);
typedef float (*lmVec3_Float_CVec3_CVec3)(const lmVec3&,const lmVec3&);

////////////////////////////////////////////////////////////////////////////////
//bool(const lmVec3&, const lmVec3&)
extern lmVec3_Bool_CVec3_CVec3 lmVec3Equals;
extern lmVec3_Bool_CVec3_CVec3 lmVec3NotEquals;

////////////////////////////////////////////////////////////////////////////////
//void (lmVec3&, const lmVec3&)
extern lmVec3_Void_Vec3_CVec3 lmVec3Normalise;
extern lmVec3_Void_Vec3_CVec3 lmVec3Maximise;
extern lmVec3_Void_Vec3_CVec3 lmVec3Minimise;
extern lmVec3_Void_Vec3_CVec3 lmVec3Negative;

////////////////////////////////////////////////////////////////////////////////
//void (lmVec3&, const lmVec3&, float)
extern lmVec3_Void_Vec3_CVec3_Float lmVec3Mul;
extern lmVec3_Void_Vec3_CVec3_Float lmVec3Div;

////////////////////////////////////////////////////////////////////////////////
//void (lmVec3&, const lmVec3&, const lmVec3&)
extern lmVec3_Void_Vec3_CVec3_CVec3 lmVec3Add;
extern lmVec3_Void_Vec3_CVec3_CVec3 lmVec3Sub;
extern lmVec3_Void_Vec3_CVec3_CVec3 lmVec3CrossProduct;

////////////////////////////////////////////////////////////////////////////////
//float (const lmVec3&)
extern lmVec3_Float_CVec3 lmVec3Length;
extern lmVec3_Float_CVec3 lmVec3LengthSqr;

////////////////////////////////////////////////////////////////////////////////
//float (cosnt lmVec3&, const lmVec3&)
extern lmVec3_Float_CVec3_CVec3 lmVec3DotProduct;

#include "lmVec3.inl"

////////////////////////////////////////////////////////////////////////////////

#endif//__LMVEC3_H_
