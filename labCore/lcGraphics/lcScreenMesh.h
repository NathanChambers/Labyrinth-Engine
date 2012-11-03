#ifndef __LCSCREENMESH_H_
#define __LCSCREENMESH_H_
//--------------------------------------------------------------------------------//
#include "lcMesh.h"
//--------------------------------------------------------------------------------//

class lcScreenMesh : public lcMesh
{
public:
	lcScreenMesh(const char* a_szName)
		:lcMesh(a_szName)
	{
		struct Vertex
		{
			D3DXVECTOR3 vPosition;
			D3DXVECTOR2 vTexCoord;
		};

		Vertex aVerticies[] = 
		{
			{D3DXVECTOR3(-1.0f,-1.0f,0.0f), D3DXVECTOR2(0,0)},
			{D3DXVECTOR3(-1.0f,1.0f,0.0f), D3DXVECTOR2(0,1)},	
			{D3DXVECTOR3(1.0f,1.0f,0.0f), D3DXVECTOR2(1,1)},
			{D3DXVECTOR3(1.0f,-1.0f,0.0f), D3DXVECTOR2(1,0)},
		};

		unsigned int aIndicies[] =
		{
			1,2,0,
			0,2,3,
		};

		unsigned int uiVertexCount = ARRAYSIZE(aVerticies);
		unsigned int uiIndexCount = ARRAYSIZE(aIndicies);

		//////////////////////////////////////////////////////////////////////////

		D3D11_BUFFER_DESC oVertexBufferDesc;
		oVertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		oVertexBufferDesc.ByteWidth = sizeof(Vertex) * uiVertexCount;
		oVertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		oVertexBufferDesc.CPUAccessFlags = 0;
		oVertexBufferDesc.MiscFlags = 0;
		oVertexBufferDesc.StructureByteStride = 0;

		D3D11_BUFFER_DESC oIndexBufferDesc;
		oIndexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		oIndexBufferDesc.ByteWidth = sizeof(unsigned int) * uiIndexCount;
		oIndexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		oIndexBufferDesc.CPUAccessFlags = 0;
		oIndexBufferDesc.MiscFlags = 0;
		oIndexBufferDesc.StructureByteStride = 0;

		//////////////////////////////////////////////////////////////////////////
		D3D11_SUBRESOURCE_DATA oVertexData;
		oVertexData.pSysMem = aVerticies;
		oVertexData.SysMemSlicePitch = 0;
		oVertexData.SysMemPitch = 0;

		D3D11_SUBRESOURCE_DATA oIndexData;
		oIndexData.pSysMem = aIndicies;
		oIndexData.SysMemSlicePitch = 0;
		oIndexData.SysMemPitch = 0;

		//////////////////////////////////////////////////////////////////////////

		SetPrimativeTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		AttachVertexData(oVertexBufferDesc,oVertexData,uiVertexCount,sizeof(Vertex));
		AttachIndexData(oIndexBufferDesc,oIndexData,uiIndexCount,0);
	}

	void RenderImmediate(const lcRenderer* ac_pkRenderer)
	{
		UNREFERENCED_PARAMETER(ac_pkRenderer);
	}
};

#endif//__QUAD_H_
//////////////////////////////////////////////////////////////////////////