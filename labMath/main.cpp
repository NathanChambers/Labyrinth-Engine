#include "lmCore.h"
#include <stdio.h>
#include <crtdbg.h>
#include <math.h>
#include <Windows.h>

LARGE_INTEGER kStart;
LARGE_INTEGER kEnd;
LARGE_INTEGER kFreq;

const int TEST_ITERATIONS = 1600000;
const float FLOAT_TOLLERANCE = 0.0001f;
bool PRINT_RESULTS = false;

void PrintVec4(const lmVec4& ac_rkArgIn)
{
	printf("X:%f Y:%f Z:%f W:%f \n",ac_rkArgIn.x,ac_rkArgIn.y,ac_rkArgIn.z,ac_rkArgIn.w);
}

//Returns 0 if it passes
bool PrintResult(bool a_bPassed,const char* a_szFunction)
{
	if(PRINT_RESULTS)
	{
		if(a_bPassed)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			printf("PASS \t- %s \n",a_szFunction);
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			printf("FAILED \t- %s \n",a_szFunction);
		}
	}

	return !a_bPassed;
}

//Tests all Vec3 Functions
bool Vec3Testing()
{
	int iTracker = 0;

	lmVec3 kVec0(1,2,3);
	lmVec3 kVec1(4,3,2);
	lmVec3 kVec2 = lmVec3::ZERO;
	lmVec3 kRet;
	float fRet;

	//Compare
	iTracker += PrintResult(lmVec3Equals(kVec0,kVec0),"EQUALS");
	iTracker += PrintResult(lmVec3NotEquals(kVec0,kVec1),"NOT EQUALS");

	//Arithmatic
	lmVec3Add(kRet,kVec0,kVec1);
	iTracker += PrintResult(kRet == lmVec3(5.0f,5.0f,5.0f),"ADD");

	lmVec3Sub(kRet,kVec0,kVec1);
	iTracker += PrintResult(kRet == lmVec3(-3.0f,-1.0f,1.0f),"SUB");

	lmVec3Mul(kRet,kVec0,2.0f);
	iTracker += PrintResult(kRet == lmVec3(2.0f,4.0f,6.0f),"MUL");

	lmVec3Div(kRet,kVec0,2.0f);
	iTracker += PrintResult(kRet == lmVec3(0.5f,1.0f,1.5f),"DIV");

	//Helper
	lmVec3Maximise(kRet,kVec0);
	iTracker += PrintResult(kRet == lmVec3(3.0f,3.0f,3.0f),"MAX");

	lmVec3Minimise(kRet,kVec0);
	iTracker += PrintResult(kRet == lmVec3(1.0f,1.0f,1.0f),"MIN");

	lmVec3Negative(kRet,kVec0);
	iTracker += PrintResult(kRet == lmVec3(-1.0f,-2.0f,-3.0f),"NEG");

	//Vector Math
	
	fRet = lmVec3Length(kVec0);
	iTracker += PrintResult(fRet < 3.7416f + FLOAT_TOLLERANCE && fRet > 3.7416f - FLOAT_TOLLERANCE,"LENGTH");

	fRet = lmVec3LengthSqr(kVec0);
	iTracker += PrintResult(fRet < 14.0f + FLOAT_TOLLERANCE && fRet > 14.0f - FLOAT_TOLLERANCE,"LENGTH SQR");

	lmVec3 kVec3(1,1,1);
	lmVec3Normalise(kRet,kVec3);
	iTracker += PrintResult(kRet == lmVec3(0.5773502691f,0.5773502691f,0.5773502691f),"NORMALISE");

	fRet = lmVec3DotProduct(kRet,kRet);
	iTracker += PrintResult(fRet > 1.0f - FLOAT_TOLLERANCE && fRet < 1 + FLOAT_TOLLERANCE,"DOT");

	lmVec3CrossProduct(kRet,lmVec3(1,0,0),lmVec3(0,1,0));
	iTracker += PrintResult(kRet == lmVec3(0,0,1),"CROSS");

	return iTracker == 0;
}

