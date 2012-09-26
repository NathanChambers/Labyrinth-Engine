//--------------------------------------------------------------------------------//
//
// \author      Conan H. Bourke
// \date        13/01/2012
// \brief		Simple Win32 window wrapper.
//
//--------------------------------------------------------------------------------//
#include "lcWindow.h"
//--------------------------------------------------------------------------------//
lcMouse* Window::m_pMouse = 0;
Window* Window::m_pSingleton = 0;
//--------------------------------------------------------------------------------//

Window::Window(const char* a_szName, int a_iWidth /* = 640 */, int a_iHeight /* = 480 */,bool a_bWindowed /* = true */, bool a_bHasBorder /* = true */)
: m_oHwnd(0),
m_iWidth(a_iWidth),
m_iHeight(a_iHeight)
{
	DEVMODE dmScreenSettings;
	int posX, posY;

	// Get the instance of this application.
	m_hInstance = GetModuleHandle(0);

	// Setup the windows class with default settings.
	sm_oWindowclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	sm_oWindowclass.lpfnWndProc = WindowProc;
	sm_oWindowclass.cbClsExtra = 0;
	sm_oWindowclass.cbWndExtra = 0;
	sm_oWindowclass.hInstance = m_hInstance;
	sm_oWindowclass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	sm_oWindowclass.hIconSm = sm_oWindowclass.hIcon;
	sm_oWindowclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	sm_oWindowclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	sm_oWindowclass.lpszMenuName = NULL;
	sm_oWindowclass.lpszClassName = a_szName;
	sm_oWindowclass.cbSize = sizeof(WNDCLASSEX);

	// Register the window class.
	RegisterClassEx(&sm_oWindowclass);

	// Determine the resolution of the clients desktop screen.
	m_iWidth  = GetSystemMetrics(SM_CXSCREEN);
	m_iHeight = GetSystemMetrics(SM_CYSCREEN);

	// Setup the screen settings depending on whether it is running in full screen or in windowed mode.
	if(!a_bWindowed)
	{
		// If full screen set the screen to maximum size of the users desktop and 32bit.
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize       = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth  = (unsigned long)m_iWidth;
		dmScreenSettings.dmPelsHeight = (unsigned long)m_iHeight;
		dmScreenSettings.dmBitsPerPel = 32;			
		dmScreenSettings.dmFields     = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Change the display settings to full screen.
		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);

		// Set the position of the window to the top left corner.
		posX = posY = 0;
	}
	else
	{
		// If windowed then set it to 800x600 resolution.
		m_iHeight	= a_iHeight;
		m_iWidth	= a_iWidth;

		// Place the window in the middle of the screen.
		posX = (GetSystemMetrics(SM_CXSCREEN) - m_iWidth)  / 2;
		posY = (GetSystemMetrics(SM_CYSCREEN) - m_iHeight) / 2;
	}

	// Create the window with the screen settings and get the handle to it.
	m_oHwnd = CreateWindowEx(WS_EX_APPWINDOW, a_szName, a_szName, 
		a_bHasBorder ? WS_OVERLAPPEDWINDOW : WS_POPUP,
		posX, posY, m_iWidth, m_iHeight, NULL, NULL, m_hInstance, NULL);

	// Bring the window up on the screen and set it as main focus.
	ShowWindow(m_oHwnd, SW_SHOW);
	SetForegroundWindow(m_oHwnd);
	SetFocus(m_oHwnd);
}

//--------------------------------------------------------------------------------//

Window::~Window()
{
	if (m_oHwnd)
	{
		DestroyWindow(m_oHwnd);
		m_oHwnd = 0;
	}
}

//--------------------------------------------------------------------------------//

Window* Window::Create(const char* a_szName, int a_iWidth, int a_iHeight,bool a_bWindowed, bool a_bHasBorder)
{
	if(!m_pSingleton)
		m_pSingleton = new Window(a_szName,a_iWidth,a_iHeight,a_bWindowed,a_bHasBorder);
	return m_pSingleton;
}

//--------------------------------------------------------------------------------//

void Window::Release()
{
	if(m_pSingleton)
		delete m_pSingleton;
}

//--------------------------------------------------------------------------------//

bool Window::Tick()
{
	MSG	msg;

	while(PeekMessage(&msg, 0, 0, 0, PM_NOREMOVE))
	{
        if (msg.message == WM_QUIT)
            return false;

		if(GetMessage(&msg, 0, 0, 0))
		{
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
	}

	return true;
}

//--------------------------------------------------------------------------------//

void Window::AttachMouse(lcMouse *a_pMouse)
{
	if(a_pMouse)
		m_pMouse = a_pMouse;
}

//--------------------------------------------------------------------------------//

bool Window::IsActive()
{
	return (GetFocus() == m_oHwnd);
}

//--------------------------------------------------------------------------------//
 
Window* Window::Get()
{
	return m_pSingleton;
}

//--------------------------------------------------------------------------------//

bool Window::IsWindowed()
{
	return m_bWindowed;
}

//--------------------------------------------------------------------------------//

HWND Window::GetHandle()
{ 
	return m_oHwnd;
}

//--------------------------------------------------------------------------------//

int Window::GetWidth()
{ 
	return m_iWidth;
}
//--------------------------------------------------------------------------------//

int Window::GetHeight()
{
	return m_iHeight;
}

//--------------------------------------------------------------------------------//

LRESULT CALLBACK Window::WindowProc(HWND Handle, unsigned int msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		//++++++++++++++++++++++++++++++++++++++++//
		// Windows Messages
		//++++++++++++++++++++++++++++++++++++++++//
		case WM_SYSCOMMAND:
			{
				if (wParam == SC_CLOSE)
				{
					PostMessage(Handle,WM_DESTROY,0,0);
				}
				break;
			}

		case WM_DESTROY:
			{
				PostQuitMessage(0);
				break;
			}

		//++++++++++++++++++++++++++++++++++++++++//
		// Mosue Messages
		//++++++++++++++++++++++++++++++++++++++++//

		case WM_MOUSEWHEEL:
			{
				if(m_pMouse)
					m_pMouse->m_uiScrollVal = GET_WHEEL_DELTA_WPARAM(wParam);
				break;
			}	
	};

	return DefWindowProc(Handle,msg,wParam,lParam);
}

//--------------------------------------------------------------------------------//