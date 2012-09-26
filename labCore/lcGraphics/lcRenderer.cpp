//--------------------------------------------------------------------------------//
//
// \author      Nathan M. Chambers
// \date        01/03/2012
// \brief		Bare bones DirectX 11 Renderer.
//
//--------------------------------------------------------------------------------//
#include "lcRenderer.h"
//--------------------------------------------------------------------------------//
lcRenderer* lcRenderer::m_pSingleton = 0;
//--------------------------------------------------------------------------------//

lcRenderer::lcRenderer()
{
	m_pDevice				= 0;
	m_pDeviceContext		= 0;
	m_pRenderTargetView		= 0;
	m_pSwapChain			= 0;

	m_pDepthStencilBuffer	= 0;
	m_pDepthStencilState	= 0;
	m_pDepthStencilView		= 0;
	m_pRasterState			= 0;
}

//--------------------------------------------------------------------------------//

lcRenderer::~lcRenderer()
{
	//Release Swap chain from Fullscreen
	if(m_pSwapChain)
	{
		m_pSwapChain->SetFullscreenState(false,NULL);
	}

	//Delete the Rasterizer
	if(m_pRasterState)
	{
		m_pRasterState->Release();
		m_pRasterState = 0;
	}
	
	//Delete the Depth Stencil View
	if(m_pDepthStencilView)
	{
		m_pDepthStencilView->Release();
		m_pDepthStencilView = 0;
	}

	//Delete the Depth Stencil State
	if(m_pDepthStencilState)
	{
		m_pDepthStencilState->Release();
		m_pDepthStencilState = 0;
	}

	//Delete the Depth Stencil Buffer
	if(m_pDepthStencilBuffer)
	{
		m_pDepthStencilBuffer->Release();
		m_pDepthStencilBuffer = 0;
	}

	//Delete the Render Target View
	if(m_pRenderTargetView)
	{
		m_pRenderTargetView->Release();
		m_pRenderTargetView = 0;
	}

	//Delete the Device Context
	if(m_pDeviceContext)
	{
		m_pDeviceContext->Release();
		m_pDeviceContext = 0;
	}

	//Delete the Device
	if(m_pDevice)
	{
		m_pDevice->Release();
		m_pDevice = 0;
	}

	//Delete Sawp Chain
	if(m_pSwapChain)
	{
		m_pSwapChain->Release();
		m_pSwapChain = 0;
	}
}

//--------------------------------------------------------------------------------//

lcRenderer* lcRenderer::Create(Window* a_pWindow)
{
	if(!m_pSingleton)
	{
		m_pSingleton = new lcRenderer();

		if(!m_pSingleton->Initialise(a_pWindow))
		{
			delete m_pSingleton;
			m_pSingleton = 0;
		}
	}
	return m_pSingleton;
}

//--------------------------------------------------------------------------------//

lcRenderer* lcRenderer::Get()
{
	return m_pSingleton;
}

//--------------------------------------------------------------------------------//

ID3D11Device* lcRenderer::GetDevice()
{
	if(m_pSingleton)
		return m_pSingleton->m_pDevice;
	return NULL;
}

//--------------------------------------------------------------------------------//

ID3D11DeviceContext* lcRenderer::GetDeviceContext()
{
	if(m_pSingleton)
		return m_pSingleton->m_pDeviceContext;
	return NULL;
}

//--------------------------------------------------------------------------------//

