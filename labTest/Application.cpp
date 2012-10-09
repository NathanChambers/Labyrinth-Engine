#include "Application.h"
#include "lcTimers.h"
#include "lcCube.h"
#include "lmCore.h"

lcMesh* kBox;

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

bool Application::OnCreate(const char* a_sCmdLine)
{
	Utilities::ConsoleShow(true);

	//System,
	m_pWindow = Window::Create("Labyrinth Test App",1080,720);
	m_pRenderer = lcRenderer::Create(m_pWindow);
	m_pKeyboard = lcKeyboard::Create();
	m_pMouse = lcMouse::Create();
	lcTime::Create();

	//Camera
	lcFrustrum oFustrum;
	oFustrum.m_fFieldOfView = ((float)3.145 / 2.0f);
	oFustrum.m_fScreenAspect = ((float)m_pWindow->GetWidth() / (float)m_pWindow->GetHeight());
	oFustrum.m_fNear = 0.01f;
	oFustrum.m_fFar = 100.0f;

	m_pCamera = lcCamera::Create(oFustrum);

	m_pCamera->SetTranslate(0,0,-10);
	m_pCamera->Update();

	m_pScene = new lcNode();

	ShaderProperty* pkShaderProp = ShaderProperty::Create("./data/shaders/base.hlsl");

	return true;
}

//--------------------------------------------------------------------------------//

bool Application::OnUpdate()
{
	lcTime::Get()->Update();
	m_pMouse->Update();
	m_pKeyboard->Update();

	if(m_pKeyboard->IsKeyPressed(KEY_ESCAPE))
	{
		return false;
	}

	lcCamera::FreeLookCamera(m_pCamera,2.0f);
	m_pCamera->Update();

	m_pScene->Update();
	

	return m_pWindow->Tick();
}

//--------------------------------------------------------------------------------//

void Application::OnRender()
{
	m_pRenderer->BeginFrame(D3DXCOLOR(0,0,0,1));
		m_pRenderer->DrawScene(m_pCamera,m_pScene);
	m_pRenderer->EndFrame();
}

//--------------------------------------------------------------------------------//

void Application::OnDestroy()
{
	if(m_pShaderProp)
		delete m_pShaderProp;

	if(m_pScene)
		delete m_pScene;

	m_pWindow->Release();
	m_pRenderer->Release();
	m_pCamera->Release();
}

//--------------------------------------------------------------------------------//