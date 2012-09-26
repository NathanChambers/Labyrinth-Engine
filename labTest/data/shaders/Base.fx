//--------------------------------------------------------------------------------//
//
// \author      Nathan M. Chambers
// \date        22/04/2012
// \brief		Basic Vertex and Pixel Shader
//
//--------------------------------------------------------------------------------//

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
	return float4(1,0,0,1);
}

//--------------------------------------------------------------------------------//

technique10 Standard
{
    pass Main
    {
        SetVertexShader ( CompileShader ( vs_4_0, VS_MAIN () ) );
        SetGeometryShader ( NULL );
        SetPixelShader  ( CompileShader ( ps_4_0, PS_MAIN  () ) );
    }
}