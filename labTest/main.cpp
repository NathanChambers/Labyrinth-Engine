#include <Windows.h>
#include "Application.h"
#include "lcMemTracker.h"

Application* g_pkApp;
int main()
{
	g_pkApp = new Application();

	g_pkApp->Create();

	g_pkApp->Execute();

	g_pkApp->Destroy();

	return 0;
}