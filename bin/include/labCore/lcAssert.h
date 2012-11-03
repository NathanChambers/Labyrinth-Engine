#ifndef __LCASSERT_H_
#define __LCASSERT_H_

#include <Windows.h>

void lcMessageBox(const char* a_szMessage);
void lcMessageBox(const char* a_szException,const char* a_szFile,int a_iLine);

#define lcAssert(Exception) lcMessageBox(Exception,__FILE__,__LINE__);

#endif//__LCASSERT_H_