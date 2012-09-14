//--------------------------------------------------------------------------------//
//
// \author      Nathan M. Chambers
// \date        18/04/2012
// \brief		Shader Property, Loads Vertex and Pixel Shader from a single 
//				shader file. Also generated input layout for the shader
//
//--------------------------------------------------------------------------------//
#include "ShaderProperty.h"
#include <vector>
#include <D3Dcompiler.h>
#include "../lcGraphics//DX11Renderer.h"


#include <fstream>
#include <iostream>
#include <string>

#include <DxErr.h>
//--------------------------------------------------------------------------------//

ShaderProperty::ShaderProperty(const char* a_pFileName,bool a_bCompileFile)
	: m_bCompileFile(a_bCompileFile)
{
	m_eType = PROPERTY_SHADER;
	m_bCompileFile = a_bCompileFile;

	CompileVertexShader(a_pFileName);
	CompilePixelShader(a_pFileName);
}

//--------------------------------------------------------------------------------//

ShaderProperty::~ShaderProperty()
{
	if(m_pVertexShader)
		m_pVertexShader->Release();

	if(m_pPixelShader)
		m_pPixelShader->Release();
}

ShaderProperty* ShaderProperty::Create(const char* a_pFileName)
{
	ShaderProperty* pShader = new ShaderProperty(a_pFileName);
	return pShader;
}

//--------------------------------------------------------------------------------//

ID3D11VertexShader* ShaderProperty::GetVertexShader()
{
	return m_pVertexShader;
}

//--------------------------------------------------------------------------------//

ID3D11PixelShader* ShaderProperty::GetPixelShader()
{
	return m_pPixelShader;
}

//--------------------------------------------------------------------------------//

ID3D11InputLayout* ShaderProperty::GetInputLayout()
{
	return m_pInputLayout;
}

//--------------------------------------------------------------------------------//

void ShaderProperty::CompileVertexShader(const char* a_pFileName)
{
	ID3D10Blob* pErrorBlob = 0;
	ID3D10Blob* pVertexShaderByteCode = 0;

	if(m_bCompileFile)
	{
		//Shader Versions
		char* aVSVersions[] = 
		{
			"vs_5_0",
			"vs_4_0",
			"vs_3_0",
			"vs_2_0",

		};

		unsigned char iNumVersions = ARRAYSIZE(aVSVersions);
		for(unsigned char i = 0;i < iNumVersions;i++)
		{
			//Get a Pixel Shader from File and Compiles it
			if(FAILED(D3DX11CompileFromFile(a_pFileName, 0, 0,"VS_MAIN",aVSVersions[i],
				D3D10_SHADER_ENABLE_STRICTNESS, 0, 0, &pVertexShaderByteCode, &pErrorBlob, 0 )))
			{
				continue;
			}

			if(pVertexShaderByteCode)
				break;
		}

		if(pErrorBlob || !pVertexShaderByteCode)
		{
			if(pErrorBlob)
			{
				Utilities::Debug_OutputWrite((char*)pErrorBlob->GetBufferPointer());
			}
			else if(!pVertexShaderByteCode)
			{
				Utilities::Debug_OutputWrite("%s File Could Not Be Found \n",a_pFileName);
			}

			assert(!"Shader Loading Error, Check Output");
			pErrorBlob->Release();
		}


		//Creating the Vertex Shader to be put in the mesh for rendering
		ID3D11Device* pDevice = DX11Renderer::GetDevice();
		if(pVertexShaderByteCode)
		{
			if(FAILED(pDevice->CreateVertexShader(pVertexShaderByteCode->GetBufferPointer(),pVertexShaderByteCode->GetBufferSize(),NULL,&m_pVertexShader)))
			{
				Utilities::Debug_ConsoleWrite("VERTEX SHADER \" %s \" WAS UNSUCCESSFULL \n",a_pFileName);
			}

			InputLayoutFromShaderByteCode(pVertexShaderByteCode);
			pVertexShaderByteCode->Release(); 
		}
	}
	else
	{
		//Pre compiled Shader loading
	}
}

//--------------------------------------------------------------------------------//

