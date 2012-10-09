export void ispcVec4Add(uniform float a_pkArgOut[],uniform const float ac_pkArgL[],uniform const float ac_pkArgR[])
{
	//a_pkArgOut[0] = ac_pkArgL[0] + ac_pkArgR[0];
	//a_pkArgOut[1] = ac_pkArgL[1] + ac_pkArgR[1];
	//a_pkArgOut[2] = ac_pkArgL[2] + ac_pkArgR[2];
	//a_pkArgOut[3] = ac_pkArgL[3] + ac_pkArgR[3];

	foreach(i = 0 ... 4)
	{
		a_pkArgOut[i] = ac_pkArgL[i] + ac_pkArgR[i];
	}
}

export void ispcVec4Sub(uniform float a_pkArgOut[],uniform const float ac_pkArgL[],uniform const float ac_pkArgR[])
{
	//a_pkArgOut[0] = ac_pkArgL[0] - ac_pkArgR[0];
	//a_pkArgOut[1] = ac_pkArgL[1] - ac_pkArgR[1];
	//a_pkArgOut[2] = ac_pkArgL[2] - ac_pkArgR[2];
	//a_pkArgOut[3] = ac_pkArgL[3] - ac_pkArgR[3];

	foreach(i = 0 ... 4)
	{
		a_pkArgOut[i] = ac_pkArgL[i] - ac_pkArgR[i];
	}
}

export void ispcVec4Mul(uniform float a_pkArgOut[],uniform const float ac_pkArgL[],uniform const float ac_fArgR)
{
	//a_pkArgOut[0] = ac_pkArgL[0] * ac_fArgR;
	//a_pkArgOut[1] = ac_pkArgL[1] * ac_fArgR;
	//a_pkArgOut[2] = ac_pkArgL[2] * ac_fArgR;
	//a_pkArgOut[3] = ac_pkArgL[3] * ac_fArgR;

	foreach(i = 0 ... 4)
	{
		a_pkArgOut[i] = ac_pkArgL[i] * ac_fArgR;
	}
}

export void ispcVec4Div(uniform float a_pkArgOut[],uniform const float ac_pkArgL[],uniform const float ac_fArgR)
{
	//a_pkArgOut[0] = ac_pkArgL[0] / ac_fArgR;
	//a_pkArgOut[1] = ac_pkArgL[1] / ac_fArgR;
	//a_pkArgOut[2] = ac_pkArgL[2] / ac_fArgR;
	//a_pkArgOut[3] = ac_pkArgL[3] / ac_fArgR;

	foreach(i = 0 ... 4)
	{
		a_pkArgOut[i] = ac_pkArgL[i] / ac_fArgR;
	}
}

export void ispcVec4Negative(uniform float a_pkArgOut[],uniform const float ac_pkArgL[])
{
	//a_pkArgOut[0] = -ac_pkArgL[0];
	//a_pkArgOut[1] = -ac_pkArgL[1];
	//a_pkArgOut[2] = -ac_pkArgL[2];
	//a_pkArgOut[3] = -ac_pkArgL[3];

	foreach(i = 0 ... 4)
	{
		a_pkArgOut[i] = -ac_pkArgL[i];
	}
}

export uniform bool ispcVec4Equals(uniform const float ac_pkArgL[],uniform const float ac_pkArgR[])
{
	return ac_pkArgL[0] == ac_pkArgR[0] &&  ac_pkArgL[1] == ac_pkArgR[1] &&  ac_pkArgL[2] == ac_pkArgR[2] &&  ac_pkArgL[3] == ac_pkArgR[3]; 
}

export uniform bool ispcVec4NotEquals(uniform const float ac_pkArgL[],uniform const float ac_pkArgR[])
{
	return ac_pkArgL[0] != ac_pkArgR[0] &&  ac_pkArgL[1] != ac_pkArgR[1] &&  ac_pkArgL[2] != ac_pkArgR[2] &&  ac_pkArgL[3] != ac_pkArgR[3];
}