void lcRenderer::BeginFrame(D3DXCOLOR a_oColor)
{
	m_pDeviceContext->ClearRenderTargetView(m_pRenderTargetView,a_oColor);
	m_pDeviceContext->ClearDepthStencilView(m_pDepthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
}

//--------------------------------------------------------------------------------//

void lcRenderer::EndFrame()
{
	m_pSwapChain->Present(0,0);
}

//--------------------------------------------------------------------------------//

void lcRenderer::Release()
{
	if(m_pSingleton)
		delete m_pSingleton;
}

//--------------------------------------------------------------------------------//

bool lcRenderer::Initialise(Window* a_pWindow)
{
	//++++++++++++++++++++++++++++++++++++++++//
	// Driver Types and DX Level
	//++++++++++++++++++++++++++++++++++++++++//

	//Get Driver Types
	D3D_DRIVER_TYPE aDriverTypes[] = 
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_SOFTWARE,
	};

	unsigned int uiTotalDriverTypes = ARRAYSIZE(aDriverTypes);

	//Get DX Feature Levels
	D3D_FEATURE_LEVEL aFeatureLevel[] = 
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3,
		D3D_FEATURE_LEVEL_9_2,
		D3D_FEATURE_LEVEL_9_1,
	};

	unsigned int uiTotalFeatureLevels = ARRAYSIZE(aFeatureLevel);

	//++++++++++++++++++++++++++++++++++++++++//
	// Swap Chain
	//++++++++++++++++++++++++++++++++++++++++//

	//Create Swap Chain Description
	DXGI_SWAP_CHAIN_DESC oSwapDesc;
	ZeroMemory( &oSwapDesc, sizeof(oSwapDesc) );
	oSwapDesc.BufferCount = 1;
	oSwapDesc.BufferDesc.Width = a_pWindow->GetWidth();
	oSwapDesc.BufferDesc.Height = a_pWindow->GetHeight();
	oSwapDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		oSwapDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		oSwapDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	oSwapDesc.BufferDesc.RefreshRate.Numerator = 60;
	oSwapDesc.BufferDesc.RefreshRate.Denominator = 1;
	oSwapDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	oSwapDesc.OutputWindow = a_pWindow->GetHandle();
	oSwapDesc.SampleDesc.Count = 8;
	oSwapDesc.SampleDesc.Quality = 16;
		oSwapDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	oSwapDesc.Windowed = a_pWindow->IsWindowed();

	//Create Swap Chain with Driver Type and Feature Level
	bool bCreateSwapChainPass = false;
	for(unsigned int iDriver = 0;iDriver < uiTotalDriverTypes;++iDriver)
	{
		for(unsigned int iFeature = 0;iFeature < uiTotalFeatureLevels;++iFeature)
		{
			if(!D3D11CreateDeviceAndSwapChain(NULL,aDriverTypes[iDriver],NULL,0,&aFeatureLevel[iFeature],uiTotalFeatureLevels,
				D3D11_SDK_VERSION,&oSwapDesc,&m_pSwapChain,&m_pDevice,NULL,&m_pDeviceContext))
			{
				m_eDriverType = aDriverTypes[iDriver];
				m_eFeatureLevel = aFeatureLevel[iFeature];
				bCreateSwapChainPass = true;
				break;
			}
		}

		if(bCreateSwapChainPass)
			break;
	}

	if(!bCreateSwapChainPass)
		return 0;

	//++++++++++++++++++++++++++++++++++++++++//
	// Back Buffer
	//++++++++++++++++++++++++++++++++++++++++//

	//Create Back Buffer
	ID3D11Texture2D* pBackBuffer;
	if(FAILED(m_pSwapChain->GetBuffer(0,__uuidof(ID3D11Texture2D),(LPVOID*)&pBackBuffer)))
	{
		Utilities::Debug_ConsoleWrite("FAILED TO CREATE SWAP CHAIN");
		return 0;
	}

	//++++++++++++++++++++++++++++++++++++++++//
	// Render Target View
	//++++++++++++++++++++++++++++++++++++++++//

	//Create Render Target View
	if(FAILED(m_pDevice->CreateRenderTargetView(pBackBuffer,NULL,&m_pRenderTargetView)))
	{
		Utilities::Debug_ConsoleWrite("FAILED TO CREATE RENDER TARGET");
		return 0;
	}

	m_pDeviceContext->OMSetRenderTargets(1,&m_pRenderTargetView,NULL);

	//Release Back Buffer
	pBackBuffer->Release();
	pBackBuffer = 0;

	//++++++++++++++++++++++++++++++++++++++++//
	// Depth Buffer
	//++++++++++++++++++++++++++++++++++++++++//

	//Depth Stencil Descripter
	D3D11_TEXTURE2D_DESC oDepthBufferDesc;
	ZeroMemory(&oDepthBufferDesc, sizeof(oDepthBufferDesc));
	oDepthBufferDesc.Width = a_pWindow->GetWidth();
	oDepthBufferDesc.Height = a_pWindow->GetHeight();
	oDepthBufferDesc.MipLevels = 1;
	oDepthBufferDesc.ArraySize = 1;
	oDepthBufferDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		oDepthBufferDesc.SampleDesc.Count = 8;
		oDepthBufferDesc.SampleDesc.Quality = 16;
	oDepthBufferDesc.SampleDesc.Count = 1;
	oDepthBufferDesc.SampleDesc.Quality = 0;
	oDepthBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	oDepthBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	oDepthBufferDesc.CPUAccessFlags = 0;
	oDepthBufferDesc.MiscFlags = 0;

	//Create Depth Buffer
	if(FAILED(m_pDevice->CreateTexture2D(&oDepthBufferDesc, NULL, &m_pDepthStencilBuffer)))
	{
		Utilities::Debug_ConsoleWrite("FAILED TO CREATE BACK BUFFER");
		return 0;
	}

	//++++++++++++++++++++++++++++++++++++++++//
	// Depth Stencil
	//++++++++++++++++++++++++++++++++++++++++//

	//Create Depth Stencil Descripter
	D3D11_DEPTH_STENCIL_DESC oDepthStencilDesc;
	ZeroMemory(&oDepthStencilDesc, sizeof(oDepthStencilDesc));

	oDepthStencilDesc.DepthEnable = true;
	oDepthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	oDepthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;

	oDepthStencilDesc.StencilEnable = true;
	oDepthStencilDesc.StencilReadMask = 0xFF;
	oDepthStencilDesc.StencilWriteMask = 0xFF;

	oDepthStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	oDepthStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
	oDepthStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	oDepthStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	oDepthStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	oDepthStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
	oDepthStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	oDepthStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	//Create Depth Stencil State
	if(FAILED(m_pDevice->CreateDepthStencilState(&oDepthStencilDesc, &m_pDepthStencilState)))
	{
		Utilities::Debug_ConsoleWrite("FAILED TO CREATE DEPTH STENCIL STATE");
		return 0;
	}

	//Set Depth Stencil State
	m_pDeviceContext->OMSetDepthStencilState(m_pDepthStencilState, 1);

	//++++++++++++++++++++++++++++++++++++++++//
	// Depth Stencil View
	//++++++++++++++++++++++++++++++++++++++++//

	//Create Depth Stencil View Desc
	D3D11_DEPTH_STENCIL_VIEW_DESC oDepthStencilViewDesc;
	ZeroMemory(&oDepthStencilViewDesc, sizeof(oDepthStencilViewDesc));

	oDepthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	oDepthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	oDepthStencilViewDesc.Texture2D.MipSlice = 0;

	// Create the depth stencil view.
	if(FAILED(m_pDevice->CreateDepthStencilView(m_pDepthStencilBuffer, &oDepthStencilViewDesc, &m_pDepthStencilView)))
	{
		Utilities::Debug_ConsoleWrite("FAILED TO CREATE SWAP CHAIN");
		return 0;
	}

	m_pDeviceContext->OMSetRenderTargets(1, &m_pRenderTargetView, m_pDepthStencilView);

	//++++++++++++++++++++++++++++++++++++++++//
	// Rasterizer
	//++++++++++++++++++++++++++++++++++++++++//

	//Create Rasterizer Descripter
	D3D11_RASTERIZER_DESC oRasterDesc;
	ZeroMemory(&oRasterDesc, sizeof(oRasterDesc));
	oRasterDesc.AntialiasedLineEnable = false;
	oRasterDesc.CullMode = D3D11_CULL_BACK;
	oRasterDesc.DepthBias = 0;
	oRasterDesc.DepthBiasClamp = 0.0f;
	oRasterDesc.DepthClipEnable = true;
	oRasterDesc.FillMode = D3D11_FILL_SOLID;
	oRasterDesc.FrontCounterClockwise = false;
	oRasterDesc.MultisampleEnable = false;
	oRasterDesc.ScissorEnable = false;
	oRasterDesc.SlopeScaledDepthBias = 0.0f;

	// Create the rasterizer state from the description we just filled out.
	if(FAILED(m_pDevice->CreateRasterizerState(&oRasterDesc, &m_pRasterState)))
		return 0;

	//++++++++++++++++++++++++++++++++++++++++//
	// View Port
	//++++++++++++++++++++++++++++++++++++++++//

	//Create and Set View Port
	D3D11_VIEWPORT oViewPort;	 
	oViewPort.Width = (float)a_pWindow->GetWidth();
	oViewPort.Height = (float)a_pWindow->GetHeight();
	oViewPort.MinDepth = 0.0f;
	oViewPort.MaxDepth = 1.0f;
	oViewPort.TopLeftX = 0;
	oViewPort.TopLeftY = 0;

	m_pDeviceContext->RSSetViewports(1,&oViewPort);

	//++++++++++++++++++++++++++++++++++++++++//
	// World Matrix Buffer
	//++++++++++++++++++++++++++++++++++++++++//
	 
	D3D11_BUFFER_DESC oMatrixBufferDesc;
	oMatrixBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	oMatrixBufferDesc.ByteWidth = sizeof(D3DXMATRIX);
	oMatrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	oMatrixBufferDesc.CPUAccessFlags = 0;
	oMatrixBufferDesc.MiscFlags = 0;
	oMatrixBufferDesc.StructureByteStride = 0;

	if(FAILED(m_pDevice->CreateBuffer(&oMatrixBufferDesc,NULL,&m_pCBWorld)))
		return 0;

	if(FAILED(m_pDevice->CreateBuffer(&oMatrixBufferDesc,NULL,&m_pCBViewProj)))
		return 0;


	//++++++++++++++++++++++++++++++++++++++++//
	// Shader Constant Buffers
	//++++++++++++++++++++++++++++++++++++++++//

	D3DXMATRIX mWorld;
	D3DXMatrixIdentity(&mWorld);
	m_pDeviceContext->UpdateSubresource(m_pCBWorld,0,NULL,&mWorld,0,0);

	D3DXMATRIX mViewProj;
	D3DXMatrixIdentity(&mViewProj);
	m_pDeviceContext->UpdateSubresource(m_pCBViewProj,0,NULL,&mViewProj,0,0);
	
	return true;
}