void ShaderProperty::CompilePixelShader(const char* a_pFileName)
{
	ID3D10Blob* pErrorBlob = 0;
	ID3D10Blob* pPixelShaderByteCode = 0;

	if(m_bCompileFile)
	{
		char* aPSVersions[] = 
		{
			"ps_5_0",
			"ps_4_0",
			"ps_3_0",
			"ps_2_0",
		};

		unsigned int iNumVersions = ARRAYSIZE(aPSVersions);
		for(unsigned char i = 0;i < iNumVersions;i++)
		{
			//Get a Pixel Shader from File and Compiles it
			if(FAILED(D3DX11CompileFromFile(a_pFileName, 0, 0,"PS_MAIN",aPSVersions[i],
				D3D10_SHADER_ENABLE_STRICTNESS, 0, 0, &pPixelShaderByteCode, &pErrorBlob, 0 )))
			{
				continue;
			}

			if(pPixelShaderByteCode)
				break;
		}

		if(pErrorBlob || !pPixelShaderByteCode)
		{
			if(pErrorBlob)
			{
				Utilities::Debug_OutputWrite((char*)pErrorBlob->GetBufferPointer());
			}
			else if(!pPixelShaderByteCode)
			{
				Utilities::Debug_OutputWrite("%s File Could Not Be Found \n",a_pFileName);
			}

			assert(!"Shader Loading Error, Check Output");
			pErrorBlob->Release();
		}

		//Creating the Pixel Shader to be put in the mesh for rendering
		ID3D11Device* pDevice = DX11Renderer::GetDevice();
		if(pPixelShaderByteCode)
		{
			if(FAILED(pDevice->CreatePixelShader(pPixelShaderByteCode->GetBufferPointer(),pPixelShaderByteCode->GetBufferSize(),NULL,&m_pPixelShader)))
			{
				Utilities::Debug_ConsoleWrite("PIXEL SHADER \" %s \" WAS UNSUCCESSFULL \n",a_pFileName);
			}
		}
	}
	else
	{
		//Add Pre Compiled Loading
	}

}

//--------------------------------------------------------------------------------//

void ShaderProperty::InputLayoutFromShaderByteCode(ID3DBlob* a_pShaderByteCode)
{
	//Reflect Shader Info
	ID3D11ShaderReflection* pVertexShaderReflection = NULL;

	if(FAILED(D3DReflect(a_pShaderByteCode->GetBufferPointer(),a_pShaderByteCode->GetBufferSize(),
		IID_ID3D11ShaderReflection,(void**)&pVertexShaderReflection)))
	{
		return;
	}

	//Get Shader Info
	D3D11_SHADER_DESC shaderDesc;
	pVertexShaderReflection->GetDesc(&shaderDesc);

	//Read Input Layout Desc from Shader Info
	unsigned int byteOffset = 0;
	std::vector<D3D11_INPUT_ELEMENT_DESC> inputLayoutDesc;
	for(unsigned int i = 0; i < shaderDesc.InputParameters;i++)
	{
		D3D11_SIGNATURE_PARAMETER_DESC paramDesc;
		pVertexShaderReflection->GetInputParameterDesc(i,&paramDesc);

		//Fill out input element desc
		D3D11_INPUT_ELEMENT_DESC elementDesc;
		elementDesc.SemanticName = paramDesc.SemanticName;
		elementDesc.SemanticIndex = paramDesc.SemanticIndex;
		elementDesc.InputSlot = 0;
		elementDesc.AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
		elementDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		elementDesc.InstanceDataStepRate = 0;

		//Determine DXGI Format
		if(paramDesc.Mask == 1)
		{
			if(paramDesc.ComponentType == D3D_REGISTER_COMPONENT_UINT32) 
				elementDesc.Format = DXGI_FORMAT_R32_UINT;
			else if(paramDesc.ComponentType == D3D_REGISTER_COMPONENT_SINT32)
				elementDesc.Format = DXGI_FORMAT_R32_SINT;
			else if(paramDesc.ComponentType == D3D_REGISTER_COMPONENT_FLOAT32)
				elementDesc.Format = DXGI_FORMAT_R32_FLOAT;
		}
		else if(paramDesc.Mask <= 3)
		{
			if(paramDesc.ComponentType == D3D_REGISTER_COMPONENT_UINT32) 
				elementDesc.Format = DXGI_FORMAT_R32G32_UINT;
			else if(paramDesc.ComponentType == D3D_REGISTER_COMPONENT_SINT32)
				elementDesc.Format = DXGI_FORMAT_R32G32_SINT;
			else if(paramDesc.ComponentType == D3D_REGISTER_COMPONENT_FLOAT32)
				elementDesc.Format = DXGI_FORMAT_R32G32_FLOAT;
		}
		else if(paramDesc.Mask <= 7)
		{
			if(paramDesc.ComponentType == D3D_REGISTER_COMPONENT_UINT32) 
				elementDesc.Format = DXGI_FORMAT_R32G32B32_UINT;
			else if(paramDesc.ComponentType == D3D_REGISTER_COMPONENT_SINT32)
				elementDesc.Format = DXGI_FORMAT_R32G32B32_SINT;
			else if(paramDesc.ComponentType == D3D_REGISTER_COMPONENT_FLOAT32)
				elementDesc.Format = DXGI_FORMAT_R32G32B32_FLOAT;
		}
		else if(paramDesc.Mask <= 15)
		{
			if(paramDesc.ComponentType == D3D_REGISTER_COMPONENT_UINT32) 
				elementDesc.Format = DXGI_FORMAT_R32G32B32A32_UINT;
			else if(paramDesc.ComponentType == D3D_REGISTER_COMPONENT_SINT32)
				elementDesc.Format = DXGI_FORMAT_R32G32B32A32_SINT;
			else if(paramDesc.ComponentType == D3D_REGISTER_COMPONENT_FLOAT32)
				elementDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
		}

		//Save Element Desc
		inputLayoutDesc.push_back(elementDesc);
	}

	//Create Input Layout
	ID3D11Device* pDevice = DX11Renderer::GetDevice();
	if(FAILED(pDevice->CreateInputLayout(&inputLayoutDesc[0],inputLayoutDesc.size(),
		a_pShaderByteCode->GetBufferPointer(),a_pShaderByteCode->GetBufferSize(),&m_pInputLayout)))
	{
		return;
	}

	pVertexShaderReflection->Release();
}

