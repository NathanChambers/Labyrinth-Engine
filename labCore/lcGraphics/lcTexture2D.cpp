#include "lcTexture2D.h"
#include "lcAssert.h"
#include "lcRenderer.h"
#include "FreeImage.h"

lcTexture2D::lcTexture2D(const char* a_szFileDir)
{
	FREE_IMAGE_FORMAT kImageFormat = FreeImage_GetFileType(a_szFileDir, 0);
	FIBITMAP* pkData = FreeImage_Load(kImageFormat,a_szFileDir,0);

	if(pkData == nullptr)
		return;

	FIBITMAP* pk32BitData = FreeImage_ConvertTo32Bits(pkData);
	FreeImage_Unload(pkData);

	if(pk32BitData == nullptr)
		return;

	unsigned int uiPitch = FreeImage_GetPitch(pk32BitData);
	unsigned int uiWidth = FreeImage_GetWidth(pk32BitData);
	unsigned int uiHeight = FreeImage_GetHeight(pk32BitData);

	m_pkRawData = (unsigned char*)malloc(uiWidth * uiHeight << 2);
	FreeImage_ConvertToRawBits(m_pkRawData,pk32BitData,uiPitch,32,FI_RGBA_RED_MASK,FI_RGBA_GREEN_MASK,FI_RGBA_BLUE_MASK,true);

	D3D11_TEXTURE2D_DESC kTextureDesc;
	kTextureDesc.Width = uiWidth;
	kTextureDesc.Height = uiHeight;
	kTextureDesc.MipLevels = 1;
	kTextureDesc.ArraySize = 1;
	kTextureDesc.SampleDesc.Count = 1;
	kTextureDesc.SampleDesc.Quality = 0;
	kTextureDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	kTextureDesc.Usage = D3D11_USAGE_DYNAMIC;
	kTextureDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	kTextureDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	kTextureDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA kResourceData;
	kResourceData.pSysMem = m_pkRawData;
	kResourceData.SysMemPitch = uiPitch;
	kResourceData.SysMemSlicePitch = 0;

	if(FAILED(lcRenderer::GetDevice()->CreateTexture2D(&kTextureDesc,&kResourceData,&m_pkDXTexture2D)))
	{
		lcAssert("Could not Create Texture");
	}
}

lcTexture2D::lcTexture2D(const lcTexture2D& a_rkCopy)
{
	
}

void lcTexture2D::ReloadTexture(const char* a_szFileDir)
{
	FREE_IMAGE_FORMAT kImageFormat = FreeImage_GetFileType(a_szFileDir, 0);
	FIBITMAP* pkData = FreeImage_Load(kImageFormat,a_szFileDir,0);

	if(pkData == nullptr)
		return;

	FIBITMAP* pk32BitData = FreeImage_ConvertTo32Bits(pkData);
	FreeImage_Unload(pkData);

	if(pk32BitData == nullptr)
		return;

	unsigned int uiPitch = FreeImage_GetPitch(pk32BitData);
	unsigned int uiWidth = FreeImage_GetWidth(pk32BitData);
	unsigned int uiHeight = FreeImage_GetHeight(pk32BitData);

	m_pkRawData = (unsigned char*)malloc(uiWidth * uiHeight << 2);
	FreeImage_ConvertToRawBits(m_pkRawData,pk32BitData,uiPitch,32,FI_RGBA_RED_MASK,FI_RGBA_GREEN_MASK,FI_RGBA_BLUE_MASK,true);

	D3D11_TEXTURE2D_DESC kTextureDesc;
	kTextureDesc.Width = uiWidth;
	kTextureDesc.Height = uiHeight;
	kTextureDesc.MipLevels = 1;
	kTextureDesc.ArraySize = 1;
	kTextureDesc.SampleDesc.Count = 1;
	kTextureDesc.SampleDesc.Quality = 0;
	kTextureDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	kTextureDesc.Usage = D3D11_USAGE_DYNAMIC;
	kTextureDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	kTextureDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	kTextureDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA kResourceData;
	kResourceData.pSysMem = m_pkRawData;
	kResourceData.SysMemPitch = uiPitch;
	kResourceData.SysMemSlicePitch = 0;

	if(FAILED(lcRenderer::GetDevice()->CreateTexture2D(&kTextureDesc,&kResourceData,&m_pkDXTexture2D)))
	{
		lcAssert("Could not Create Texture");
	}
}

lcTexture2D::~lcTexture2D()
{
	
}