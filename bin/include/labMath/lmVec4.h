#ifndef __LMVEC4_H_
#define __LMVEC4_H_

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//lmVec4 Dec
class lmVec4
{
	friend class LmBoot;
public:
	//Constructors
	lmVec4();
	lmVec4(float a_fX, float a_fY, float a_fZ, float a_fW = 1.0f);
	lmVec4(const lmVec4& ac_rkCopy);
	lmVec4(float* a_afVector);
	lmVec4& operator = (const lmVec4& ac_rkCopy);
	lmVec4& operator = (float* a_afVector);
	~lmVec4();

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
	static const lmVec4 ZERO;
	static const lmVec4 POSX;
	static const lmVec4 POSY;
	static const lmVec4 POSZ;
	static const lmVec4 NEGX;
	static const lmVec4 NEGY;
	static const lmVec4 NEGZ;

	//Regular Functions
	void Set(float a_fX, float a_fY, float a_fZ, float a_fW = 1.0f);

	void Normalise();
	void Maximize();
	void Minimize();

	float DotProduct(const lmVec4&) const;
	lmVec4 CrossProduct(const lmVec4&,const lmVec4&) const;

	float Length() const;
	float LenghtSqr() const;

	//Operators
	lmVec4 operator + (const lmVec4&) const;
	lmVec4 operator - (const lmVec4&) const;
	lmVec4& operator += (const lmVec4&);
	lmVec4& operator -= (const lmVec4&);

	lmVec4 operator * (float) const;
	lmVec4 operator / (float) const;
	lmVec4& operator *= (float);
	lmVec4& operator /= (float);

	lmVec4 operator - ();

	float& operator [] (unsigned int);
	const float& operator [] (unsigned int) const;

	operator float* ();
	operator const float*() const;

	bool operator == (const lmVec4&) const;
	bool operator != (const lmVec4&) const;

private:
	static void Construct();
};

////////////////////////////////////////////////////////////////////////////////
//Function Pointer Dec
typedef bool (*lmVec4_Bool_CVec4_CVec4)(const lmVec4&,const lmVec4&);

typedef void (*lmVec4_Void_Vec4_CVec4)(lmVec4&,const lmVec4&);
typedef void (*lmVec4_Void_Vec4_CVec4_Float)(lmVec4&,const lmVec4&,float);
typedef void (*lmVec4_Void_Vec4_CVec4_CVec4)(lmVec4&,const lmVec4&,const lmVec4&);		

typedef float (*lmVec4_Float_CVec4)(const lmVec4&);
typedef float (*lmVec4_Float_CVec4_CVec4)(const lmVec4&,const lmVec4&);

////////////////////////////////////////////////////////////////////////////////
//bool(const lmVec4&, const lmVec4&)
extern lmVec4_Bool_CVec4_CVec4 lmVec4Equals;
extern lmVec4_Bool_CVec4_CVec4 lmVec4NotEquals;

////////////////////////////////////////////////////////////////////////////////
//void (lmVec4&, const lmVec4&)
extern lmVec4_Void_Vec4_CVec4 lmVec4Normalise;
extern lmVec4_Void_Vec4_CVec4 lmVec4Maximise;
extern lmVec4_Void_Vec4_CVec4 lmVec4Minimise;
extern lmVec4_Void_Vec4_CVec4 lmVec4Negative;

////////////////////////////////////////////////////////////////////////////////
//void (lmVec4&, const lmVec4&, float)
extern lmVec4_Void_Vec4_CVec4_Float lmVec4Mul;
extern lmVec4_Void_Vec4_CVec4_Float lmVec4Div;

////////////////////////////////////////////////////////////////////////////////
//void (lmVec4&, const lmVec4&, const lmVec4&)
extern lmVec4_Void_Vec4_CVec4_CVec4 lmVec4Add;
extern lmVec4_Void_Vec4_CVec4_CVec4 lmVec4Sub;
extern lmVec4_Void_Vec4_CVec4_CVec4 lmVec4CrossProduct;

////////////////////////////////////////////////////////////////////////////////
//float (const lmVec4&)
extern lmVec4_Float_CVec4 lmVec4Length;
extern lmVec4_Float_CVec4 lmVec4LengthSqr;

////////////////////////////////////////////////////////////////////////////////
//float (cosnt lmVec4&, const lmVec4&)
extern lmVec4_Float_CVec4_CVec4 lmVec4DotProduct;

#include "lmVec4.inl"

////////////////////////////////////////////////////////////////////////////////

#endif//__LMVEC4_H_
