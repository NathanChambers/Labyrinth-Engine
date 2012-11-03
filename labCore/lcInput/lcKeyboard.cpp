//--------------------------------------------------------------------------------//
//
// \author		Nathan M. Chambers
// \date        29/02/2012
// \brief		Simple lcKeyboard Wrapper
//
//--------------------------------------------------------------------------------//
#include "lcKeyboard.h"
#include "lcWindow.h"
#include <windows.h>
//--------------------------------------------------------------------------------//
lcKeyboard* lcKeyboard::m_pSingleton = 0;
//--------------------------------------------------------------------------------//

lcKeyboard::lcKeyboard()
{
	memset(m_uiKeysCurr,0,sizeof(m_uiKeysCurr));
	memset(m_uiKeysPrev,0,sizeof(m_uiKeysPrev));
}

//--------------------------------------------------------------------------------//

lcKeyboard::~lcKeyboard()
{

}

//--------------------------------------------------------------------------------//

lcKeyboard* lcKeyboard::Create()
{
	if(!m_pSingleton)
		m_pSingleton = new lcKeyboard();
	return m_pSingleton;

}

//--------------------------------------------------------------------------------//

lcKeyboard* lcKeyboard::Get()
{
	return m_pSingleton;
}

//--------------------------------------------------------------------------------//

void lcKeyboard::Release()
{
	if(m_pSingleton)
		delete m_pSingleton;
}

//--------------------------------------------------------------------------------//

void lcKeyboard::Update()
{
	if (!Window::Get()->IsActive())
		return;

	for(int i = 0;i < 256;i++)
	{
		m_uiKeysPrev[i] = m_uiKeysCurr[i];
		short iResult = GetAsyncKeyState(i);

		if(iResult != 0)
			m_uiKeysCurr[i] = true;
		else
			m_uiKeysCurr[i] = false;
	}
}

//--------------------------------------------------------------------------------//

bool lcKeyboard::IsKeyDown(short a_oKey)
{
	if(m_pSingleton->m_uiKeysCurr[a_oKey] && m_pSingleton->m_uiKeysPrev[a_oKey])
	{
		return true;
	}
	return false;
}

//--------------------------------------------------------------------------------//

bool lcKeyboard::IsKeyUp(short a_oKey)
{
	if(!m_pSingleton->m_uiKeysCurr[a_oKey] && !m_pSingleton->m_uiKeysPrev[a_oKey])
	{
		return true;
	}
	return false;
}

//--------------------------------------------------------------------------------//

bool lcKeyboard::IsKeyPressed(short a_oKey)
{
	if(m_pSingleton->m_uiKeysCurr[a_oKey] && !m_pSingleton->m_uiKeysPrev[a_oKey])
	{
		return true;
	}
	return false;
}

//--------------------------------------------------------------------------------//

bool lcKeyboard::IsKeyReleased(short a_oKey)
{
	if(!m_pSingleton->m_uiKeysCurr[a_oKey] && m_pSingleton->m_uiKeysPrev[a_oKey])
	{
		return true;
	}
	return false;	
}

//--------------------------------------------------------------------------------//