bool Vec4Testing()
{
	int iTracker = 0;

	lmVec4 kVec0(1,2,3,4);
	lmVec4 kVec1(4,3,2,1);
	lmVec4 kVec2 = lmVec4::ZERO;
	lmVec4 kRet;
	float fRet;

	//Compare
	iTracker += PrintResult(lmVec4Equals(kVec0,kVec0),"EQUALS");
	iTracker += PrintResult(lmVec4NotEquals(kVec0,kVec1),"NOT EQUALS");

	//Arithmatic
	lmVec4Add(kRet,kVec0,kVec1);
	iTracker += PrintResult(kRet == lmVec4(5.0f,5.0f,5.0f,5.0f),"ADD");

	lmVec4Sub(kRet,kVec0,kVec1);
	iTracker += PrintResult(kRet == lmVec4(-3.0f,-1.0f,1.0f,3.0f),"SUB");

	lmVec4Mul(kRet,kVec0,2.0f);
	iTracker += PrintResult(kRet == lmVec4(2.0f,4.0f,6.0f,8.0f),"MUL");

	lmVec4Div(kRet,kVec0,2.0f);
	iTracker += PrintResult(kRet == lmVec4(0.5f,1.0f,1.5f,2.0f),"DIV");

	//Helper
	lmVec4Maximise(kRet,kVec0);
	iTracker += PrintResult(kRet == lmVec4(4.0f,4.0f,4.0f,4.0f),"MAX");

	lmVec4Minimise(kRet,kVec0);
	iTracker += PrintResult(kRet == lmVec4(1.0f,1.0f,1.0f,1.0f),"MIN");

	lmVec4Negative(kRet,kVec0);
	iTracker += PrintResult(kRet == lmVec4(-1.0f,-2.0f,-3.0f,-4.0f),"NEG");

	//Vector Math
	
	fRet = lmVec4Length(kVec0);
	iTracker += PrintResult(fRet < 5.4772f + FLOAT_TOLLERANCE && fRet > 5.4772f - FLOAT_TOLLERANCE,"LENGTH");

	fRet = lmVec4LengthSqr(kVec0);
	iTracker += PrintResult(fRet < 30.0f + FLOAT_TOLLERANCE && fRet > 30.0f - FLOAT_TOLLERANCE,"LENGTH SQR");

	lmVec4 kVec3(1,1,1,1);
	lmVec4Normalise(kRet,kVec3);
	iTracker += PrintResult(kRet == lmVec4(0.5f,0.5f,0.5f,0.5f),"NORMALISE");

	fRet = lmVec4DotProduct(kRet,kRet);
	iTracker += PrintResult(fRet == 1.0f,"DOT");
	kVec0 = lmVec4(1,2,3,4);

	lmVec4CrossProduct(kRet,lmVec4(1,0,0),lmVec4(0,1,0));
	iTracker += PrintResult(kRet == lmVec4(0,0,1),"CROSS");

	return iTracker == 0;
}

int main()
{
	_CrtDumpMemoryLeaks();

	bool bRunning = true;
	while(bRunning)
	{
		lmSetIntrinsic(LM_INTRIN_STD);
		printf("STD TEST \n");
		QueryPerformanceFrequency(&kFreq);
		QueryPerformanceCounter(&kStart);

		for(int i = 0;i < TEST_ITERATIONS;++i)
		{
			Vec4Testing();
		}

		QueryPerformanceCounter(&kEnd);

		float fSTDTimeTaken = (float)(((float)kEnd.QuadPart - (float)kStart.QuadPart) / (float)kFreq.QuadPart);
		printf("Time Taken : %f \n",fSTDTimeTaken);

		lmSetIntrinsic(LM_INTRIN_ISPC);
		printf("ISPC TEST \n");
		QueryPerformanceFrequency(&kFreq);
		QueryPerformanceCounter(&kStart);

		for(int i = 0;i < TEST_ITERATIONS;++i)
		{
			Vec4Testing();
		}

		QueryPerformanceCounter(&kEnd);

		float fISCPTimeTaken = (float)(((float)kEnd.QuadPart - (float)kStart.QuadPart) / (float)kFreq.QuadPart);
		printf("Time Taken : %f \n\n",fISCPTimeTaken);

		printf("PERFORMANCE INCREASE %%%f \n", ((fSTDTimeTaken - fISCPTimeTaken) / fSTDTimeTaken) * 100);

		getchar();
	}
	return 0;
}