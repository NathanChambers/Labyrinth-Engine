//--------------------------------------------------------------------------------//
//
// \author      Nathan M. Chambers
// \date        18/04/2012
// \brief		Shader Property, Loads Vertex and Pixel Shader from a single 
//				shader file. Also generated input layout for the shader
//
//--------------------------------------------------------------------------------//
#ifndef __LCSHADERPROPERTY_H_
#define __LCSHADERPROPERTY_H_
//--------------------------------------------------------------------------------//
#include "lcProperty.h"
#include <D3DX11.h>
#include <map>
//--------------------------------------------------------------------------------//
enum eShaderType
{
	SHADER_VERTEX,
	SHADER_PIXEL,
	SHADER_GEOMETRY,
	SHADER_COUNT
};

class ShaderProperty : public Property
{
public:
	static ShaderProperty* Create(const char* a_pFileName);
	~ShaderProperty();
	
	void AddCBuffer(const char* BufferName,const void* BufferData,size_t BufferSize,unsigned int Register);
	void UpdateCBuffer(const char* BufferName,eShaderType ShaderType);

	ID3D11VertexShader* GetVertexShader();
	ID3D11PixelShader* GetPixelShader();
	ID3D11InputLayout* GetInputLayout();

	bool LoadFromFile(const char* a_szFileName);

private:
	struct CBuffer
	{
		ID3D11Buffer* pBuffer;
		unsigned int uiRegister;
		const void* pBufferData;
	};

	ShaderProperty(const char* a_pFileName,bool a_bCompileFile = true);
	
	bool CompileVertexShader(ID3D11VertexShader** a_pkVertexShader,ID3D11InputLayout** a_pkInputLayout,const char* a_pFileName);
	bool CompilePixelShader(ID3D11PixelShader** a_pkPixelShader,const char* a_pFileName);
	bool InputLayoutFromShaderByteCode(ID3D11InputLayout** a_pkInputLayout,ID3DBlob* a_pShaderByteCode);

	std::map<const char*,CBuffer> m_aCBuffers;

	ID3D11VertexShader*		m_pVertexShader;
	ID3D11PixelShader*		m_pPixelShader;
	ID3D11InputLayout*		m_pInputLayout;

	bool					m_bCompileFile;
};
//--------------------------------------------------------------------------------//
#endif//__SHADERPROPERTY_H_
//--------------------------------------------------------------------------------//