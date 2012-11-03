#ifndef __APPLICATION_H_
#define __APPLICATION_H_

#include "lcAppBase.h"
#include "lcWindow.h"
#include "lcRenderer.h"
#include "lcCamera.h"
#include "lcKeyboard.h"
#include "lcMouse.h"
#include "lcMesh.h"
#include "lcShaderProperty.h"
#include "lcUtilities.h"
#include "lcTimers.h"

class Application : public AppBase
{
public: 
	Application();
	~Application();

	bool OnCreate();
	void OnDestroy();
	bool OnUpdate();
	void OnRender();

private:
	Window*			m_pWindow;
	lcRenderer*		m_pRenderer;

	lcKeyboard*		m_pKeyboard;
	lcMouse*		m_pMouse;

	lcCamera*		m_pCamera;
	ShaderProperty* m_pShaderProp;
};

#endif