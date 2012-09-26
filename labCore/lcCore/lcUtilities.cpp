//--------------------------------------------------------------------------------//
//
// \author		Nathan M. Chambers
// \date        26/03/2012
// \brief		Utility Code for Debugging
//
//--------------------------------------------------------------------------------//
#include "lcUtilities.h"

#include <Windows.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>

#include <fstream>
#include <iostream>
#include <string>

#include <D3Dcompiler.h>
#include "lcRenderer.h"

//--------------------------------------------------------------------------------//
// Write to Console
//--------------------------------------------------------------------------------//
void  Utilities::Debug_ConsoleWrite(const char* pFormat,...)
{
	char pString[256];

	va_list argList;
	va_start(argList,pFormat);
	vsprintf_s(pString,pFormat,argList);
	va_end(argList);

	printf_s(pString);
}

//--------------------------------------------------------------------------------//
// Write to Output Window
//--------------------------------------------------------------------------------//
void  Utilities::Debug_OutputWrite(const char* pFormat,...)
{
	char pString[512];

	va_list argList;
	va_start(argList,pFormat);
	vsprintf_s(pString,pFormat,argList);
	va_end(argList);

	OutputDebugString(pString);
}

//--------------------------------------------------------------------------------//
// Creates a Console Window
//--------------------------------------------------------------------------------//
void  Utilities::ConsoleShow(bool a_bShow)
{
	if (a_bShow)
	{
		AllocConsole();

		HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
		int hCrt = _open_osfhandle((long) handle_out, _O_TEXT);
		FILE* hf_out = _fdopen(hCrt, "w");
		setvbuf(hf_out, NULL, _IONBF, 1);
		*stdout = *hf_out;

		HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
		hCrt = _open_osfhandle((long) handle_in, _O_TEXT);
		FILE* hf_in = _fdopen(hCrt, "r");
		setvbuf(hf_in, NULL, _IONBF, 128);
		*stdin = *hf_in;

		SetConsoleTitle("Debug Console");

		//move the window to the upper left corner
		HWND hwnd = GetConsoleWindow();
		RECT rect;
		GetWindowRect(hwnd, &rect);
		MoveWindow(hwnd, 0, 0, rect.right - rect.left, rect.bottom - rect.top, TRUE);

		ConsoleClear();
	}
	else
	{
		FreeConsole();
	}
}

//--------------------------------------------------------------------------------//
// Clears the Text in the Console Window
//--------------------------------------------------------------------------------//
void Utilities::ConsoleClear()
{
	system("cls");
}

void Utilities::PreCompileShader(const char* a_pShaderFile,const char* a_pCompiledFile)
{

}