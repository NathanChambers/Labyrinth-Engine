//--------------------------------------------------------------------------------//
//
// \author      Nathan M. Chambers
// \date        18/04/2012
// \brief		Shader Property, Loads Vertex and Pixel Shader from a single 
//				shader file. Also generated input layout for the shader
//
//--------------------------------------------------------------------------------//
#ifndef __SHADERPROPERTY_H_
#define __SHADERPROPERTY_H_
//--------------------------------------------------------------------------------//
#include "Property.h"
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

private:
	struct CBuffer
	{
		ID3D11Buffer* pBuffer;
		unsigned int uiRegister;
		const void* pBufferData;
	};

	ShaderProperty(const char* a_pFileName,bool a_bCompileFile = true);
	
	void CompileVertexShader(const char* a_pFileName);
	void CompilePixelShader(const char* a_pFileName);
	void InputLayoutFromShaderByteCode(ID3DBlob* a_pShaderByteCode);

	std::map<const char*,CBuffer> m_aCBuffers;

	ID3D11VertexShader*		m_pVertexShader;
	ID3D11PixelShader*		m_pPixelShader;
	ID3D11InputLayout*		m_pInputLayout;

	bool					m_bCompileFile;
};

//--------------------------------------------------------------------------------//
//Inline Functions

//--------------------------------------------------------------------------------//
#endif//__SHADERPROPERTY_H_
//--------------------------------------------------------------------------------//