export uniform float ispcVec4DotProduct(uniform const float ac_pkArgL[],uniform const float ac_pkArgR[])
{
	return ac_pkArgL[0] * ac_pkArgR[0] + ac_pkArgL[1] * ac_pkArgR[1] + ac_pkArgL[2] * ac_pkArgR[2] + ac_pkArgL[3] * ac_pkArgR[3];
}

export uniform float ispcVec4Length(uniform const float ac_pkArgL[])
{
	return sqrt(ac_pkArgL[0] * ac_pkArgL[0] + ac_pkArgL[1] * ac_pkArgL[1] + ac_pkArgL[2] * ac_pkArgL[2] + ac_pkArgL[3] * ac_pkArgL[3]);
}

export uniform float ispcVec4LengthSqr(uniform const float ac_pkArgL[])
{
	return ac_pkArgL[0] * ac_pkArgL[0] + ac_pkArgL[1] * ac_pkArgL[1] + ac_pkArgL[2] * ac_pkArgL[2] + ac_pkArgL[3] * ac_pkArgL[3];
}

export void ispcVec4Normalise(uniform float a_pkArgOut[],uniform const float ac_pkArgL[])
{
	uniform float fLength = sqrt(ac_pkArgL[0] * ac_pkArgL[0] + ac_pkArgL[1] * ac_pkArgL[1] + ac_pkArgL[2] * ac_pkArgL[2] + ac_pkArgL[3] * ac_pkArgL[3]);

	//a_pkArgOut[0] = ac_pkArgL[0] / fLength;
	//a_pkArgOut[1] = ac_pkArgL[1] / fLength;
	//a_pkArgOut[2] = ac_pkArgL[2] / fLength;
	//a_pkArgOut[3] = ac_pkArgL[3] / fLength;

	foreach(i = 0 ... 4)
	{
		a_pkArgOut[i] = ac_pkArgL[i] / fLength;
	}
}

export void ispcVec4Maximise(uniform float a_pkArgOut[],uniform const float ac_pkArgL[])
{
	uniform float fHighest = ac_pkArgL[0];
	if(ac_pkArgL[1] > fHighest)
		fHighest = ac_pkArgL[1];
	
	if(ac_pkArgL[2] > fHighest)
		fHighest = ac_pkArgL[2];

	if(ac_pkArgL[3] > fHighest)
		fHighest = ac_pkArgL[3];

	//a_pkArgOut[0] = fHighest;
	//a_pkArgOut[1] = fHighest;
	//a_pkArgOut[2] = fHighest;
	//a_pkArgOut[3] = fHighest;

	foreach(i = 0 ... 4)
	{
		a_pkArgOut[i] = fHighest;
	}
}

export void ispcVec4Minimise(uniform float a_pkArgOut[],uniform const float ac_pkArgL[])
{
	uniform float fLowest = ac_pkArgL[0];
	if(ac_pkArgL[1] < fLowest)
		fLowest = ac_pkArgL[1];
	
	if(ac_pkArgL[2] < fLowest)
		fLowest = ac_pkArgL[2];

	if(ac_pkArgL[3] < fLowest)
		fLowest = ac_pkArgL[3];

	//a_pkArgOut[0] = fLowest;
	//a_pkArgOut[1] = fLowest;
	//a_pkArgOut[2] = fLowest;
	//a_pkArgOut[3] = fLowest;

	foreach(i = 0 ... 4)
	{
		a_pkArgOut[i] = fLowest;
	}
}

export void ispcVec4CrossProduct(uniform float a_pkArgOut[],uniform const float ac_pkArgL[],uniform const float ac_pkArgR[])
{
	a_pkArgOut[0] = (ac_pkArgL[1] * ac_pkArgR[2]) - (ac_pkArgL[2] * ac_pkArgR[1]);
	a_pkArgOut[1] = (ac_pkArgL[2] * ac_pkArgR[0]) - (ac_pkArgL[0] * ac_pkArgR[2]);
	a_pkArgOut[2] = (ac_pkArgL[0] * ac_pkArgR[1]) - (ac_pkArgL[1] * ac_pkArgR[0]);
	a_pkArgOut[3] = 1.0f;
}