//--------------------------------------------------------------------------------//

void ShaderProperty::AddCBuffer(const char* BufferName,const void* BufferData,size_t BufferSize,unsigned int a_uiRegister)
{
	int iPadding = BufferSize % sizeof(D3DXVECTOR4);

	if(iPadding)
	{
		BufferSize += sizeof(D3DXVECTOR4) - iPadding;
	}


	D3D11_BUFFER_DESC oMatrixBufferDesc;
	oMatrixBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	oMatrixBufferDesc.ByteWidth = BufferSize;
	oMatrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	oMatrixBufferDesc.CPUAccessFlags = 0;
	oMatrixBufferDesc.MiscFlags = 0;
	oMatrixBufferDesc.StructureByteStride = 0;

	ID3D11Buffer* pCBuffer = 0;
	ID3D11Device* pDevice = DX11Renderer::GetDevice();
	ID3D11DeviceContext* pDeviceContext  = DX11Renderer::GetDeviceContext();

	if(FAILED(pDevice->CreateBuffer(&oMatrixBufferDesc,NULL,&pCBuffer)))
	{
		return;
	}

	CBuffer oNewBuffer;
	oNewBuffer.pBuffer = pCBuffer;
	oNewBuffer.pBufferData = BufferData;
	oNewBuffer.uiRegister = a_uiRegister;

	pDeviceContext->UpdateSubresource(oNewBuffer.pBuffer,0,NULL,oNewBuffer.pBufferData,0,0);

	m_aCBuffers[BufferName] = oNewBuffer;
}

//--------------------------------------------------------------------------------//

void ShaderProperty::UpdateCBuffer(const char* a_pBufferName,eShaderType a_eShaderType)
{
	ID3D11DeviceContext* pDeviceContext = DX11Renderer::GetDeviceContext();
	pDeviceContext->UpdateSubresource(m_aCBuffers[a_pBufferName].pBuffer,0,NULL,m_aCBuffers[a_pBufferName].pBufferData,0,0);

	ID3D11Buffer* pBuffer = m_aCBuffers[a_pBufferName].pBuffer;
	switch(a_eShaderType)
	{
	case SHADER_VERTEX:
		pDeviceContext->VSSetConstantBuffers(m_aCBuffers[a_pBufferName].uiRegister,1,&pBuffer);
		break;
	case SHADER_PIXEL:
		pDeviceContext->PSSetConstantBuffers(m_aCBuffers[a_pBufferName].uiRegister,1,&pBuffer);
		break;
	case SHADER_GEOMETRY:
		pDeviceContext->GSSetConstantBuffers(m_aCBuffers[a_pBufferName].uiRegister,1,&pBuffer);
		break;
	}
}

//--------------------------------------------------------------------------------//