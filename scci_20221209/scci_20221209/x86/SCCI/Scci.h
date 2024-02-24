/*******************************************************************************
	Generated by: DLL to C version 3.74
	Date: 2023-12-11
	Description: The declaration of functions and variables for scci.dll.
	Website: http://www.dll-decompiler.com
	Technical Support: support@dll-decompiler.com
*******************************************************************************/

#if !defined(_SCCI_SUPP_H_00086000_INCLUDED_)
#define _SCCI_SUPP_H_00086000_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <windows.h>

#pragma pack(push)
#pragma pack(1)

#include "Scci_rdata.h"
#include "Scci_data.h"
#include "Scci_scciseg.h"

__declspec(align(16)) struct stScci
{
	UCHAR Header[0x1000];
	UCHAR Text[0x47000];
	stScci_rdata Rdata;
	stScci_data Data;
	stScci_scciseg Scciseg;
	UCHAR Rsrc[0x1C000];
	UCHAR Reloc[0xC000];
};

#pragma pack(pop)

__declspec(align(16)) extern stScci Scci;

/* Export Symbols in the .text section */
enum{
	Scci_CodeEnd = 0,
};

/* .text section, RVA range: 0x1000 - 0x48000 */
UCHAR* __stdcall Scci_text(INT iSymbol);

/* Data for initialization. */
extern UCHAR Scci_InitData[0x0];

extern HMODULE g_hScci;

/* Description: Initialize the DLL. */
BOOL Scci_Init();

/* Description: Load the DLL. */
BOOL Scci_LoadLibrary();

/* Description: Free the DLL. */
BOOL Scci_FreeLibrary();

/*
	Description: Access any address in the DLL.
	Parameters:
		rvaAddr: The RVA address you want to access.
*/
void* __stdcall Scci_RVA(DWORD rvaAddr);

#define Scci_VA(vaAddr) Scci_RVA((vaAddr) - 0x10000000)


#endif // !defined(_SCCI_SUPP_H_00086000_INCLUDED_)