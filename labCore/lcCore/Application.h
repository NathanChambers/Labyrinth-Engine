#ifndef __APPLICATION_H_
#define __APPLICATION_H_

#include "AppBase.h"
#include "Window.h"
#include "DX11Renderer.h"
#include "DX11Camera.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Mesh.h"
#include "ShaderProperty.h"
#include "Utilities.h"
#include "Timers.h"

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

	DX11Camera*		m_pCamera;
	ShaderProperty* m_pShaderProp;
	Mesh*			m_pScene;
};

#endif