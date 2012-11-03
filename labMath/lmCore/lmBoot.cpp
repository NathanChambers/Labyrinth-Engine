#include "LmBoot.h"
#include "lmCore.h"

#include <stdio.h>
#include <Windows.h>

bool lmBoot::m_bBooted = false;
extern LM_INTRIN_SET g_kIntrinsic;
extern LM_INTRIN_SET g_kNextIntrinsic;

lmBoot::lmBoot()
{
	if(!m_bBooted)
	{
		m_bBooted = true;

		//Create Intrinsic
		g_kIntrinsic = LM_INTRIN_STD;


		Construct();
	}
}

void lmBoot::Reboot() const
{
	if(g_kNextIntrinsic != LM_INTRIN_ERROR)
	{
		g_kIntrinsic = g_kNextIntrinsic;
		g_kNextIntrinsic = LM_INTRIN_ERROR;

		lmVec2::Construct();
		lmVec3::Construct();
		lmVec4::Construct();

		lmMatrix4::Construct();
	}
	else
	{
		printf("USE THE PROPER FUNCTION TO SWITCH INTRINSICS! \n");
		OutputDebugString("USE THE PROPER FUNCTION TO SWITCH INTRINSICS! \n");
	}

	g_kNextIntrinsic = LM_INTRIN_NONE;
}

void lmBoot::Construct()
{
	lmVec2::Construct();
	lmVec3::Construct();
	lmVec4::Construct();

	lmMatrix4::Construct();
}