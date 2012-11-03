//--------------------------------------------------------------------------------//
//
// \author		Nathan M. Chambers
// \date        29/02/2012
// \brief		Simple lcMouse Wrapper
//
//--------------------------------------------------------------------------------//
#include "lcMouse.h"
#include "lcWindow.h"
//--------------------------------------------------------------------------------//
lcMouse* lcMouse::m_pSingleton = 0;
//--------------------------------------------------------------------------------//

lcMouse::lcMouse()
{
	int aButtonTypes[] = 
	{
		VK_LBUTTON,
		VK_RBUTTON,
		VK_MBUTTON
	};

	m_iXPrev = -1;
	m_iYPrev = -1;

	m_pVKMap = new int[BUTTON_COUNT];
	memcpy(m_pVKMap,aButtonTypes,sizeof(BUTTON_COUNT)*sizeof(int));
	memset(m_bButtonCurr,0,sizeof(m_bButtonCurr));
	memset(m_bButtonPrev,0,sizeof(m_bButtonPrev));

	m_uiScrollVal = 0;
	m_bScrollingUp = false;
	m_bScrollingDown = false;

	m_bScreenLocked = false;
}

//--------------------------------------------------------------------------------//

lcMouse::~lcMouse()
{
	if(m_pVKMap)
		delete m_pVKMap;
}

//--------------------------------------------------------------------------------//

lcMouse* lcMouse::Create()
{
	if(!m_pSingleton)
		m_pSingleton = new lcMouse();
	return m_pSingleton;
}

//--------------------------------------------------------------------------------//

lcMouse* lcMouse::Get()
{
	return m_pSingleton;
}

//--------------------------------------------------------------------------------//

void lcMouse::Release()
{
	if(m_pSingleton)
		delete m_pSingleton;
}

//--------------------------------------------------------------------------------//
#include <assert.h>
void lcMouse::Update()
{
	if (!Window::Get()->IsActive())
		return;

	if(m_bScreenLocked)
	{
		RECT kWndRect;
		GetWindowRect(Window::Get()->GetHandle(),&kWndRect);
		ClipCursor(&kWndRect);
	}
	else
	{
		ClipCursor(nullptr);
	}

	m_iXPrev = m_iXCurr;
	m_iYPrev = m_iYCurr;

	POINT oPos;
	GetCursorPos(&oPos);

	m_iXCurr = oPos.x;
	m_iYCurr = oPos.y;

	for(int iBtn = 0;iBtn < BUTTON_COUNT;++iBtn)
	{
		m_bButtonPrev[iBtn] = m_bButtonCurr[iBtn];
		short iResult = GetAsyncKeyState(m_pVKMap[iBtn]);
		if(iResult != 0)
			m_bButtonCurr[iBtn] = true;
		else
			m_bButtonCurr[iBtn] = false;
	}

	if(m_uiScrollVal > 0)
	{
		m_bScrollingUp = true;
		m_bScrollingDown = false;
	}
	else if(m_uiScrollVal < 0)
	{
		m_bScrollingUp = false;
		m_bScrollingDown = true;
	}
	else
	{
		m_bScrollingUp = false;
		m_bScrollingDown = false;
	}



	m_uiScrollVal = 0;
}

void lcMouse::Show(bool a_bShow)
{
	ShowCursor(a_bShow);
}

//--------------------------------------------------------------------------------//

void lcMouse::GetPosition(int& a_iX,int& a_iY)
{	
	POINT oMousePoint;
	oMousePoint.x = m_iXCurr;
	oMousePoint.y = m_iYCurr;

	ScreenToClient(Window::Get()->GetHandle(),&oMousePoint);

	a_iX = oMousePoint.x;
	a_iY = oMousePoint.y;
}

//--------------------------------------------------------------------------------//

void lcMouse::GetPositionToScreen(int& a_iX,int& a_iY)
{
	a_iX = m_iXCurr;
	a_iY = m_iYCurr;
}

//--------------------------------------------------------------------------------//

void lcMouse::GetDeltaPosition(int& a_iX,int& a_iY)
{
	if(m_iXPrev >= 0 || m_iYPrev >= 0)
	{
		a_iX = m_iXCurr - m_iXPrev;
		a_iY = m_iYCurr - m_iYPrev;
	}
	else
	{
		a_iX = 0;
		a_iY = 0;
	}
}

//--------------------------------------------------------------------------------//

bool lcMouse::IsButtonDown(eBUTTONS a_uiButton)
{
	if(m_pSingleton->m_bButtonCurr[a_uiButton] && m_pSingleton->m_bButtonPrev[a_uiButton])
	{
		return true;
	}
	return false;
}

//--------------------------------------------------------------------------------//

bool lcMouse::IsButtonUp(eBUTTONS a_uiButton)
{
	if(!m_pSingleton->m_bButtonCurr[a_uiButton] && !m_pSingleton->m_bButtonPrev[a_uiButton])
	{
		return true;
	}
	return false;
}

//--------------------------------------------------------------------------------//

bool lcMouse::IsButtonPressed(eBUTTONS a_uiButton)
{
	if(m_pSingleton->m_bButtonCurr[a_uiButton] && !m_pSingleton->m_bButtonPrev[a_uiButton])
	{
		return true;
	}
	return false;
}

//--------------------------------------------------------------------------------//

bool lcMouse::IsButtonReleased(eBUTTONS a_uiButton)
{
	if(!m_pSingleton->m_bButtonCurr[a_uiButton] && m_pSingleton->m_bButtonPrev[a_uiButton])
	{
		return true;
	}
	return false;
}

//--------------------------------------------------------------------------------//

bool lcMouse::IsScrollingUp()
{
	return m_pSingleton->m_bScrollingUp;
}

//--------------------------------------------------------------------------------//

bool lcMouse::IsScrollingDown()
{
	return m_pSingleton->m_bScrollingDown;
}

//--------------------------------------------------------------------------------//

void lcMouse::LockToWindow(bool a_bLocked)
{
	m_bScreenLocked = a_bLocked;
}