//--------------------------------------------------------------------------------//
//
// \author		Nathan M. Chambers
// \date        26/03/2012
// \brief		Utility Code for Debugging
//
//--------------------------------------------------------------------------------//
#ifndef __UTILITIES_H_
#define __UTILITIES_H_
//--------------------------------------------------------------------------------//

#include <stdio.h>
#include <assert.h>

namespace Utilities
{
	//Create Console
	void ConsoleShow(bool a_bShow);
	void ConsoleClear();

	//Write to Console / Output Window
	void Debug_ConsoleWrite(const char* pFormat,...);
	void Debug_OutputWrite(const char* pFormat,...);

	void PreCompileShader(const char* ShaderFile,const char* CompiledFile);
}
//--------------------------------------------------------------------------------//
#endif//__UTILITIES_H_
//--------------------------------------------------------------------------------//