#include "LmBoot.h"
#include "lmCore.h"

bool LmBoot::bBooted = false;

LmBoot::LmBoot()
{
	if(!bBooted)
	{
		Construct();
	}
}

void LmBoot::Construct()
{
	LmVec2::Construct();
	LmVec3::Construct();
	LmVec4::Construct();

	lmMatrix4::Construct();
}