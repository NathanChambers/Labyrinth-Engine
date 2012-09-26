//--------------------------------------------------------------------------------//
//
// \author      Nathan M. Chambers
// \date        01/03/2012
// \brief		Bare bones DirectX 11 Renderer.
//
//--------------------------------------------------------------------------------//
#ifndef __LCRENDERER_H_
#define __LCRENDERER_H_
//--------------------------------------------------------------------------------//
#include <D3D11.h>

#include "lcCamera.h"
#include "lcWindow.h"
#include "lcMesh.h"
//--------------------------------------------------------------------------------//

struct CBWorld
{
	D3DXMATRIX		m_mWorldMatrix;
};

//--------------------------------------------------------------------------------//

struct CBViewProj
{
	D3DXMATRIX		m_mViewProj;
};

//--------------------------------------------------------------------------------//

class lcRenderer
{
public:
	static lcRenderer* Create(Window* a_pWindow);
	static lcRenderer* Get();
	void Release();

	static ID3D11Device* GetDevice();
	static ID3D11DeviceContext* GetDeviceContext();

	void BeginFrame(D3DXCOLOR ClearColor);
	void EndFrame();
	void DrawScene(lcCamera* Camera,lcNode* SceneNode);

private:
	lcRenderer();
	~lcRenderer();

	bool Initialise(Window* a_pWindow);
	void RenderNode(lcNode*);
	void TraverseChildren(lcNode*);

	static lcRenderer*			m_pSingleton;
	
	IDXGISwapChain*				m_pSwapChain;
	ID3D11Device*				m_pDevice;
	ID3D11DeviceContext*		m_pDeviceContext;
	ID3D11RenderTargetView*		m_pRenderTargetView;

	ID3D11Texture2D*			m_pDepthStencilBuffer;
	ID3D11DepthStencilState*	m_pDepthStencilState;
	ID3D11DepthStencilView*		m_pDepthStencilView;
	ID3D11RasterizerState*		m_pRasterState;

	D3D_DRIVER_TYPE				m_eDriverType;
	D3D_FEATURE_LEVEL			m_eFeatureLevel;

	ID3D11Buffer*				m_pCBWorld;
	ID3D11Buffer*				m_pCBViewProj;
};

//--------------------------------------------------------------------------------//
#endif//__DX11RENDERER_H_
//--------------------------------------------------------------------------------//