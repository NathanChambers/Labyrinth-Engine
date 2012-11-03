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
	float4 textureColor;
	textureColor = shaderTexture.Sample(SampleType,Input.UV);
	return textureColor;
}