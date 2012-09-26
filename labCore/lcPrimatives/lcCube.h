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
//--------------------------------------------------------------------------------//
lcNode* CreateCube()
{
	lcMesh* pMesh = new lcMesh("Cube");

	struct Vertex
	{
		D3DXVECTOR3 vPosition;
		D3DXVECTOR4 vColor;
	};

	Vertex aVerticies[] = 
	{
		//0 Front Top Left
		{D3DXVECTOR3(-0.5f,0.5f,-0.5f),	D3DXVECTOR4(1.0f,0.0f,0.0f,1.0f)},

		//1 Front Top Right
		{D3DXVECTOR3(0.5f,0.5f,-0.5f),	D3DXVECTOR4(0.0f,1.0f,0.0f,1.0f)},	

		//2 Front Bottom Right
		{D3DXVECTOR3(0.5f,-0.5f,-0.5f),	D3DXVECTOR4(0.0f,0.0f,1.0f,1.0f)},

		//3 Front Bottom Left
		{D3DXVECTOR3(-0.5f,-0.5f,-0.5f),D3DXVECTOR4(0.0f,0.0f,0.0f,1.0f)},

		//4 Back Top Left
		{D3DXVECTOR3(-0.5f,0.5f,0.5f),	D3DXVECTOR4(1.0f,0.0f,0.0f,1.0f)},

		//5 Back Top Right
		{D3DXVECTOR3(0.5f,0.5f,0.5f),	D3DXVECTOR4(0.0f,1.0f,0.0f,1.0f)},	

		//6 Back Bottom Right
		{D3DXVECTOR3(0.5f,-0.5f,0.5f),	D3DXVECTOR4(0.0f,0.0f,1.0f,1.0f)},

		//7 Back Bottom Left
		{D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR4(1.0f,1.0f,1.0f,1.0f)},
	};

	unsigned int aIndicies[] =
	{
		//Front
		0,1,3,
		3,1,2,

		//Right
		1,5,2,
		2,5,6,

		//Back
		5,4,6,
		6,4,7,

		//Left
		4,0,7,
		7,0,3,

		//Bottom
		3,2,7,
		7,2,6,

		//Top
		4,5,0,
		0,5,1
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
	lcNode* pNode = dynamic_cast<lcNode*>(pMesh);
	return pNode;
}

#endif//__CUBE_H_
//////////////////////////////////////////////////////////////////////////