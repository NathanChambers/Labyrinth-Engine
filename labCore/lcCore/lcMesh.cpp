//--------------------------------------------------------------------------------//
//
// \author      Nathan M. Chambers
// \date        06/03/2012
// \brief		Render Class Containing Shaders with vertex and index buffers
//
//--------------------------------------------------------------------------------//
#include "lcMesh.h"
#include "lcRenderer.h"
#include "lcShaderProperty.h"
#include "lcTextureProperty.h"
//--------------------------------------------------------------------------------//

lcMesh::lcMesh() 
{
	m_pInputLayout = 0;
	m_pVertexShader = 0;
	m_pPixelShader	= 0;
	m_oTopology = D3D11_PRIMITIVE_TOPOLOGY_POINTLIST;
}

//--------------------------------------------------------------------------------//

lcMesh::lcMesh(const char* a_pName) 
	:lcNode(a_pName)
{
	m_pInputLayout = 0;
	m_pVertexShader = 0;
	m_pPixelShader	= 0;
	m_oTopology = D3D11_PRIMITIVE_TOPOLOGY_POINTLIST;
}

//--------------------------------------------------------------------------------//

lcMesh::lcMesh(const lcMesh& a_rCopy)
{
	m_pInputLayout = a_rCopy.m_pInputLayout;
	m_pVertexShader = a_rCopy.m_pVertexShader;
	m_pPixelShader	= a_rCopy.m_pPixelShader;
	m_oTopology = a_rCopy.m_oTopology;
}

//--------------------------------------------------------------------------------//

lcMesh::~lcMesh()
{
}

lcNode* lcMesh::Clone()
{
	lcMesh* pClone = new lcMesh();

	pClone->m_sName = m_sName;
	pClone->m_pIndexBuffer = m_pIndexBuffer;
	pClone->m_pVertexBuffer = m_pVertexBuffer;
	pClone->m_oTopology = m_oTopology;

	pClone->m_uiIndexCount = m_uiIndexCount;
	pClone->m_uiVertexCount = m_uiVertexCount;
	pClone->m_uiOffset = m_uiOffset;
	pClone->m_uiStride = m_uiStride;

	for(auto pPropIter = m_aProperties.begin();pPropIter != m_aProperties.end();++pPropIter)
	{
		pClone->AttachProperty(*pPropIter);
	}

	return dynamic_cast<lcNode*>(pClone);
}

//--------------------------------------------------------------------------------//

void lcMesh::SetPrimativeTopology(D3D11_PRIMITIVE_TOPOLOGY a_oTopology)
{
	m_oTopology = a_oTopology;
}

//--------------------------------------------------------------------------------//

void lcMesh::AttachProperty(Property* a_pProp)
{
	LC_PROPERTY_TYPES ePropType = a_pProp->GetType();

	switch(ePropType)
	{
	case LC_PROPERTY_SHADER:
		{
			ShaderProperty* pkProp = dynamic_cast<ShaderProperty*>(a_pProp);
			if(pkProp)
			{
				m_pInputLayout = pkProp->GetInputLayout();
				m_pVertexShader = pkProp->GetVertexShader();
				m_pPixelShader = pkProp->GetPixelShader();
				m_aProperties.push_front(a_pProp);
			}
			break;
		}

	case LC_PROPERTY_TEXTURE:
		{
			lcTextureProperty* pkProp = dynamic_cast<lcTextureProperty*>(a_pProp);
			if(pkProp)
			{
				m_aProperties.push_front(a_pProp);
			}
			break;
		}

	default:
		{
			Utilities::Debug_ConsoleWrite("ERROR : Property Has No Type");
			return;
		}
	}

	
}

//--------------------------------------------------------------------------------//

bool lcMesh::AttachVertexData(D3D11_BUFFER_DESC a_oVertexDesc,D3D11_SUBRESOURCE_DATA a_oVertexData,unsigned int a_uiVertexCount,unsigned int a_uiStride)
{
	//Create a Vertex Buffer with the Data of all the verts and a description of the buffer
	ID3D11Device* pDevice = lcRenderer::GetDevice();
	if(FAILED(pDevice->CreateBuffer(&a_oVertexDesc,&a_oVertexData,&m_pVertexBuffer)))
	{
		Utilities::Debug_ConsoleWrite("Could Not Create Vertex Buffer \n");
		return false;
	}

	//Set the Amount of Verts in the Buffer
	m_uiVertexCount = a_uiVertexCount;
	m_uiStride = a_uiStride;

	return true;
}

//--------------------------------------------------------------------------------//

bool lcMesh::AttachIndexData(D3D11_BUFFER_DESC a_oIndexDesc,D3D11_SUBRESOURCE_DATA a_oIndexData,unsigned int a_uiIndexCount,unsigned int a_uiOffset)
{
	//Create Index Buffer with a Description of the Indices and their data
	ID3D11Device* pDevice = lcRenderer::GetDevice();
	if(FAILED(pDevice->CreateBuffer(&a_oIndexDesc,&a_oIndexData,&m_pIndexBuffer)))
	{
		Utilities::Debug_ConsoleWrite("Could Not Create Index Buffer \n");
		return false;
	}
	
	//Set the Number of Indices the buffer contains
	m_uiIndexCount = a_uiIndexCount;
	m_uiOffset = a_uiOffset;

	return true;
}

//--------------------------------------------------------------------------------//

void lcMesh::UpdateProperties()
{
	for(auto pIter = m_aProperties.begin();pIter != m_aProperties.end();++pIter)
	{
		switch((*pIter)->GetType())
		{
		case LC_PROPERTY_SHADER:
			{
				ShaderProperty* pkProp = dynamic_cast<ShaderProperty*>((*pIter));
				if(pkProp)
				{
					m_pInputLayout = pkProp->GetInputLayout();
					m_pVertexShader = pkProp->GetVertexShader();
					m_pPixelShader = pkProp->GetPixelShader();
				}
			}

		case LC_PROPERTY_TEXTURE:
			{
				lcTextureProperty* pkProp = dynamic_cast<lcTextureProperty*>((*pIter));
				if(pkProp)
				{
					pkProp->SynchTextures();
				}
				break;
			}
		}
	}

	lcNode::UpdateProperties();
}