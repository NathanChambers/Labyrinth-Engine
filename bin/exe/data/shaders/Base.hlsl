cbuffer CBWorldMatrix : register(b0)
{
	float4x4 g_mWorld;
}

cbuffer CBViewMatrix : register(b1)
{
	float4x4 g_mViewProj;
}

//--------------------------------------------------------------------------------//

struct VS_INPUT
{
	float3 Position : POSITION0;
	float4 Color	: COLOR0;
};

struct PS_INPUT
{
	float4 Position : SV_Position;
	float4 Color	: COLOR0;
};

//--------------------------------------------------------------------------------//

PS_INPUT VS_MAIN (VS_INPUT Input)
{
	PS_INPUT Output;
	float4x4 mWVP = mul(g_mWorld,g_mViewProj);
	Output.Position = mul(float4(Input.Position.xyz,1),mWVP);
	Output.Color = Input.Color;
	return Output;
}

//--------------------------------------------------------------------------------//

float4 PS_MAIN(PS_INPUT Input) : SV_Target
{
	return Input.Color;
}