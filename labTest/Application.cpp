
#include "Application.h"
#include "lcTimers.h"
#include "lcScreenMesh.h"
#include "lcCube.h"
#include "lmCore.h"
#include "lcAssert.h"
#include "lcMemTracker.h"
#include "lcCube.h"
#include "lcMatrix.h"
#include "lcTexture2D.h"
#include "lcTextureProperty.h"

#include "AntTweakBar.h"

lcNode*	m_pScene;
lcMesh* g_pkBox;

ShaderProperty* pkShader;
ID3D11ShaderResourceView* CubeTexture;
ID3D11ShaderResourceView* CubeTexture2;
ID3D11SamplerState* CubeSampleState;

TwBar* g_pkDevTweakBar;

D3DXVECTOR3 g_kRootPosition;
D3DXQUATERNION g_kRootRotation;
lcTexture2D* kTexture;

bool g_bAttached = true;
bool g_bWireframe = false;
lmMatrix4 kMatrix;

void HandleShaderFiles(const char* a_szFilename)
{
	const char* pEnd = strchr(a_szFilename,'\0');
	while((*pEnd) != '.')
	{
		pEnd--;
	}
	char szExtension[32];
	strncpy_s(szExtension,pEnd,strlen(pEnd) + 1);
	

	if(strstr(szExtension,".hlsl"))
	{
		pkShader->LoadFromFile(a_szFilename);
		m_pScene->UpdateProperties();
	}
	else if(strstr(szExtension,".jpg") || strstr(szExtension,".png") || strstr(szExtension,".bmp") || strstr(szExtension,".tif"))
	{
		ID3D11ShaderResourceView* NewTexture = nullptr;
		D3DX11CreateShaderResourceViewFromFile(lcRenderer::GetDevice(),a_szFilename,nullptr,nullptr,&NewTexture,nullptr);

		if(NewTexture)
		{
			CubeTexture = NewTexture;
			return;
		}
	}
}

//--------------------------------------------------------------------------------//

Application::Application()
{
	m_pShaderProp = nullptr;
	m_pScene = nullptr;
}

//--------------------------------------------------------------------------------//

Application::~Application()
{

}

//--------------------------------------------------------------------------------//

