// *****************************************************************************************************************
// *****************************************************************************************************************

cbuffer PerFrameConstants : register(b0)
{
	matrix projViewMatrix3D;
	matrix projMatrix2D;
	float2 screenZeroPoint;
	float2 screenScale;
	float4 ambientColor;
	float4 globalColor;
	matrix invProjViewMatrix3D;
	float3 viewPos;
	float padding;
};

// *****************************************************************************************************************
// *****************************************************************************************************************
