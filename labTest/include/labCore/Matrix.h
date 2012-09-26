#ifndef __MATRIX_H_
#define __MATRIX_H_

#include "Mesh.h"

Node* DrawMatrix(D3DXMATRIX oMat)
{
	Mesh* pMesh = new Mesh("MATRIX");

	struct Vertex
	{
		D3DXVECTOR3 oPos;
		D3DXCOLOR	oColor;
	};

	Vertex aVerticies[] = 
	{
		{D3DXVECTOR3(oMat._41,oMat._42,oMat._43),D3DXCOLOR(1,0,0,1)},
		{D3DXVECTOR3(oMat._41,oMat._42,oMat._43),D3DXCOLOR(0,1,0,1)},
		{D3DXVECTOR3(oMat._41,oMat._42,oMat._43),D3DXCOLOR(0,0,1,1)},

		{D3DXVECTOR3(oMat._11,oMat._12,oMat._13),D3DXCOLOR(1,0,0,1)},
		{D3DXVECTOR3(oMat._21,oMat._22,oMat._23),D3DXCOLOR(0,1,0,1)},
		{D3DXVECTOR3(oMat._31,oMat._32,oMat._33),D3DXCOLOR(0,0,1,1)},
	};

	unsigned int aIndicies [] =
	{
		0,3,
		1,4,
		2,5,
	};

	

	unsigned int uiVertexCount = ARRAYSIZE(aVerticies);
	unsigned int uiIndexCount = ARRAYSIZE(aIndicies);

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

	pMesh->SetPrimativeTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
	pMesh->AttachVertexData(oVertexBufferDesc,oVertexData,uiVertexCount,sizeof(Vertex));
	pMesh->AttachIndexData(oIndexBufferDesc,oIndexData,uiIndexCount,0);

	return dynamic_cast<Node*>(pMesh);
}


#endif//__MATRIX_H_