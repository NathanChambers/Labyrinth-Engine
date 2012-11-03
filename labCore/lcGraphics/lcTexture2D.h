#ifndef __LCTEXTURE2D_H_
#define __LCTEXTURE2D_H_

#include <D3D11.h>

class lcTexture2D
{
	friend class lcTextureProperty;
public:
	lcTexture2D(const char* a_szTextureDir);
	lcTexture2D(const lcTexture2D& a_rkCopy);
	~lcTexture2D();

	void ReloadTexture(const char* a_szFileDir);
private:
	unsigned char* m_pkRawData;
	ID3D11Texture2D* m_pkDXTexture2D;
};

#endif//__LCTEXTURE2D_H_