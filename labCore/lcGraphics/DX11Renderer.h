//--------------------------------------------------------------------------------//
//
// \author      Nathan M. Chambers
// \date        01/03/2012
// \brief		Bare bones DirectX 11 Renderer.
//
//--------------------------------------------------------------------------------//
#ifndef __DX11RENDERER_H_
#define __DX11RENDERER_H_
//--------------------------------------------------------------------------------//
#include <D3D11.h>

#include "DX11Camera.h"
#include "../lcCore/Window.h"
#include "../lcPrimatives/Mesh.h"
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

class DX11Renderer
{
public:
	static DX11Renderer* Create(Window* a_pWindow);
	static DX11Renderer* Get();
	void Release();

	static ID3D11Device* GetDevice();
	static ID3D11DeviceContext* GetDeviceContext();

	void BeginFrame(D3DXCOLOR ClearColor);
	void EndFrame();
	void DrawScene(DX11Camera* Camera,Node* SceneNode);

private:
	DX11Renderer();
	~DX11Renderer();

	bool Initialise(Window* a_pWindow);
	void RenderNode(Node*);
	void TraverseChildren(Node*);

	static DX11Renderer*		m_pSingleton;
	
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