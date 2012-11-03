#include "lcAssert.h"

#include <Windows.h>
#include <stdio.h>
#include <stdio.h>
#include <stdarg.h>
#include <string>

void lcMessageBox(const char* a_szMessage)
{
	MessageBox(nullptr,a_szMessage,"Labyrinth Message",MB_ICONINFORMATION | MB_OK);
}

void lcMessageBox(const char* a_szException,const char* a_szFile,int a_iLine)
{
	char pString[256];

	char szFile[256];
	sprintf_s(szFile,"%s : Line %d \n",a_szFile,a_iLine);

	char szException[256];
	sprintf_s(szException,"\nException : %s",a_szException);

	sprintf_s(pString,"%s %s",szFile,szException);

	int iResult = MessageBox(nullptr,pString,"Labyrinth Assert Error",MB_ICONERROR | MB_ABORTRETRYIGNORE);

	switch(iResult)
	{
	case IDABORT:
		{
			char szDebugString[256];
			sprintf_s(szDebugString," \nProgram Exited At - %sException : %s \n\n",szFile,a_szException);
			OutputDebugString(szDebugString);
			exit(1);
			break;
		}

	default:
		{
			printf(szException);
			char szDebugString[256];
			sprintf_s(szDebugString," \nAssert Ignored - %s \n",a_szException);
			OutputDebugString(szDebugString);
		}
	}
}