//--------------------------------------------------------------------------------//

void lcRenderer::DrawScene(lcCamera* a_pCamera,lcNode* a_pRootNode)
{
	//Update ViewProj
	D3DXMATRIX mViewProj;
	a_pCamera->GetViewProj(mViewProj);
	D3DXMatrixTranspose(&mViewProj,&mViewProj);

	m_pDeviceContext->UpdateSubresource(m_pCBViewProj,0,NULL,&mViewProj,0,0);
	m_pDeviceContext->VSSetConstantBuffers(1,1,&m_pCBViewProj);
	
	//CULLING HERE!

	if(a_pRootNode->GetChildCount() > 0)
		TraverseChildren(a_pRootNode);
	else
		RenderNode(a_pRootNode);	
}

//--------------------------------------------------------------------------------//

void lcRenderer::TraverseChildren(lcNode* a_pRootNode)
{
	if(a_pRootNode->GetChildCount() > 0)
	{
		for(unsigned int i = 0;i < a_pRootNode->GetChildCount();i++)
		{
			lcNode* pChild = a_pRootNode->GetAt(i);

			if(pChild->GetChildCount() > 0)
			{
				TraverseChildren(pChild);
			}
			else
			{
				RenderNode(pChild);
			}
		}
	}

	RenderNode(a_pRootNode);
}

