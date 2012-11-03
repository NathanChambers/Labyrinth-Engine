#ifndef __LCTEXTUREPROPERTY_H_
#define __LCTEXTUREPROPERTY_H_

#include "lcProperty.h"
#include "lcTexture2D.h"
#include <map>

class lcTextureProperty : public Property
{
	friend class lcMesh;
public:
	lcTextureProperty();
	~lcTextureProperty();

	void SetDiffuse(lcTexture2D* m_pkTexture);
	void SetNormal(lcTexture2D* m_pkTexture);
	void SetSpecular(lcTexture2D* m_pkTexture);
	void SetEmissive(lcTexture2D* m_pkTexture);
	void SetDisplacement(lcTexture2D* m_pkTexture);
	void SetDetail(lcTexture2D* m_pkTexture);

	void SynchTextures();

private:
	

protected:

	std::map<int,ID3D11ShaderResourceView*> m_akTextureResources;
	bool BindTexture(lcTexture2D* m_pkTexture, ID3D11ShaderResourceView* a_pkShaderResource, int a_iRegister);

	ID3D11ShaderResourceView* m_pkDiffTex;
	ID3D11ShaderResourceView* m_pkNormTex;
	ID3D11ShaderResourceView* m_pkSpecTex;
	ID3D11ShaderResourceView* m_pkEmissiveTex;
	ID3D11ShaderResourceView* m_pkDisplacementTex;
	ID3D11ShaderResourceView* m_pkDetailTex;

};

#endif//__PCTEXTUREPROPERTY_H_