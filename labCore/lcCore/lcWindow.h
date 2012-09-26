//--------------------------------------------------------------------------------//
//
// \author      Conan H. Bourke
// \date        13/01/2012
// \brief		Simple Win32 window wrapper.
//
//--------------------------------------------------------------------------------//
#ifndef __LCWINDOW_H_
#define __LCWINDOW_H_
//--------------------------------------------------------------------------------//
#include <windows.h>
#include "lcMouse.h"
//--------------------------------------------------------------------------------//
class lcMouse;
//--------------------------------------------------------------------------------//

class Window
{
public:
	////////////////////////////////////////////////////////////////////////////////
	// \brief	: Creates a Window Class
	// \args	: const char* (a_szName)
	//				Name of the Window
	////////////////////////////////////////////////////////////////////////////////
	
	static Window* Create(const char* a_szName, int a_iWidth = 640, int a_iHeight = 480,bool a_bWindowed = true, bool a_bHasBorder = true);
	static Window* Get();
	void Release();

	HWND	GetHandle();
	int		GetWidth();
	int		GetHeight();
	bool	IsActive();
	bool	IsWindowed();

	bool	Tick();

	void AttachMouse(lcMouse *a_pMouse);

private:
	Window(const char* a_szName, int a_iWidth, int a_iHeight,bool a_bWindowed, bool a_bHasBorder);
	~Window();

	static Window* m_pSingleton;

	HWND	m_oHwnd;
	int		m_iWidth;
	int		m_iHeight;

	HINSTANCE m_hInstance;
	bool	m_bWindowed;

	WNDCLASSEX	sm_oWindowclass;

	static lcMouse*	m_pMouse;
	
	static LRESULT CALLBACK WindowProc(HWND Handle, unsigned int msg, WPARAM wParam, LPARAM lParam);

};

//--------------------------------------------------------------------------------//
#endif // __WINDOW_H_
//--------------------------------------------------------------------------------//