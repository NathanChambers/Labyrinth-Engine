export void ispcVec3Add(uniform float a_pkArgOut[],uniform const float ac_pkArgL[],uniform const float ac_pkArgR[])
{
	a_pkArgOut[0] = ac_pkArgL[0] + ac_pkArgR[0];
	a_pkArgOut[1] = ac_pkArgL[1] + ac_pkArgR[1];
	a_pkArgOut[2] = ac_pkArgL[2] + ac_pkArgR[2];
}

export void ispcVec3Sub(uniform float a_pkArgOut[],uniform const float ac_pkArgL[],uniform const float ac_pkArgR[])
{
	a_pkArgOut[0] = ac_pkArgL[0] - ac_pkArgR[0];
	a_pkArgOut[1] = ac_pkArgL[1] - ac_pkArgR[1];
	a_pkArgOut[2] = ac_pkArgL[2] - ac_pkArgR[2];
}

export void ispcVec3Mul(uniform float a_pkArgOut[],uniform const float ac_pkArgL[],uniform const float ac_fArgR)
{
	a_pkArgOut[0] = ac_pkArgL[0] * ac_fArgR;
	a_pkArgOut[1] = ac_pkArgL[1] * ac_fArgR;
	a_pkArgOut[2] = ac_pkArgL[2] * ac_fArgR;
}

export void ispcVec3Div(uniform float a_pkArgOut[],uniform const float ac_pkArgL[],uniform const float ac_fArgR)
{
	a_pkArgOut[0] = ac_pkArgL[0] / ac_fArgR;
	a_pkArgOut[1] = ac_pkArgL[1] / ac_fArgR;
	a_pkArgOut[2] = ac_pkArgL[2] / ac_fArgR;
}

export void ispcVec3Negative(uniform float a_pkArgOut[],uniform const float ac_pkArgL[])
{
	a_pkArgOut[0] = -ac_pkArgL[0];
	a_pkArgOut[1] = -ac_pkArgL[1];
	a_pkArgOut[2] = -ac_pkArgL[2];
}

export uniform bool ispcVec3Equals(uniform const float ac_pkArgL[],uniform const float ac_pkArgR[])
{
	return ac_pkArgL[0] == ac_pkArgR[0] &&  ac_pkArgL[1] == ac_pkArgR[1] &&  ac_pkArgL[2] == ac_pkArgR[2]; 
}

export uniform bool ispcVec3NotEquals(uniform const float ac_pkArgL[],uniform const float ac_pkArgR[])
{
	return ac_pkArgL[0] != ac_pkArgR[0] &&  ac_pkArgL[1] != ac_pkArgR[1] &&  ac_pkArgL[2] != ac_pkArgR[2];
}

export uniform float ispcVec3DotProduct(uniform const float ac_pkArgL[],uniform const float ac_pkArgR[])
{
	return ac_pkArgL[0] * ac_pkArgR[0] + ac_pkArgL[1] * ac_pkArgR[1] + ac_pkArgL[2] * ac_pkArgR[2];
}

export uniform float ispcVec3Length(uniform const float ac_pkArgL[])
{
	return sqrt(ac_pkArgL[0] * ac_pkArgL[0] + ac_pkArgL[1] * ac_pkArgL[1] + ac_pkArgL[2] * ac_pkArgL[2]);
}

export uniform float ispcVec3LengthSqr(uniform const float ac_pkArgL[])
{
	return ac_pkArgL[0] * ac_pkArgL[0] + ac_pkArgL[1] * ac_pkArgL[1] + ac_pkArgL[2] * ac_pkArgL[2];
}

export void ispcVec3Normalise(uniform float a_pkArgOut[],uniform const float ac_pkArgL[])
{
	uniform float fLength = sqrt(ac_pkArgL[0] * ac_pkArgL[0] + ac_pkArgL[1] * ac_pkArgL[1] + ac_pkArgL[2] * ac_pkArgL[2]);

	a_pkArgOut[0] = ac_pkArgL[0] / fLength;
	a_pkArgOut[1] = ac_pkArgL[1] / fLength;
	a_pkArgOut[2] = ac_pkArgL[2] / fLength;
}

export void ispcVec3Maximise(uniform float a_pkArgOut[],uniform const float ac_pkArgL[])
{
	uniform float fHighest = ac_pkArgL[0];
	if(ac_pkArgL[1] > fHighest)
		fHighest = ac_pkArgL[1];
	
	if(ac_pkArgL[2] > fHighest)
		fHighest = ac_pkArgL[2];

	a_pkArgOut[0] = fHighest;
	a_pkArgOut[1] = fHighest;
	a_pkArgOut[2] = fHighest;
}

export void ispcVec3Minimise(uniform float a_pkArgOut[],uniform const float ac_pkArgL[])
{
	uniform float fLowest = ac_pkArgL[0];
	if(ac_pkArgL[1] < fLowest)
		fLowest = ac_pkArgL[1];
	
	if(ac_pkArgL[2] < fLowest)
		fLowest = ac_pkArgL[2];

	a_pkArgOut[0] = fLowest;
	a_pkArgOut[1] = fLowest;
	a_pkArgOut[2] = fLowest;
}

export void ispcVec3CrossProduct(uniform float a_pkArgOut[],uniform const float ac_pkArgL[],uniform const float ac_pkArgR[])
{
	a_pkArgOut[0] = ac_pkArgL[1] * ac_pkArgR[2] - ac_pkArgL[2] * ac_pkArgR[1];
	a_pkArgOut[1] = ac_pkArgL[2] * ac_pkArgR[0] - ac_pkArgL[0] * ac_pkArgR[2];
	a_pkArgOut[2] = ac_pkArgL[0] * ac_pkArgR[1] - ac_pkArgL[1] * ac_pkArgR[0];
}