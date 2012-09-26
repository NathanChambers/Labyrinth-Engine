#include <Windows.h>
#include "Application.h"

Application* g_pkApp;

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int iShowCmd)
{
	g_pkApp = new Application();

	g_pkApp->Create(lpCmdLine);

	g_pkApp->Execute();

	g_pkApp->Destroy();

	return 0;
}