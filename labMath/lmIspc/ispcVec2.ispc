export void ispcVec2Add(uniform float a_pkArgOut[],uniform const float ac_pkArgL[],uniform const float ac_pkArgR[])
{
	a_pkArgOut[0] = ac_pkArgL[0] + ac_pkArgR[0];
	a_pkArgOut[1] = ac_pkArgL[1] + ac_pkArgR[1];
}

export void ispcVec2Sub(uniform float a_pkArgOut[],uniform const float ac_pkArgL[],uniform const float ac_pkArgR[])
{
	a_pkArgOut[0] = ac_pkArgL[0] - ac_pkArgR[0];
	a_pkArgOut[1] = ac_pkArgL[1] - ac_pkArgR[1];
}

export void ispcVec2Mul(uniform float a_pkArgOut[],uniform const float ac_pkArgL[],uniform const float ac_fArgR)
{
	a_pkArgOut[0] = ac_pkArgL[0] * ac_fArgR;
	a_pkArgOut[1] = ac_pkArgL[1] * ac_fArgR;
}

export void ispcVec2Div(uniform float a_pkArgOut[],uniform const float ac_pkArgL[],uniform const float ac_fArgR)
{
	a_pkArgOut[0] = ac_pkArgL[0] / ac_fArgR;
	a_pkArgOut[1] = ac_pkArgL[1] / ac_fArgR;
}

export void ispcVec2Negative(uniform float a_pkArgOut[],uniform const float ac_pkArgL[])
{
	a_pkArgOut[0] = -ac_pkArgL[0];
	a_pkArgOut[1] = -ac_pkArgL[1];
}

export uniform bool ispcVec2Equals(uniform const float ac_pkArgL[],uniform const float ac_pkArgR[])
{
	return ac_pkArgL[0] == ac_pkArgR[0] &&  ac_pkArgL[1] == ac_pkArgR[1]; 
}

export uniform bool ispcVec2NotEquals(uniform const float ac_pkArgL[],uniform const float ac_pkArgR[])
{
	return ac_pkArgL[0] != ac_pkArgR[0] &&  ac_pkArgL[1] != ac_pkArgR[1];
}

export uniform float ispcVec2DotProduct(uniform const float ac_pkArgL[],uniform const float ac_pkArgR[])
{
	return ac_pkArgL[0] * ac_pkArgR[0] + ac_pkArgL[1] * ac_pkArgR[1];
}

export uniform float ispcVec2Length(uniform const float ac_pkArgL[])
{
	return sqrt(ac_pkArgL[0] * ac_pkArgL[0] + ac_pkArgL[1] * ac_pkArgL[1]);
}

export uniform float ispcVec2LengthSqr(uniform const float ac_pkArgL[])
{
	return ac_pkArgL[0] * ac_pkArgL[0] + ac_pkArgL[1] * ac_pkArgL[1];
}

export void ispcVec2Normalise(uniform float a_pkArgOut[],uniform const float ac_pkArgL[])
{
	uniform float fLength = sqrt(ac_pkArgL[0] * ac_pkArgL[0] + ac_pkArgL[1] * ac_pkArgL[1]);

	a_pkArgOut[0] = ac_pkArgL[0] / fLength;
	a_pkArgOut[1] = ac_pkArgL[1] / fLength;
}

export void ispcVec2Maximise(uniform float a_pkArgOut[],uniform const float ac_pkArgL[])
{
	uniform float fHighest = ac_pkArgL[0];
	if(ac_pkArgL[1] > fHighest)
		fHighest = ac_pkArgL[1];
	
	a_pkArgOut[0] = fHighest;
	a_pkArgOut[1] = fHighest;
}

export void ispcVec2Minimise(uniform float a_pkArgOut[],uniform const float ac_pkArgL[])
{
	uniform float fLowest = ac_pkArgL[0];
	if(ac_pkArgL[1] < fLowest)
		fLowest = ac_pkArgL[1];
	
	a_pkArgOut[0] = fLowest;
	a_pkArgOut[1] = fLowest;
}