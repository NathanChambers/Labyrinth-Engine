#ifndef __LMVEC3_H_
#define __LMVEC3_H_

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//LmVec3 Dec
class LmVec3
{
	friend class LmBoot;
public:
	//Constructors
	LmVec3();
	LmVec3(float a_fX, float a_fY, float a_fZ);
	LmVec3(const LmVec3& ac_rkCopy);
	LmVec3(float* a_afVector);
	LmVec3& operator = (const LmVec3& ac_rkCopy);
	LmVec3& operator = (float* a_afVector);
	~LmVec3();

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
	static const LmVec3 ZERO;
	static const LmVec3 POSX;
	static const LmVec3 POSY;
	static const LmVec3 POSZ;
	static const LmVec3 NEGX;
	static const LmVec3 NEGY;
	static const LmVec3 NEGZ;

	//Regular Functions
	void Set(float a_fX, float a_fY, float a_fZ);

	void Normalise();
	void Maximize();
	void Minimize();

	float DotProduct(const LmVec3&) const;
	LmVec3 CrossProduct(const LmVec3&) const;

	float Length() const;
	float LenghtSqr() const;

	//Operators
	LmVec3 operator + (const LmVec3&) const;
	LmVec3 operator - (const LmVec3&) const;
	LmVec3& operator += (const LmVec3&);
	LmVec3& operator -= (const LmVec3&);

	LmVec3 operator * (float) const;
	LmVec3 operator / (float) const;
	LmVec3& operator *= (float);
	LmVec3& operator /= (float);

	LmVec3 operator - ();

	float& operator [] (unsigned int);
	const float& operator [] (unsigned int) const;

	bool operator == (const LmVec3&) const;
	bool operator != (const LmVec3&) const;

private:
	static void Construct();
};

////////////////////////////////////////////////////////////////////////////////
//Function Pointer Dec
typedef bool (*lmVec3_Bool_CVec3_CVec3)(const LmVec3&,const LmVec3&);

typedef void (*lmVec3_Void_Vec3_CVec3)(LmVec3&,const LmVec3&);
typedef void (*lmVec3_Void_Vec3_CVec3_Float)(LmVec3&,const LmVec3&,float);
typedef void (*lmVec3_Void_Vec3_CVec3_CVec3)(LmVec3&,const LmVec3&,const LmVec3&);		

typedef float (*lmVec3_Float_CVec3)(const LmVec3&);
typedef float (*lmVec3_Float_CVec3_CVec3)(const LmVec3&,const LmVec3&);

////////////////////////////////////////////////////////////////////////////////
//bool(const LmVec3&, const LmVec3&)
extern lmVec3_Bool_CVec3_CVec3 LmVec3Equals;
extern lmVec3_Bool_CVec3_CVec3 LmVec3NotEquals;

////////////////////////////////////////////////////////////////////////////////
//void (LmVec3&, const LmVec3&)
extern lmVec3_Void_Vec3_CVec3 LmVec3Normalise;
extern lmVec3_Void_Vec3_CVec3 LmVec3Maximise;
extern lmVec3_Void_Vec3_CVec3 LmVec3Minimise;
extern lmVec3_Void_Vec3_CVec3 LmVec3Negative;

////////////////////////////////////////////////////////////////////////////////
//void (LmVec3&, const LmVec3&, float)
extern lmVec3_Void_Vec3_CVec3_Float LmVec3Mul;
extern lmVec3_Void_Vec3_CVec3_Float LmVec3Div;

////////////////////////////////////////////////////////////////////////////////
//void (LmVec3&, const LmVec3&, const LmVec3&)
extern lmVec3_Void_Vec3_CVec3_CVec3 LmVec3Add;
extern lmVec3_Void_Vec3_CVec3_CVec3 LmVec3Sub;
extern lmVec3_Void_Vec3_CVec3_CVec3 LmVec3CrossProduct;

////////////////////////////////////////////////////////////////////////////////
//float (const LmVec3&)
extern lmVec3_Float_CVec3 LmVec3Length;
extern lmVec3_Float_CVec3 LmVec3LengthSqr;

////////////////////////////////////////////////////////////////////////////////
//float (cosnt LmVec3&, const LmVec3&)
extern lmVec3_Float_CVec3_CVec3 LmVec3DotProduct;

#include "lmVec3.inl"

////////////////////////////////////////////////////////////////////////////////

#endif//__LMVEC3_H_
