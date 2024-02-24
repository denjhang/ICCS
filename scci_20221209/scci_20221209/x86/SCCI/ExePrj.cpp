// ExePrj.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Scci.h"

int _tmain(int argc, _TCHAR* argv[])
{
	/* Invoke the generated code, just like invoke the DLL. */
	Scci_Init();
	Scci_LoadLibrary();

	/* 
		Here you can call Scci_GetProcAddress to get the addresses of exported functions. 

		Example:
		void (*fTestFun)(LPCSTR);
		*(FARPROC*)&fTestFun = Win32Dll_GetProcAddress("TestFun");
		fTestFun("Hello World!");
	*/

	Scci_FreeLibrary();

	return 0;
}