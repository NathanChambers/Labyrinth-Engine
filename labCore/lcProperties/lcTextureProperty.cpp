#include "lcTextureProperty.h"
#include "lcProperty.h"
#include "lcRenderer.h"

lcTextureProperty::lcTextureProperty()
{
	m_eType = LC_PROPERTY_TEXTURE;
}

lcTextureProperty::~lcTextureProperty()
{

}

void lcTextureProperty::SetDiffuse(lcTexture2D* m_pkTexture)
{
	BindTexture(m_pkTexture,m_pkDiffTex,0);
}

void lcTextureProperty::SetNormal(lcTexture2D* m_pkTexture)
{
	BindTexture(m_pkTexture,m_pkNormTex,1);
}

void lcTextureProperty::SetSpecular(lcTexture2D* m_pkTexture)
{
	BindTexture(m_pkTexture,m_pkSpecTex,2);
}
void lcTextureProperty::SetEmissive(lcTexture2D* m_pkTexture)
{
	BindTexture(m_pkTexture,m_pkEmissiveTex,3);
}

void lcTextureProperty::SetDisplacement(lcTexture2D* m_pkTexture)
{
	BindTexture(m_pkTexture,m_pkDisplacementTex,4);
}

void lcTextureProperty::SetDetail(lcTexture2D* m_pkTexture)
{
	BindTexture(m_pkTexture,m_pkDetailTex,5);
}

bool lcTextureProperty::BindTexture(lcTexture2D* m_pkTexture,ID3D11ShaderResourceView* a_pkShaderResource, int a_iRegister)
{
	ID3D11ShaderResourceView* pkPropResource;
	lcRenderer::GetDevice()->CreateShaderResourceView(m_pkTexture->m_pkDXTexture2D,nullptr,&pkPropResource);

	if(pkPropResource != nullptr)
	{
		a_pkShaderResource = pkPropResource;
		m_akTextureResources[a_iRegister] = a_pkShaderResource;
	}
	else
	{
		return false;
	}

	return true;
}

void lcTextureProperty::SynchTextures()
{
	for(auto pIter = m_akTextureResources.begin();pIter != m_akTextureResources.end();++pIter)
	{
		lcRenderer::GetDeviceContext()->PSSetShaderResources((*pIter).first,1,&(*pIter).second);
	}
}