bool Application::OnCreate()
{
	Utilities::ConsoleShow(true);

	//System
	m_pWindow = Window::Create("Labyrinth Test App",1280,720,true,true);
	m_pRenderer = lcRenderer::Create(m_pWindow);
	m_pKeyboard = lcKeyboard::Create();
	m_pMouse = lcMouse::Create();
	lcTime::Create();

	m_pWindow->EnableFileDrop(true);
	m_pWindow->OnDropFile = &HandleShaderFiles;
	//m_pMouse->LockToWindow(true);

	g_pkDevTweakBar = TwNewBar("DevBar");

	//Camera
	lcFrustrum oFustrum;
	oFustrum.m_fFieldOfView = ((float)LM_PI_HALF * 0.5f);
	oFustrum.m_fScreenAspect = ((float)Window::Width() / (float)Window::Height());
	oFustrum.m_fNear = 0.01f;
	oFustrum.m_fFar = 1000000.0f;

	m_pCamera = lcCamera::Create(oFustrum);

	m_pCamera->SetTranslate(D3DXVECTOR3(0,0,-10));
	m_pCamera->LookAt(D3DXVECTOR3(0,0,0));
	m_pCamera->Update();

	m_pScene = new lcNode();
	pkShader = ShaderProperty::Create("./data/shaders/diff.hlsl");

	g_pkBox = dynamic_cast<lcMesh*>(CreateCube(lmVec3(0,0,0),lmVec3(1,1,1)));
	g_pkBox->AttachProperty(pkShader);

	m_pScene->AttachChild(g_pkBox);

	TwStructMember positionDef[] = 
	{
		{"X",TW_TYPE_FLOAT,0,"step=0.01"},
		{"Y",TW_TYPE_FLOAT,4,"step=0.01"},
		{"Z",TW_TYPE_FLOAT,8,"step=0.01"}
	};
	TwType positionType = TwDefineStruct("PositionType",positionDef,3,sizeof(D3DXVECTOR3),nullptr,nullptr);
	
	//Movement Bar
	//TwAddVarRW(g_pkDevTweakBar,"Wireframe",TW_TYPE_BOOL8,&g_bWireframe,nullptr);
	//TwAddSeparator(g_pkDevTweakBar,"Space0",nullptr);

	TwAddVarRW(g_pkDevTweakBar,"Root Translate",positionType,&g_kRootPosition,nullptr);
	TwAddVarRW(g_pkDevTweakBar,"Root Rotate",TW_TYPE_QUAT4F,&g_kRootRotation,nullptr);

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//CREATE TEXTURE PROPERTY SO THAT TEXTURES CHANGE PER OBJECT USING THE SAME SHADER HURR DURR
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	lcTexture2D* pkCrateTexture = new lcTexture2D("./data/textures/crate.jpg");
	lcTexture2D* pkDevTexture = new lcTexture2D("./data/textures/dev01.png");

	lcTextureProperty* pkTextures = new lcTextureProperty();
	pkTextures->SetDiffuse(pkCrateTexture);
	pkTextures->SetNormal(pkDevTexture);
	g_pkBox->AttachProperty(pkTextures);


	D3D11_SAMPLER_DESC sampDesc;
	ZeroMemory( &sampDesc, sizeof(sampDesc) );
	sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
    sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
    sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
    sampDesc.MinLOD = 0;
    sampDesc.MaxLOD = D3D11_FLOAT32_MAX;

	lcRenderer::GetDevice()->CreateSamplerState(&sampDesc,&CubeSampleState);

	lmMatrix4 kYRot;
	lmMatrix4 kXRot;

	kYRot.MakeYRotate(LM_PI_HALF / 2.0f);
	kXRot.MakeXRotate(LM_PI_HALF / 2.0f);
	
	lmMatrix4 kOutMat;
	lmMatrix4Mul(kOutMat,kXRot,kYRot);

	g_pkBox->SetRotate(kOutMat.m_v);

	
	return true;
}

//--------------------------------------------------------------------------------//

bool Application::OnUpdate()
{
	lcTime::Get()->Update();
	m_pKeyboard->Update();
	m_pMouse->Update();

	lcCamera::FreeLookCamera(m_pCamera,1.0f,1.0f);
	m_pCamera->Update();
	
	if(lcKeyboard::IsKeyDown(KEY_ESCAPE))
		return 0;

	D3DXMATRIX outMat;
	D3DXQUATERNION invQuat;

	m_pScene->SetTranslate(g_kRootPosition);

	D3DXQUATERNION tempq;
	D3DXVECTOR3 tempAxis;
	float tempAngle;

	D3DXQuaternionToAxisAngle(&g_kRootRotation, &tempAxis, &tempAngle);
	tempAxis = -tempAxis;
	D3DXQuaternionRotationAxis(&tempq, &tempAxis, tempAngle);

	D3DXMatrixRotationQuaternion(&outMat,&tempq);
	m_pScene->SetRotate(outMat);

	if(g_bWireframe)
	{
		g_pkBox->SetPrimativeTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);
	}
	else
	{
		g_pkBox->SetPrimativeTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	}


	lcRenderer::GetDeviceContext()->PSSetSamplers(0,1,&CubeSampleState);

	m_pScene->Update();

	return m_pWindow->Tick();
}



//--------------------------------------------------------------------------------//

void Application::OnRender()
{
	m_pRenderer->BeginFrame(D3DXCOLOR(0.15f,0.15f,0.2f,1.0f));
		m_pRenderer->DrawScene(m_pCamera,m_pScene);
		TwDraw();
	m_pRenderer->EndFrame();
}

//--------------------------------------------------------------------------------//

void Application::OnDestroy()
{
	if(m_pScene)
		delete m_pScene;

	m_pWindow->Release();
	m_pRenderer->Release();
	m_pCamera->Release();

	TwTerminate();
}

//--------------------------------------------------------------------------------//