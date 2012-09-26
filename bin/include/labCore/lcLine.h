#ifndef __LINE_H_
#define __LINE_H_

#include "lcMesh.h"

lcNode* CreateLine(D3DXVECTOR3 a_vStart,D3DXVECTOR3 a_vEnd)
{
	lcMesh* pMesh = new lcMesh("Line");

	struct Vertex
	{
		D3DXVECTOR3 vPosition;
		D3DXCOLOR vColor;
	};

	Vertex aVerticies [] = 
	{
		{a_vStart,D3DXCOLOR(1.0f,0.0f,0.0f,1.0f)},
		{a_vEnd,D3DXCOLOR(1.0f,0.0f,0.0f,1.0f)},
	};

	unsigned int aIndicies [] =
	{
		0,1,
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

	pMesh->SetPrimativeTopology(D3D_PRIMITIVE_TOPOLOGY_LINELIST);
	pMesh->AttachVertexData(oVertexBufferDesc,oVertexData,uiVertexCount,sizeof(Vertex));
	pMesh->AttachIndexData(oIndexBufferDesc,oIndexData,uiIndexCount,0);
	
	//////////////////////////////////////////////////////////////////////////
	//Cast it to a lcNode
	lcNode* pNode = dynamic_cast<lcNode*>(pMesh);
	return pNode;
}

#endif//__LINE_H_