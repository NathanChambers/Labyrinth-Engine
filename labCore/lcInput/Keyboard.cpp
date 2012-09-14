//--------------------------------------------------------------------------------//
//
// \author		Nathan M. Chambers
// \date        29/02/2012
// \brief		Simple Keyboard Wrapper
//
//--------------------------------------------------------------------------------//
#include "Keyboard.h"
#include <windows.h>
//--------------------------------------------------------------------------------//
Keyboard* Keyboard::m_pSingleton = 0;
//--------------------------------------------------------------------------------//

Keyboard::Keyboard()
{
	memset(m_uiKeysCurr,0,sizeof(m_uiKeysCurr));
	memset(m_uiKeysPrev,0,sizeof(m_uiKeysPrev));
}

//--------------------------------------------------------------------------------//

Keyboard::~Keyboard()
{

}

//--------------------------------------------------------------------------------//

Keyboard* Keyboard::Create()
{
	if(!m_pSingleton)
		m_pSingleton = new Keyboard();
	return m_pSingleton;

}

//--------------------------------------------------------------------------------//

Keyboard* Keyboard::Get()
{
	return m_pSingleton;
}

//--------------------------------------------------------------------------------//

void Keyboard::Release()
{
	if(m_pSingleton)
		delete m_pSingleton;
}

//--------------------------------------------------------------------------------//

void Keyboard::Update()
{
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

bool Keyboard::IsKeyDown(short a_oKey)
{
	if(m_uiKeysCurr[a_oKey] && m_uiKeysPrev[a_oKey])
	{
		return true;
	}
	return false;
}

//--------------------------------------------------------------------------------//

bool Keyboard::IsKeyUp(short a_oKey)
{
	if(!m_uiKeysCurr[a_oKey] && !m_uiKeysPrev[a_oKey])
	{
		return true;
	}
	return false;
}

//--------------------------------------------------------------------------------//

bool Keyboard::IsKeyPressed(short a_oKey)
{
	if(m_uiKeysCurr[a_oKey] && !m_uiKeysPrev[a_oKey])
	{
		return true;
	}
	return false;
}

//--------------------------------------------------------------------------------//

bool Keyboard::IsKeyReleased(short a_oKey)
{
	if(!m_uiKeysCurr[a_oKey] && m_uiKeysPrev[a_oKey])
	{
		return true;
	}
	return false;	
}

//--------------------------------------------------------------------------------//