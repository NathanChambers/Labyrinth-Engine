cbuffer CBWorldMatrix : register(b0)
{
	float4x4 g_mWorld;
}

cbuffer CBViewMatrix : register(b1)
{
	float4x4 g_mViewProj;
}

SamplerState SampleType;
Texture2D shaderTexture;

//--------------------------------------------------------------------------------//

struct VS_INPUT
{
	float3 Position : POSITION0;
	float2 UV		: TEXCOORD0;
};

struct PS_INPUT
{
	float4 Position : SV_Position;
	float2 UV		: TEXCOORD0;
};

//--------------------------------------------------------------------------------//

PS_INPUT VS_MAIN (VS_INPUT Input)
{
	PS_INPUT Output;
	float4x4 mWVP = mul(g_mWorld,g_mViewProj);
	Output.Position = mul(float4(Input.Position.xyz,1),mWVP);
	Output.UV = Input.UV;
	return Output;
}

//--------------------------------------------------------------------------------//

float4 PS_MAIN(PS_INPUT Input) : SV_Target
{
	// Outputs edges only using a A 3x3 edge filter kernel
	float4 lum = float4(0.30, 0.59, 0.11, 1);

	// TOP ROW
	float s11 = dot(shaderTexture.Sample(SampleType, Input.UV + float2(-1.0f / 1024.0f, -1.0f / 768.0f)), lum);	// LEFT
	float s12 = dot(shaderTexture.Sample(SampleType, Input.UV + float2(0, -1.0f / 768.0f)), lum);				// MIDDLE
	float s13 = dot(shaderTexture.Sample(SampleType, Input.UV + float2(1.0f / 1024.0f, -1.0f / 768.0f)), lum);	// RIGHT

	// MIDDLE ROW
	float s21 = dot(shaderTexture.Sample(SampleType, Input.UV + float2(-1.0f / 1024.0f, 0)), lum);				// LEFT
	// Omit center
	float s23 = dot(shaderTexture.Sample(SampleType, Input.UV + float2(-1.0f / 1024.0f, 0)), lum); 				// RIGHT

	// LAST ROW
	float s31 = dot(shaderTexture.Sample(SampleType, Input.UV + float2(-1.0f / 1024.0f, 1.0f / 768.0f)), lum);	// LEFT
	float s32 = dot(shaderTexture.Sample(SampleType, Input.UV + float2(0, 1.0f / 768.0f)), lum);				// MIDDLE
	float s33 = dot(shaderTexture.Sample(SampleType, Input.UV + float2(1.0f / 1024.0f, 1.0f / 768.0f)), lum);	// RIGHT

	// Filter ... thanks internet :)
	float t1 = s13 + s33 + (2 * s23) - s11 - (2 * s21) - s31;
	float t2 = s31 + (2 * s32) + s33 - s11 - (2 * s12) - s13;

	float4 col;

	if (((t1 * t1) + (t2 * t2)) > 0.005) 
	{
		col = float4(0,0,0,1);
	} 
	else 
	{
		col = float4(1,1,1,1);
	}

	return col;
}

