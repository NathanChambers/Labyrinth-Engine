#ifndef __LMVEC2_H_
#define __LMVEC2_H_

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//LmVec2 Dec
class LmVec2
{
	friend class LmBoot;
public:
	//Constructors
	LmVec2();
	LmVec2(float a_fX, float a_fY);
	LmVec2(const LmVec2& ac_rkCopy);
	LmVec2(float* a_afVector);
	LmVec2& operator = (const LmVec2& ac_rkCopy);
	LmVec2& operator = (float* a_afVector);
	~LmVec2();

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
	static const LmVec2 ZERO;
	static const LmVec2 POSX;
	static const LmVec2 POSY;
	static const LmVec2 NEGX;
	static const LmVec2 NEGY;

	//Regular Functions
	void Set(float a_fX, float a_fY);

	void Normalise();
	void Maximize();
	void Minimize();

	float DotProduct(const LmVec2&) const;

	float Length() const;
	float LenghtSqr() const;

	//Operators
	LmVec2 operator + (const LmVec2&) const;
	LmVec2 operator - (const LmVec2&) const;
	LmVec2& operator += (const LmVec2&);
	LmVec2& operator -= (const LmVec2&);

	LmVec2 operator * (float) const;
	LmVec2 operator / (float) const;
	LmVec2& operator *= (float);
	LmVec2& operator /= (float);

	LmVec2 operator - ();

	float& operator [] (unsigned int);
	const float& operator [] (unsigned int) const;

	bool operator == (const LmVec2&) const;
	bool operator != (const LmVec2&) const;

private:
	static void Construct();
};

////////////////////////////////////////////////////////////////////////////////
//Function Pointer Dec
typedef bool (*lmVec2_Bool_CVec2_CVec2)(const LmVec2&,const LmVec2&);

typedef void (*lmVec2_Void_Vec2_CVec2)(LmVec2&,const LmVec2&);
typedef void (*lmVec2_Void_Vec2_CVec2_Float)(LmVec2&,const LmVec2&,float);
typedef void (*lmVec2_Void_Vec2_CVec2_CVec2)(LmVec2&,const LmVec2&,const LmVec2&);		

typedef float (*lmVec2_Float_CVec2)(const LmVec2&);
typedef float (*lmVec2_Float_CVec2_CVec2)(const LmVec2&,const LmVec2&);

////////////////////////////////////////////////////////////////////////////////
//bool(const LmVec2&, const LmVec2&)
extern lmVec2_Bool_CVec2_CVec2 LmVec2Equals;
extern lmVec2_Bool_CVec2_CVec2 LmVec2NotEquals;

////////////////////////////////////////////////////////////////////////////////
//void (LmVec2&, const LmVec2&)
extern lmVec2_Void_Vec2_CVec2 LmVec2Normalise;
extern lmVec2_Void_Vec2_CVec2 LmVec2Maximise;
extern lmVec2_Void_Vec2_CVec2 LmVec2Minimise;
extern lmVec2_Void_Vec2_CVec2 LmVec2Negative;

////////////////////////////////////////////////////////////////////////////////
//void (LmVec2&, const LmVec2&, float)
extern lmVec2_Void_Vec2_CVec2_Float LmVec2Mul;
extern lmVec2_Void_Vec2_CVec2_Float LmVec2Div;

////////////////////////////////////////////////////////////////////////////////
//void (LmVec2&, const LmVec2&, const LmVec2&)
extern lmVec2_Void_Vec2_CVec2_CVec2 LmVec2Add;
extern lmVec2_Void_Vec2_CVec2_CVec2 LmVec2Sub;

////////////////////////////////////////////////////////////////////////////////
//float (const LmVec2&)
extern lmVec2_Float_CVec2 LmVec2Length;
extern lmVec2_Float_CVec2 LmVec2LengthSqr;

////////////////////////////////////////////////////////////////////////////////
//float (cosnt LmVec2&, const LmVec2&)
extern lmVec2_Float_CVec2_CVec2 LmVec2DotProduct;

#include "lmVec2.inl"

////////////////////////////////////////////////////////////////////////////////

#endif//__LMVec2_H_
