#include "lmBoot.h"
#include "lmCore.h"

#include <stdio.h>
using namespace Labyrinth;

lmBoot lmBoot::m_kBoot;

lmBoot::lmBoot()
{
	Construct();
}

void lmBoot::Construct()
{
	lmVec4::Construct();
}