//--------------------------------------------------------------------------------//

void lcRenderer::RenderNode(lcNode* a_pNode)
{
	lcMesh* pMesh = dynamic_cast<lcMesh*>(a_pNode);
	if(pMesh)
	{
		//Update World Matrix
		D3DXMATRIX mWorldMatrix;
		pMesh->GetWorldTransform(mWorldMatrix);
		D3DXMatrixTranspose(&mWorldMatrix,&mWorldMatrix);

		m_pDeviceContext->UpdateSubresource(m_pCBWorld,0,NULL,&mWorldMatrix,0,0);
		m_pDeviceContext->VSSetConstantBuffers(0,1,&m_pCBWorld);

		//Set Shaders
		m_pDeviceContext->VSSetShader(pMesh->m_pVertexShader,NULL,0);
		m_pDeviceContext->PSSetShader(pMesh->m_pPixelShader,NULL,0);

		//Set Input
		m_pDeviceContext->IASetInputLayout(pMesh->m_pInputLayout);
		m_pDeviceContext->IASetVertexBuffers(0,1,&pMesh->m_pVertexBuffer,&pMesh->m_uiStride,&pMesh->m_uiOffset);
		m_pDeviceContext->IASetIndexBuffer(pMesh->m_pIndexBuffer,DXGI_FORMAT_R32_UINT,0);
		m_pDeviceContext->IASetPrimitiveTopology(pMesh->m_oTopology);


		//Render
		m_pDeviceContext->DrawIndexed(pMesh->m_uiIndexCount,0,0);
	}
}

//--------------------------------------------------------------------------------//