//--------------------------------------------------------------------------------//
//
// \author      Nathan M. Chambers
// \date        06/03/2012
// \brief		Render Class Containing Shaders with vertex and index buffers
//--------------------------------------------------------------------------------//
#ifndef __MESH_H_
#define __MESH_H_
//--------------------------------------------------------------------------------//
#include "Node.h"
#include "DX11Renderer.h"
#include "ShaderProperty.h"
#include <map>
//--------------------------------------------------------------------------------//

class Mesh : public Node
{
	friend class DX11Renderer;

public:
	Mesh();
	Mesh(const char* a_pName);
	Mesh(const Mesh&);

	virtual ~Mesh();
	virtual Node* Clone();
	

	void AttachProperty(Property* a_pProp);

	bool AttachVertexData(D3D11_BUFFER_DESC a_oVertexDesc,D3D11_SUBRESOURCE_DATA a_oVertexData,
		unsigned int a_uiVertexCount,unsigned int a_uiStride);

	bool AttachIndexData(D3D11_BUFFER_DESC a_oIndexDesc,D3D11_SUBRESOURCE_DATA a_oIndexData,
		unsigned int a_uiIndexCount,unsigned int a_uiOffset);

	void SetPrimativeTopology(D3D11_PRIMITIVE_TOPOLOGY a_oTopology);

private:
	std::list<Property*>		m_aProperties;

	D3D11_PRIMITIVE_TOPOLOGY	m_oTopology;

	ID3D11InputLayout*			m_pInputLayout;
	ID3D11VertexShader*			m_pVertexShader;
	ID3D11PixelShader*			m_pPixelShader;

	ID3D11Buffer*				m_pVertexBuffer;
	ID3D11Buffer*				m_pIndexBuffer;

	unsigned int						m_uiVertexCount;
	unsigned int						m_uiIndexCount;

	unsigned int						m_uiStride;
	unsigned int						m_uiOffset;
};

//--------------------------------------------------------------------------------//
#endif//__MESH_H_
//--------------------------------------------------------------------------------//