#ifndef __LAB_VEC4_H_
#define __LAB_VEC4_H_

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//LmVec4 Dec
class LmVec4
{
	friend class LmBoot;
public:
	//Constructors
	LmVec4();
	LmVec4(float a_fX, float a_fY, float a_fZ, float a_fW = 1.0f);
	LmVec4(const LmVec4& ac_rkCopy);
	LmVec4(float* a_afVector);
	LmVec4& operator = (const LmVec4& ac_rkCopy);
	LmVec4& operator = (float* a_afVector);
	~LmVec4();

	//Class Data
	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
		float v[4];
	};

	//Static Variables
	static const LmVec4 ZERO;
	static const LmVec4 POSX;
	static const LmVec4 POSY;
	static const LmVec4 POSZ;
	static const LmVec4 NEGX;
	static const LmVec4 NEGY;
	static const LmVec4 NEGZ;

	//Regular Functions
	void Set(float a_fX, float a_fY, float a_fZ, float a_fW = 1.0f);

	void Normalise();
	void Maximize();
	void Minimize();

	float DotProduct(const LmVec4&) const;
	LmVec4 CrossProduct(const LmVec4&) const;

	float Length() const;
	float LenghtSqr() const;

	//Operators
	LmVec4 operator + (const LmVec4&) const;
	LmVec4 operator - (const LmVec4&) const;
	LmVec4& operator += (const LmVec4&);
	LmVec4& operator -= (const LmVec4&);

	LmVec4 operator * (float) const;
	LmVec4 operator / (float) const;
	LmVec4& operator *= (float);
	LmVec4& operator /= (float);

	LmVec4 operator - ();

	float& operator [] (unsigned int);
	const float& operator [] (unsigned int) const;

	bool operator == (const LmVec4&) const;
	bool operator != (const LmVec4&) const;

private:
	static void Construct();
};

////////////////////////////////////////////////////////////////////////////////
//Function Pointer Dec
typedef bool (*lmVec4_Bool_CVec4_CVec4)(const LmVec4&,const LmVec4&);

typedef void (*lmVec4_Void_Vec4_CVec4)(LmVec4&,const LmVec4&);
typedef void (*lmVec4_Void_Vec4_CVec4_Float)(LmVec4&,const LmVec4&,float);
typedef void (*lmVec4_Void_Vec4_CVec4_CVec4)(LmVec4&,const LmVec4&,const LmVec4&);		

typedef float (*lmVec4_Float_CVec4)(const LmVec4&);
typedef float (*lmVec4_Float_CVec4_CVec4)(const LmVec4&,const LmVec4&);

////////////////////////////////////////////////////////////////////////////////
//bool(const LmVec4&, const LmVec4&)
extern lmVec4_Bool_CVec4_CVec4 LmVec4Equals;
extern lmVec4_Bool_CVec4_CVec4 LmVec4NotEquals;

////////////////////////////////////////////////////////////////////////////////
//void (LmVec4&, const LmVec4&)
extern lmVec4_Void_Vec4_CVec4 LmVec4Normalise;
extern lmVec4_Void_Vec4_CVec4 LmVec4Maximise;
extern lmVec4_Void_Vec4_CVec4 LmVec4Minimise;
extern lmVec4_Void_Vec4_CVec4 LmVec4Negative;

////////////////////////////////////////////////////////////////////////////////
//void (LmVec4&, const LmVec4&, float)
extern lmVec4_Void_Vec4_CVec4_Float LmVec4Mul;
extern lmVec4_Void_Vec4_CVec4_Float LmVec4Div;

////////////////////////////////////////////////////////////////////////////////
//void (LmVec4&, const LmVec4&, const LmVec4&)
extern lmVec4_Void_Vec4_CVec4_CVec4 LmVec4Add;
extern lmVec4_Void_Vec4_CVec4_CVec4 LmVec4Sub;
extern lmVec4_Void_Vec4_CVec4_CVec4 LmVec4CrossProduct;

////////////////////////////////////////////////////////////////////////////////
//float (const LmVec4&)
extern lmVec4_Float_CVec4 LmVec4Length;
extern lmVec4_Float_CVec4 LmVec4LengthSqr;

////////////////////////////////////////////////////////////////////////////////
//float (cosnt LmVec4&, const LmVec4&)
extern lmVec4_Float_CVec4_CVec4 LmVec4DotProduct;

#include "lmVec4.inl"

////////////////////////////////////////////////////////////////////////////////

#endif//__LAB_VEC4_H_
