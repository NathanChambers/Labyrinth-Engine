//--------------------------------------------------------------------------------//
//
// \author      Nathan M. Chambers
// \date        23/04/2012
// \brief		Basic Cube Desc
//
//--------------------------------------------------------------------------------//
#ifndef __CUBE_H_
#define __CUBE_H_
//--------------------------------------------------------------------------------//
#include "lcMesh.h"
#include "lmVec3.h"

//--------------------------------------------------------------------------------//
lcNode* CreateCube(lmVec3 a_kPosition,lmVec3 a_kSize)
{
	lcMesh* pMesh = new lcMesh("Cube");

	struct Vertex
	{
		D3DXVECTOR3 vPosition;
		D3DXVECTOR2 vUV;
	};

	Vertex aVerticies[] = 
	{
		//Front
		{D3DXVECTOR3(-a_kSize.x,-a_kSize.y,-a_kSize.z),	D3DXVECTOR2(0,1)},
		{D3DXVECTOR3(-a_kSize.x,a_kSize.y,-a_kSize.z),	D3DXVECTOR2(0,0)},
		{D3DXVECTOR3(a_kSize.x,a_kSize.y,-a_kSize.z),	D3DXVECTOR2(1,0)},	
		{D3DXVECTOR3(a_kSize.x,-a_kSize.y,-a_kSize.z),	D3DXVECTOR2(1,1)},

		//Back
		{D3DXVECTOR3(-a_kSize.x,-a_kSize.y,a_kSize.z),	D3DXVECTOR2(1,1)},
		{D3DXVECTOR3(a_kSize.x,-a_kSize.y,a_kSize.z),	D3DXVECTOR2(0,1)},
		{D3DXVECTOR3(a_kSize.x,a_kSize.y,a_kSize.z),	D3DXVECTOR2(0,0)},	
		{D3DXVECTOR3(-a_kSize.x,a_kSize.y,a_kSize.z),	D3DXVECTOR2(1,0)},

		//Top
		{D3DXVECTOR3(-a_kSize.x,a_kSize.y,-a_kSize.z),	D3DXVECTOR2(0,1)},
		{D3DXVECTOR3(-a_kSize.x,a_kSize.y,a_kSize.z),	D3DXVECTOR2(0,0)},
		{D3DXVECTOR3(a_kSize.x,a_kSize.y,a_kSize.z),	D3DXVECTOR2(1,0)},	
		{D3DXVECTOR3(a_kSize.x,a_kSize.y,-a_kSize.z),	D3DXVECTOR2(1,1)},
		
		//Bottom
		{D3DXVECTOR3(-a_kSize.x,-a_kSize.y,-a_kSize.z),	D3DXVECTOR2(1,1)},
		{D3DXVECTOR3(a_kSize.x,-a_kSize.y,-a_kSize.z),	D3DXVECTOR2(0,1)},
		{D3DXVECTOR3(a_kSize.x,-a_kSize.y,a_kSize.z),	D3DXVECTOR2(0,0)},	
		{D3DXVECTOR3(-a_kSize.x,-a_kSize.y,a_kSize.z),	D3DXVECTOR2(1,0)},

		//Left
		{D3DXVECTOR3(-a_kSize.x,-a_kSize.y,a_kSize.z),	D3DXVECTOR2(0,1)},
		{D3DXVECTOR3(-a_kSize.x,a_kSize.y,a_kSize.z),	D3DXVECTOR2(0,0)},
		{D3DXVECTOR3(-a_kSize.x,a_kSize.y,-a_kSize.z),	D3DXVECTOR2(1,0)},	
		{D3DXVECTOR3(-a_kSize.x,-a_kSize.y,-a_kSize.z),	D3DXVECTOR2(1,1)},

		//Right
		{D3DXVECTOR3(a_kSize.x,-a_kSize.y,-a_kSize.z),	D3DXVECTOR2(0,1)},
		{D3DXVECTOR3(a_kSize.x,a_kSize.y,-a_kSize.z),	D3DXVECTOR2(0,0)},
		{D3DXVECTOR3(a_kSize.x,a_kSize.y,a_kSize.z),	D3DXVECTOR2(1,0)},	
		{D3DXVECTOR3(a_kSize.x,-a_kSize.y,a_kSize.z),	D3DXVECTOR2(1,1)},
		
	};

	unsigned int aIndicies[] =
	{
		0,1,2,
		0,2,3,
		4,5,6,
		4,6,7,
		8,9,10,
		8,10,11,
		12,13,14,
		12,14,15,
		16,17,18,
		16,18,19,
		20,21,22,
		20,22,23,
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

	pMesh->SetPrimativeTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	pMesh->AttachVertexData(oVertexBufferDesc,oVertexData,uiVertexCount,sizeof(Vertex));
	pMesh->AttachIndexData(oIndexBufferDesc,oIndexData,uiIndexCount,0);

	//////////////////////////////////////////////////////////////////////////
	//Cast it to a lcNode
	pMesh->SetTranslate(a_kPosition.v);

	lcNode* pNode = dynamic_cast<lcNode*>(pMesh);
	return pNode;
}

#endif//__CUBE_H_
//////////////////////////////////////////////////////////////////////////