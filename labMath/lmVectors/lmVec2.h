#ifndef __LMVEC2_H_
#define __LMVEC2_H_

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//lmVec2 Dec
class lmVec2
{
	friend class LmBoot;
public:
	//Constructors
	lmVec2();
	lmVec2(float a_fX, float a_fY);
	lmVec2(const lmVec2& ac_rkCopy);
	lmVec2(float* a_afVector);
	lmVec2& operator = (const lmVec2& ac_rkCopy);
	lmVec2& operator = (float* a_afVector);
	~lmVec2();

	//Class Data
	union
	{
		struct
		{
			float x;
			float y;
		};
		float v[2];
	};

	//Static Variables
	static const lmVec2 ZERO;
	static const lmVec2 POSX;
	static const lmVec2 POSY;
	static const lmVec2 NEGX;
	static const lmVec2 NEGY;

	//Regular Functions
	void Set(float a_fX, float a_fY);

	void Normalise();
	void Maximize();
	void Minimize();

	float DotProduct(const lmVec2&) const;

	float Length() const;
	float LengthSqr() const;

	//Operators
	lmVec2 operator + (const lmVec2&) const;
	lmVec2 operator - (const lmVec2&) const;
	lmVec2& operator += (const lmVec2&);
	lmVec2& operator -= (const lmVec2&);

	lmVec2 operator * (float) const;
	lmVec2 operator / (float) const;
	lmVec2& operator *= (float);
	lmVec2& operator /= (float);

	lmVec2 operator - ();

	float& operator [] (unsigned int);
	const float& operator [] (unsigned int) const;

	operator float* ();
	operator const float*() const;

	bool operator == (const lmVec2&) const;
	bool operator != (const lmVec2&) const;

private:
	static void Construct();
};

////////////////////////////////////////////////////////////////////////////////
//Function Pointer Dec
typedef bool (*lmVec2_Bool_CVec2_CVec2)(const lmVec2&,const lmVec2&);

typedef void (*lmVec2_Void_Vec2_CVec2)(lmVec2&,const lmVec2&);
typedef void (*lmVec2_Void_Vec2_CVec2_Float)(lmVec2&,const lmVec2&,float);
typedef void (*lmVec2_Void_Vec2_CVec2_CVec2)(lmVec2&,const lmVec2&,const lmVec2&);		

typedef float (*lmVec2_Float_CVec2)(const lmVec2&);
typedef float (*lmVec2_Float_CVec2_CVec2)(const lmVec2&,const lmVec2&);

////////////////////////////////////////////////////////////////////////////////
//bool(const lmVec2&, const lmVec2&)
extern lmVec2_Bool_CVec2_CVec2 lmVec2Equals;
extern lmVec2_Bool_CVec2_CVec2 lmVec2NotEquals;

////////////////////////////////////////////////////////////////////////////////
//void (lmVec2&, const lmVec2&)
extern lmVec2_Void_Vec2_CVec2 lmVec2Normalise;
extern lmVec2_Void_Vec2_CVec2 lmVec2Maximise;
extern lmVec2_Void_Vec2_CVec2 lmVec2Minimise;
extern lmVec2_Void_Vec2_CVec2 lmVec2Negative;

////////////////////////////////////////////////////////////////////////////////
//void (lmVec2&, const lmVec2&, float)
extern lmVec2_Void_Vec2_CVec2_Float lmVec2Mul;
extern lmVec2_Void_Vec2_CVec2_Float lmVec2Div;

////////////////////////////////////////////////////////////////////////////////
//void (lmVec2&, const lmVec2&, const lmVec2&)
extern lmVec2_Void_Vec2_CVec2_CVec2 lmVec2Add;
extern lmVec2_Void_Vec2_CVec2_CVec2 lmVec2Sub;

////////////////////////////////////////////////////////////////////////////////
//float (const lmVec2&)
extern lmVec2_Float_CVec2 lmVec2Length;
extern lmVec2_Float_CVec2 lmVec2LengthSqr;

////////////////////////////////////////////////////////////////////////////////
//float (cosnt lmVec2&, const lmVec2&)
extern lmVec2_Float_CVec2_CVec2 lmVec2DotProduct;

#include "lmVec2.inl"

////////////////////////////////////////////////////////////////////////////////

#endif//__LMVec2_H_
