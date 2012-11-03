//--------------------------------------------------------------------------------//
//
// \author      Conan H. Bourke
// \date        13/01/2012
// \brief		Simple Win32 window wrapper.
//
//--------------------------------------------------------------------------------//
#include "lcWindow.h"
#include "lcMouse.h"
#include "AntTweakBar.h"
//--------------------------------------------------------------------------------//
Window* Window::m_pSingleton = 0;
//--------------------------------------------------------------------------------//

Window::Window(const char* a_szName, int a_iWidth /* = 640 */, int a_iHeight /* = 480 */,bool a_bWindowed /* = true */, bool a_bHasBorder /* = true */)
: m_oHwnd(0),
m_iWidth(a_iWidth),
m_iHeight(a_iHeight)
{
	DEVMODE dmScreenSettings;
	int posX, posY;

	if(!a_bWindowed)
		a_bHasBorder = false;

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

	RECT kRect = {0,0,a_iWidth,a_iHeight};
	int iBoarderWidth = 0;
	int iBoarderHeight = 0;

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
		m_iHeight	= a_iHeight;
		m_iWidth	= a_iWidth;

		if(a_bHasBorder)
		{
			AdjustWindowRect(&kRect,WS_OVERLAPPEDWINDOW,false);
			iBoarderWidth = abs(kRect.left) + kRect.right - m_iWidth;
			iBoarderHeight = abs(kRect.top) + kRect.bottom - m_iHeight;
		}

		// Place the window in the middle of the screen.
		posX = (GetSystemMetrics(SM_CXSCREEN) - m_iWidth)  / 2;
		posY = (GetSystemMetrics(SM_CYSCREEN) - m_iHeight) / 2;
	}

	// Create the window with the screen settings and get the handle to it.
	m_oHwnd = CreateWindowEx(WS_EX_APPWINDOW, a_szName, a_szName, 
		a_bHasBorder ? WS_OVERLAPPED | WS_CAPTION | WS_THICKFRAME | WS_SYSMENU : WS_POPUP,
		posX, posY, m_iWidth + iBoarderWidth, m_iHeight + iBoarderHeight, NULL, NULL, m_hInstance, NULL);

	// Bring the window up on the screen and set it as main focus.
	ShowWindow(m_oHwnd, SW_SHOW);
	SetForegroundWindow(m_oHwnd);
	SetFocus(m_oHwnd);

	OnDropFile = &Window::OnDropFileDef;
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

int Window::Width()
{ 
	if(m_pSingleton)
		return m_pSingleton->m_iWidth;
	return 0;
}
//--------------------------------------------------------------------------------//

int Window::Height()
{
	if(m_pSingleton)
		return m_pSingleton->m_iHeight;
	return 0;
}

//--------------------------------------------------------------------------------//

void Window::OnDropFileDef(const char* a_szFileName)
{
	UNREFERENCED_PARAMETER(a_szFileName);
}

void Window::EnableFileDrop(bool a_bEnable)
{
	DragAcceptFiles(m_oHwnd,a_bEnable);
}

lmVec2 Window::Position()
{
	lmVec2 kRetPos(0,0);

	if(m_pSingleton)
	{
		RECT kWndRect;
		GetWindowRect(m_pSingleton->m_oHwnd,&kWndRect);
		kRetPos.Set((float)kWndRect.left,(float)kWndRect.top);
	}
	return kRetPos;
}

//--------------------------------------------------------------------------------//

LRESULT CALLBACK Window::WindowProc(HWND Handle, unsigned int msg, WPARAM wParam, LPARAM lParam)
{
	TwEventWin(Handle,msg,wParam,lParam);

	switch (msg)
	{
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

		case WM_MOUSEWHEEL:
			{
				if(lcMouse::Get())
					lcMouse::Get()->m_uiScrollVal = GET_WHEEL_DELTA_WPARAM(wParam);
				break;
			}

		case WM_DROPFILES:
			{
				HDROP hDrop = (HDROP)wParam;
				int iFileCount = DragQueryFile(hDrop,0xFFFFFFFF, nullptr, MAX_PATH);
				for(int i = 0;i < iFileCount;++i)
				{
					char a_szFileDir[256];
					DragQueryFile(hDrop,i,a_szFileDir,MAX_PATH);
					m_pSingleton->OnDropFile(a_szFileDir);
				}
				DragFinish(hDrop);
				break;
			}

		default:
			return DefWindowProc(Handle,msg,wParam,lParam);
	};

	return 0;
}

//--------------------------------------------------------------------------------//