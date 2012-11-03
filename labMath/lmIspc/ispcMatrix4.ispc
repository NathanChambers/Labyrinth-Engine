export void ispcMatrix4Mul(uniform float a_pkArgOut[],uniform const float ac_pkArgL[],uniform const float ac_pkArgR[])
{
	//uniform float afRetMat[16];

	//foreach(i = 0 ... 4)
	//{
	//	afRetMat[(i * 4) + 0] = ac_pkArgL[i * 4] * ac_pkArgR[0] + ac_pkArgL[(i * 4) + 1] * ac_pkArgR[0 + 4] + ac_pkArgL[(i * 4) + 2] * ac_pkArgR[(0 + 4) + 4] + ac_pkArgL[(i * 4) + 3] * ac_pkArgR[(0 + 4) + 8];
	//	afRetMat[(i * 4) + 1] = ac_pkArgL[i * 4] * ac_pkArgR[1] + ac_pkArgL[(i * 4) + 1] * ac_pkArgR[1 + 4] + ac_pkArgL[(i * 4) + 2] * ac_pkArgR[(1 + 4) + 4] + ac_pkArgL[(i * 4) + 3] * ac_pkArgR[(1 + 4) + 8];
	//	afRetMat[(i * 4) + 2] = ac_pkArgL[i * 4] * ac_pkArgR[2] + ac_pkArgL[(i * 4) + 1] * ac_pkArgR[2 + 4] + ac_pkArgL[(i * 4) + 2] * ac_pkArgR[(3 + 4) + 4] + ac_pkArgL[(i * 4) + 3] * ac_pkArgR[(2 + 4) + 8];
	//	afRetMat[(i * 4) + 3] = ac_pkArgL[i * 4] * ac_pkArgR[3] + ac_pkArgL[(i * 4) + 1] * ac_pkArgR[3 + 4] + ac_pkArgL[(i * 4) + 2] * ac_pkArgR[(4 + 4) + 4] + ac_pkArgL[(i * 4) + 3] * ac_pkArgR[(3 + 4) + 8];	
	//}

	//a_pkArgOut = afRetMat;

	uniform float afRetMat[16];
	afRetMat[0] = ac_pkArgL[0] * ac_pkArgR[0] + ac_pkArgL[1] * ac_pkArgR[4] + ac_pkArgL[2] * ac_pkArgR[8] + ac_pkArgL[3] * ac_pkArgR[12];
	afRetMat[1] = ac_pkArgL[0] * ac_pkArgR[1] + ac_pkArgL[1] * ac_pkArgR[5] + ac_pkArgL[2] * ac_pkArgR[9] + ac_pkArgL[3] * ac_pkArgR[13];
	afRetMat[2] = ac_pkArgL[0] * ac_pkArgR[2] + ac_pkArgL[1] * ac_pkArgR[6] + ac_pkArgL[2] * ac_pkArgR[10] + ac_pkArgL[3] * ac_pkArgR[14];
	afRetMat[3] = ac_pkArgL[0] * ac_pkArgR[3] + ac_pkArgL[1] * ac_pkArgR[7] + ac_pkArgL[2] * ac_pkArgR[11] + ac_pkArgL[3] * ac_pkArgR[15];

	afRetMat[4] = ac_pkArgL[4] * ac_pkArgR[0] + ac_pkArgL[5] * ac_pkArgR[4] + ac_pkArgL[6] * ac_pkArgR[8] + ac_pkArgL[7] * ac_pkArgR[12];
	afRetMat[5] = ac_pkArgL[4] * ac_pkArgR[1] + ac_pkArgL[5] * ac_pkArgR[5] + ac_pkArgL[6] * ac_pkArgR[9] + ac_pkArgL[7] * ac_pkArgR[13];
	afRetMat[6] = ac_pkArgL[4] * ac_pkArgR[2] + ac_pkArgL[5] * ac_pkArgR[6] + ac_pkArgL[6] * ac_pkArgR[10] + ac_pkArgL[7] * ac_pkArgR[14];
	afRetMat[7] = ac_pkArgL[4] * ac_pkArgR[3] + ac_pkArgL[5] * ac_pkArgR[7] + ac_pkArgL[6] * ac_pkArgR[11] + ac_pkArgL[7] * ac_pkArgR[15];

	afRetMat[8] = ac_pkArgL[8] * ac_pkArgR[0] + ac_pkArgL[9] * ac_pkArgR[4] + ac_pkArgL[10] * ac_pkArgR[8] + ac_pkArgL[11] * ac_pkArgR[12];
	afRetMat[9] = ac_pkArgL[8] * ac_pkArgR[1] + ac_pkArgL[9] * ac_pkArgR[5] + ac_pkArgL[10] * ac_pkArgR[9] + ac_pkArgL[11] * ac_pkArgR[13];
	afRetMat[10] = ac_pkArgL[8] * ac_pkArgR[2] + ac_pkArgL[9] * ac_pkArgR[6] + ac_pkArgL[10] * ac_pkArgR[10] + ac_pkArgL[11] * ac_pkArgR[14];
	afRetMat[11] = ac_pkArgL[8] * ac_pkArgR[3] + ac_pkArgL[9] * ac_pkArgR[7] + ac_pkArgL[10] * ac_pkArgR[11] + ac_pkArgL[11] * ac_pkArgR[15];

	afRetMat[12] = ac_pkArgL[12] * ac_pkArgR[0] + ac_pkArgL[13] * ac_pkArgR[4] + ac_pkArgL[14] * ac_pkArgR[8] + ac_pkArgL[15] * ac_pkArgR[12];
	afRetMat[13] = ac_pkArgL[12] * ac_pkArgR[1] + ac_pkArgL[13] * ac_pkArgR[5] + ac_pkArgL[14] * ac_pkArgR[9] + ac_pkArgL[15] * ac_pkArgR[13];
	afRetMat[14] = ac_pkArgL[12] * ac_pkArgR[2] + ac_pkArgL[13] * ac_pkArgR[6] + ac_pkArgL[14] * ac_pkArgR[10] + ac_pkArgL[15] * ac_pkArgR[14];
	afRetMat[15] = ac_pkArgL[12] * ac_pkArgR[3] + ac_pkArgL[13] * ac_pkArgR[7] + ac_pkArgL[14] * ac_pkArgR[11] + ac_pkArgL[15] * ac_pkArgR[15];

	foreach(i = 0 ... 16)
	{
		a_pkArgOut[i] = afRetMat[i];
	}
}