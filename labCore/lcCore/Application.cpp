#include "Application.h"
#include "../lcPrimatives/Quad.h"
//--------------------------------------------------------------------------------//

Application::Application()
{

}

//--------------------------------------------------------------------------------//

Application::~Application()
{

}

//--------------------------------------------------------------------------------//

bool Application::OnCreate(const char* a_sCmdLine)
{
	Utilities::ConsoleShow(false);

	//System,
	m_pWindow = Window::Create("Demoscene",1080,720, true, false);
	m_pRenderer = DX11Renderer::Create(m_pWindow);
	m_pKeyboard = Keyboard::Create();
	m_pMouse = Mouse::Create();
	GameTime::Create();

	//Camera
	DX11Frustrum oFustrum;
	oFustrum.m_fFieldOfView = ((float)3.145 / 2.0f);
	oFustrum.m_fScreenAspect = ((float)m_pWindow->GetWidth() / (float)m_pWindow->GetHeight());
	oFustrum.m_fNear = 0.01f;
	oFustrum.m_fFar = 100.0f;

	m_pCamera = DX11Camera::Create(oFustrum);

	m_pCamera->SetTranslate(0,0,-10);
	m_pCamera->Update();
	m_pCamera->GetView(mCamera);

	//shader registries
	pData = new Data;
	pData->Position = D3DXVECTOR4(m_pCamera->GetTranslate(), 1);
	pData->ScaleAspect = D3DXVECTOR4(5, oFustrum.m_fScreenAspect, 0, 0);
	pData->DirectionX = mCamera.m[0];
	pData->DirectionY = mCamera.m[1];
	pData->DirectionZ = mCamera.m[2];

	m_pShaderProp = nullptr;
	m_pScene = nullptr;

	//Shaders
	//m_pShaderProp = ShaderProperty::Create("data/Base.hlsl");

	//m_pShaderProp->AddCBuffer("Data", pData , sizeof(Data), 3);

	//Object
	//m_pScene = dynamic_cast<Mesh*>(CreateQuad());
	//m_pScene->AttachProperty(m_pShaderProp);
	
	rotX = 0;
	rotY = 0;

	return true;
}

//--------------------------------------------------------------------------------//

bool Application::OnUpdate()
{
	m_pMouse->Update();
	m_pKeyboard->Update();

	if(m_pKeyboard->IsKeyPressed(KEY_ESCAPE))
	{
		return false;
	}

	if(m_pKeyboard->IsKeyDown(KEY_W))
	{
		int i = 0;
		i++;
	}

	DX11Camera::FreeLookCamera(m_pCamera, 5);

	m_pCamera->GetView(mCamera);

	pData->Position = D3DXVECTOR4(m_pCamera->GetTranslate(), 1);

	pData->DirectionX = mCamera.m[0];
	pData->DirectionY = mCamera.m[1];
	pData->DirectionZ = mCamera.m[2];


	m_pCamera->Update();

	//update buffers to pixel shader
	//m_pShaderProp->UpdateCBuffer("Data", SHADER_PIXEL);

	//m_pScene->Update();
	//Window Update
	return m_pWindow->Tick();
}

//--------------------------------------------------------------------------------//

void Application::OnRender()
{
	m_pRenderer->BeginFrame(D3DXCOLOR(0,0,0,1));
		//m_pRenderer->DrawScene(m_pCamera,m_pScene);
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