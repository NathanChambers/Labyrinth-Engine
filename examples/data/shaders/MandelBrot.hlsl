cbuffer CBWorldMatrix : register(b0)
{
	float4x4 g_mWorld;
}

cbuffer CBViewMatrix : register(b1)
{
	float4x4 g_mViewProj;
}

cbuffer CBPosition : register(b2)
{
	float2 g_vScreenSize;
	float2 g_vPosition;
	float g_fZoom;
}

static const int Iterations = 512;
static const float Aspect = 1;
static const float3 ColorScale = float3(1,1,1);

float ComputeValue(float2 v, float2 offset);

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
	Output.Position = float4(Input.Position,1);
	Output.UV = Input.UV;
	return Output;
}

//--------------------------------------------------------------------------------//

float4 PS_MAIN(PS_INPUT Input) : SV_Target
{
	float2 v = (Input.UV - 0.5) * g_fZoom * float2(1, Aspect) - g_vPosition;

	float val = ComputeValue(v, v);

	return float4(sin(val * ColorScale.x), sin(val * ColorScale.y), sin(val * ColorScale.z), 1);
}

//--------------------------------------------------------------------------------//

float ComputeValue(float2 v, float2 offset)
{
	float vxsquare = 0;
	float vysquare = 0;

	int iteration = 0;
	int lastIteration = Iterations;

	do
	{
		vxsquare = v.x * v.x;
		vysquare = v.y * v.y;

		v = float2(vxsquare - vysquare, v.x * v.y * 2) + offset;

		iteration++;

		if ((lastIteration == Iterations) && (vxsquare + vysquare) > 4.0)
		{
			lastIteration = iteration + 1;
		}

	}while (iteration < lastIteration);

	return (float(iteration) - (log(log(sqrt(vxsquare + vysquare))) / log(2.0))) / float(Iterations);
}