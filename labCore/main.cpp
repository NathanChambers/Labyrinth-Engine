//--------------------------------------------------------------------------------//
//
// \author		Nathan M. Chambers
// \brief		Testing the framework (ONLY USED IN DEBUG MODE)
//
//--------------------------------------------------------------------------------//

#include "AppBase.h"
#include "Window.h"
#include "DX11Renderer.h"
#include "DX11Camera.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Mesh.h"
#include "ShaderProperty.h"
#include "Utilities.h"
#include "TestObject.h"

#include <vector>
#include <D3Dcompiler.h>

#include "Cube.h"
#include "Timers.h"
#include "Matrix.h"

//--------------------------------------------------------------------------------//

class Application : public AppBase
{
public: 
	Application();
	~Application();

	bool OnCreate(const char* a_sCmdLine);
	void OnDestroy();
	bool OnUpdate();
	void OnRender();

private:
	Window*			m_pWindow;
	DX11Renderer*	m_pRenderer;
	Keyboard*		m_pKeyboard;
	Mouse*			m_pMouse;
	GameTime*		m_pGameTime;


	DX11Camera*		m_pCamera;
	ShaderProperty*	m_pShaderProp;

	Node*			m_pScene;
	Mesh*			m_pParent;
	Mesh*			m_pChild;

	float			m_fRot;
};

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
	Utilities::ConsoleShow(true);

	//System
	m_pWindow = Window::Create("Ichor Window",1024,768);
	m_pRenderer = DX11Renderer::Create(m_pWindow);
	m_pGameTime = GameTime::Create();

	//Input
	m_pKeyboard = Keyboard::Create();
	m_pMouse = Mouse::Create();
	m_pWindow->AttachMouse(m_pMouse);

	//Camera
	DX11Frustrum oFustrum;
	oFustrum.m_fFieldOfView = ((F32)PI_HALF / 2.0f);
	oFustrum.m_fScreenAspect = ((F32)m_pWindow->GetWidth() / (F32)m_pWindow->GetHeight());
	oFustrum.m_fNear = 0.01f;
	oFustrum.m_fFar = 100.0f;

	m_pCamera = DX11Camera::Create(oFustrum);
	m_pCamera->SetTranslate(0.0f,0.0f,-10.0f);

	struct sData
	{
		char cInitial;
		int iVal;
		float fVal;
		double dVal;
		long long llVal;
		char cVal;
	};

	sData* fDelta = new sData;
			
	//Shaders
	m_pShaderProp = ShaderProperty::Create("./Data/Shaders/Base.hlsl");
	m_pShaderProp->AddCBuffer("Matrix",fDelta,sizeof(sData),0);

	//OBJECTS

	//Scene
	m_pScene = new Node("Scene");
	
	//Cube
	m_pParent = dynamic_cast<Mesh*>(CreateCube());
	m_pParent->AttachProperty(m_pShaderProp);
	m_pParent->SetTranslate(1,0,0);

	m_pChild = dynamic_cast<Mesh*>(m_pParent->Clone());
	m_pChild->SetTranslate(-5,0,0);

	m_pParent->Update();
	m_pChild->Update();

	//Parenting
	m_pScene->AttachChild(m_pParent);
	m_pParent->AttachChild(m_pChild);
	

	m_fRot = 0.0f;

	return true;
}

//--------------------------------------------------------------------------------//

bool Application::OnUpdate()
{
	//System Update
	m_pMouse->Update();
	m_pKeyboard->Update();
	m_pCamera->Update();
	m_pGameTime->Update();

	//m_fRot += PI * GameTime::GetTimeElapsed();
	//m_pScene->SetRotateY(m_fRot);

	m_pScene->Update();

	if(m_pKeyboard->IsKeyPressed(KEY_1))
	{
		m_pParent->DetachChild(m_pChild);
	}
	else if(m_pKeyboard->IsKeyPressed(KEY_2))
	{
		m_pParent->AttachChild(m_pChild);
	}

	m_pChild->Update();

	DX11Camera::FreeLookCamera(m_pCamera,10.0f);
	//m_pCamera->LookAt(D3DXVECTOR3(0,0,0));

	

	//Window Update
	return m_pWindow->Tick();
}

//--------------------------------------------------------------------------------//

void Application::OnRender()
{
	m_pRenderer->BeginFrame(D3DXCOLOR(0,0,0,1));
		m_pRenderer->DrawScene(m_pCamera,m_pScene);
		//m_pRenderer->DrawScene(m_pCamera,m_pChild);
	m_pRenderer->EndFrame();
}

//--------------------------------------------------------------------------------//

void Application::OnDestroy()
{
	if(m_pShaderProp)
		delete m_pShaderProp;

	if(m_pScene)
		delete m_pScene;

	m_pGameTime->Release();


	m_pCamera->Release();
	m_pRenderer->Release();
	m_pWindow->Release();
	m_pMouse->Release();
	m_pKeyboard->Release();
}

//--------------------------------------------------------------------------------//

I32 WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,I32 iShowCmd)
{	
	// create our application instance
	AppBase* pApp = new Application();

	// if successfully created, start main game loop
	if (pApp->Create(lpCmdLine))
	{
		pApp->Execute();
	}

	// cleanup memory
	delete pApp;

	_CrtDumpMemoryLeaks();

	return 0;
}

//--------------------------------------------------------------------------------//