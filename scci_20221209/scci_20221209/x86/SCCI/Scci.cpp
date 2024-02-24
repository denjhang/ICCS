/*******************************************************************************
	Generated by: DLL to C version 3.74
	Date: 2023-12-11
	Description: The implementation code for scci.dll.
	Website: http://www.dll-decompiler.com
	Technical Support: support@dll-decompiler.com
*******************************************************************************/

#include "stdafx.h"
#include "Scci.h"


HMODULE g_hScci;
BOOL (WINAPI *Scci_DllEntryPoint)(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved);

extern UCHAR Scci_text[0x47000];
extern stScci_rdata Scci_rdata;
extern stScci_data Scci_data;
extern stScci_scciseg Scci_scciseg;

__declspec(align(16)) stScci Scci;

void* __stdcall Scci_RVA(DWORD rvaAddr)
{
	if(rvaAddr==0)
		return g_hScci;
	if(rvaAddr >= 0 && rvaAddr < 0x86000)
		return (UCHAR*)&Scci + rvaAddr;

	return NULL;
}

FARPROC __stdcall Scci_GetExport(LPCSTR lpExportName)
{
	if(lstrcmpA(lpExportName,"getSoundInterfaceManager")==0)
		return (FARPROC)Scci_VA(0x10015690);

	return NULL;
}

BOOL Scci_Init()
{
	HMODULE hDll;
	DWORD oldProtect;
	DWORD nCodeSize;
	void (*fInitData)(HMODULE,void*,void*);

	oldProtect = PAGE_EXECUTE_READWRITE;
	nCodeSize = Scci_text(Scci_CodeEnd) - Scci_text(Scci_CodeStart);
	VirtualProtect(Scci_text(Scci_CodeStart),nCodeSize,PAGE_EXECUTE_READWRITE,&oldProtect);

	memcpy(&Scci.Text,&Scci_text,sizeof(Scci_text));
	memcpy(&Scci.Rdata,&Scci_rdata,sizeof(Scci_rdata));
	memcpy(&Scci.Data,&Scci_data,sizeof(Scci_data));
	memcpy(&Scci.Scciseg,&Scci_scciseg,sizeof(Scci_scciseg));

	hDll = ::LoadLibraryA("KERNEL32.dll");
	if(!hDll)
	{
#ifdef _DEBUG
		MessageBoxA(NULL,
			"Please copy the dependent DLL \"KERNEL32.dll\" to the working directory.",
			"Load DLL Failed",MB_OK|MB_ICONERROR);
#endif
		ASSERT(0);
		return FALSE;
	}
	*((UCHAR*)&Scci_rdata+0x20) = (FARPROC)&CloseHandle;
	*((UCHAR*)&Scci_rdata+0x24) = (FARPROC)&OutputDebugStringA;
	*((UCHAR*)&Scci_rdata+0x28) = (FARPROC)&FreeLibrary;
	*((UCHAR*)&Scci_rdata+0x2C) = (FARPROC)&GetProcAddress;
	*((UCHAR*)&Scci_rdata+0x30) = (FARPROC)&LoadLibraryA;
	*((UCHAR*)&Scci_rdata+0x34) = (FARPROC)&GetPrivateProfileIntA;
	*((UCHAR*)&Scci_rdata+0x38) = (FARPROC)&GetPrivateProfileStringA;
	*((UCHAR*)&Scci_rdata+0x3C) = (FARPROC)&WritePrivateProfileStringA;
	*((UCHAR*)&Scci_rdata+0x40) = (FARPROC)&GetModuleFileNameA;
	*((UCHAR*)&Scci_rdata+0x44) = (FARPROC)&WaitForSingleObject;
	*((UCHAR*)&Scci_rdata+0x48) = (FARPROC)&SetEvent;
	*((UCHAR*)&Scci_rdata+0x4C) = (FARPROC)&CreateEventA;
	*((UCHAR*)&Scci_rdata+0x50) = (FARPROC)&SetThreadPriority;
	*((UCHAR*)&Scci_rdata+0x54) = (FARPROC)&GetExitCodeThread;
	*((UCHAR*)&Scci_rdata+0x58) = (FARPROC)&CreateThread;
	*((UCHAR*)&Scci_rdata+0x5C) = (FARPROC)&SetPriorityClass;
	*((UCHAR*)&Scci_rdata+0x60) = (FARPROC)&GetCurrentProcess;
	*((UCHAR*)&Scci_rdata+0x64) = (FARPROC)&lstrcmpA;
	*((UCHAR*)&Scci_rdata+0x68) = (FARPROC)&ClearCommError;
	*((UCHAR*)&Scci_rdata+0x6C) = (FARPROC)&GetCommState;
	*((UCHAR*)&Scci_rdata+0x70) = (FARPROC)&SetCommState;
	*((UCHAR*)&Scci_rdata+0x74) = (FARPROC)&SetCommTimeouts;
	*((UCHAR*)&Scci_rdata+0x78) = (FARPROC)&DeviceIoControl;
	*((UCHAR*)&Scci_rdata+0x7C) = (FARPROC)&GetCommTimeouts;
	*((UCHAR*)&Scci_rdata+0x80) = (FARPROC)&QueryDosDeviceA;
	*((UCHAR*)&Scci_rdata+0x84) = (FARPROC)&ExitThread;
	*((UCHAR*)&Scci_rdata+0x88) = (FARPROC)&CreateFileW;
	*((UCHAR*)&Scci_rdata+0x8C) = (FARPROC)&WriteConsoleW;
	*((UCHAR*)&Scci_rdata+0x90) = (FARPROC)&SetStdHandle;
	*((UCHAR*)&Scci_rdata+0x94) = (FARPROC)&LoadLibraryW;
	*((UCHAR*)&Scci_rdata+0x98) = (FARPROC)&OutputDebugStringW;
	*((UCHAR*)&Scci_rdata+0x9C) = (FARPROC)&LoadLibraryExW;
	*((UCHAR*)&Scci_rdata+0xA0) = (FARPROC)&FreeEnvironmentStringsW;
	*((UCHAR*)&Scci_rdata+0xA4) = (FARPROC)&GetEnvironmentStringsW;
	*((UCHAR*)&Scci_rdata+0xA8) = (FARPROC)&GetSystemTimeAsFileTime;
	*((UCHAR*)&Scci_rdata+0xAC) = (FARPROC)&GetCurrentProcessId;
	*((UCHAR*)&Scci_rdata+0xB0) = (FARPROC)&QueryPerformanceCounter;
	*((UCHAR*)&Scci_rdata+0xB4) = (FARPROC)&GetFileType;
	*((UCHAR*)&Scci_rdata+0xB8) = (FARPROC)&SetFilePointerEx;
	*((UCHAR*)&Scci_rdata+0xBC) = (FARPROC)&GetConsoleMode;
	*((UCHAR*)&Scci_rdata+0xC0) = (FARPROC)&GetModuleHandleA;
	*((UCHAR*)&Scci_rdata+0xC4) = (FARPROC)&FlushFileBuffers;
	*((UCHAR*)&Scci_rdata+0xC8) = (FARPROC)&GetOEMCP;
	*((UCHAR*)&Scci_rdata+0xCC) = (FARPROC)&GetACP;
	*((UCHAR*)&Scci_rdata+0xD0) = (FARPROC)&IsValidCodePage;
	*((UCHAR*)&Scci_rdata+0xD4) = (FARPROC)&GetProcessHeap;
	*((UCHAR*)&Scci_rdata+0xD8) = (FARPROC)&GetModuleFileNameW;
	*((UCHAR*)&Scci_rdata+0xDC) = (FARPROC)&GetStdHandle;
	*((UCHAR*)&Scci_rdata+0xE0) = (FARPROC)&HeapSize;
	*((UCHAR*)&Scci_rdata+0xE4) = (FARPROC)&GetModuleHandleExW;
	*((UCHAR*)&Scci_rdata+0xE8) = (FARPROC)&ExitProcess;
	*((UCHAR*)&Scci_rdata+0xEC) = (FARPROC)&EnumSystemLocalesW;
	*((UCHAR*)&Scci_rdata+0xF0) = (FARPROC)&GetUserDefaultLCID;
	*((UCHAR*)&Scci_rdata+0xF4) = (FARPROC)&IsValidLocale;
	*((UCHAR*)&Scci_rdata+0xF8) = (FARPROC)&GetLocaleInfoW;
	*((UCHAR*)&Scci_rdata+0xFC) = (FARPROC)&LCMapStringW;
	*((UCHAR*)&Scci_rdata+0x100) = (FARPROC)&CompareStringW;
	*((UCHAR*)&Scci_rdata+0x104) = (FARPROC)&GetModuleHandleW;
	*((UCHAR*)&Scci_rdata+0x108) = (FARPROC)&GetStartupInfoW;
	*((UCHAR*)&Scci_rdata+0x10C) = (FARPROC)&TlsFree;
	*((UCHAR*)&Scci_rdata+0x110) = (FARPROC)&TlsSetValue;
	*((UCHAR*)&Scci_rdata+0x114) = (FARPROC)&TlsGetValue;
	*((UCHAR*)&Scci_rdata+0x118) = (FARPROC)&TlsAlloc;
	*((UCHAR*)&Scci_rdata+0x11C) = (FARPROC)&TerminateProcess;
	*((UCHAR*)&Scci_rdata+0x120) = (FARPROC)&SetLastError;
	*((UCHAR*)&Scci_rdata+0x124) = (FARPROC)&SetUnhandledExceptionFilter;
	*((UCHAR*)&Scci_rdata+0x128) = (FARPROC)&UnhandledExceptionFilter;
	*((UCHAR*)&Scci_rdata+0x12C) = (FARPROC)&GetCPInfo;
	*((UCHAR*)&Scci_rdata+0x130) = (FARPROC)&InitializeCriticalSectionAndSpinCount;
	*(FARPROC*)((UCHAR*)&Scci.Rdata+0x134) = ::GetProcAddress(hDll,"RtlUnwind");
	if(!*((UCHAR*)&Scci_rdata+0x134))
		return FALSE;
	*((UCHAR*)&Scci_rdata+0x138) = (FARPROC)&RaiseException;
	*((UCHAR*)&Scci_rdata+0x13C) = (FARPROC)&GetCurrentThreadId;
	*((UCHAR*)&Scci_rdata+0x140) = (FARPROC)&HeapReAlloc;
	*((UCHAR*)&Scci_rdata+0x144) = (FARPROC)&IsProcessorFeaturePresent;
	*((UCHAR*)&Scci_rdata+0x148) = (FARPROC)&IsDebuggerPresent;
	*((UCHAR*)&Scci_rdata+0x14C) = (FARPROC)&HeapAlloc;
	*((UCHAR*)&Scci_rdata+0x150) = (FARPROC)&HeapFree;
	*((UCHAR*)&Scci_rdata+0x154) = (FARPROC)&ReadFile;
	*((UCHAR*)&Scci_rdata+0x158) = (FARPROC)&GetCommandLineA;
	*((UCHAR*)&Scci_rdata+0x15C) = (FARPROC)&WriteFile;
	*((UCHAR*)&Scci_rdata+0x160) = (FARPROC)&CreateFileA;
	*((UCHAR*)&Scci_rdata+0x164) = (FARPROC)&DeleteCriticalSection;
	*((UCHAR*)&Scci_rdata+0x168) = (FARPROC)&InitializeCriticalSection;
	*((UCHAR*)&Scci_rdata+0x16C) = (FARPROC)&lstrlenA;
	*((UCHAR*)&Scci_rdata+0x170) = (FARPROC)&Sleep;
	*((UCHAR*)&Scci_rdata+0x174) = (FARPROC)&FindResourceA;
	*((UCHAR*)&Scci_rdata+0x178) = (FARPROC)&EnterCriticalSection;
	*((UCHAR*)&Scci_rdata+0x17C) = (FARPROC)&LeaveCriticalSection;
	*((UCHAR*)&Scci_rdata+0x180) = (FARPROC)&LockResource;
	*((UCHAR*)&Scci_rdata+0x184) = (FARPROC)&LoadResource;
	*((UCHAR*)&Scci_rdata+0x188) = (FARPROC)&GetLastError;
	*((UCHAR*)&Scci_rdata+0x18C) = (FARPROC)&GetStringTypeW;
	*((UCHAR*)&Scci_rdata+0x190) = (FARPROC)&MultiByteToWideChar;
	*((UCHAR*)&Scci_rdata+0x194) = (FARPROC)&WideCharToMultiByte;
	*((UCHAR*)&Scci_rdata+0x198) = (FARPROC)&lstrcpyA;
	*((UCHAR*)&Scci_rdata+0x19C) = (FARPROC)&GetConsoleCP;
	*((UCHAR*)&Scci_rdata+0x1A0) = (FARPROC)&DecodePointer;
	*((UCHAR*)&Scci_rdata+0x1A4) = (FARPROC)&EncodePointer;
	*((UCHAR*)&Scci_rdata+0x1A8) = (FARPROC)&InterlockedDecrement;
	*((UCHAR*)&Scci_rdata+0x1AC) = (FARPROC)&InterlockedIncrement;

	hDll = ::LoadLibraryA("USER32.dll");
	if(!hDll)
	{
#ifdef _DEBUG
		MessageBoxA(NULL,
			"Please copy the dependent DLL \"USER32.dll\" to the working directory.",
			"Load DLL Failed",MB_OK|MB_ICONERROR);
#endif
		ASSERT(0);
		return FALSE;
	}
	*((UCHAR*)&Scci_rdata+0x1D8) = (FARPROC)&BeginPaint;
	*((UCHAR*)&Scci_rdata+0x1DC) = (FARPROC)&GetCursorPos;
	*((UCHAR*)&Scci_rdata+0x1E0) = (FARPROC)&ShowWindow;
	*((UCHAR*)&Scci_rdata+0x1E4) = (FARPROC)&GetSystemMetrics;
	*((UCHAR*)&Scci_rdata+0x1E8) = (FARPROC)&IsWindowVisible;
	*((UCHAR*)&Scci_rdata+0x1EC) = (FARPROC)&UpdateWindow;
	*((UCHAR*)&Scci_rdata+0x1F0) = (FARPROC)&MoveWindow;
	*((UCHAR*)&Scci_rdata+0x1F4) = (FARPROC)&InvalidateRect;
	*((UCHAR*)&Scci_rdata+0x1F8) = (FARPROC)&KillTimer;
	*((UCHAR*)&Scci_rdata+0x1FC) = (FARPROC)&PostQuitMessage;
	*((UCHAR*)&Scci_rdata+0x200) = (FARPROC)&GetWindowRect;
	*((UCHAR*)&Scci_rdata+0x204) = (FARPROC)&ScreenToClient;
	*((UCHAR*)&Scci_rdata+0x208) = (FARPROC)&SetTimer;
	*((UCHAR*)&Scci_rdata+0x20C) = (FARPROC)&DestroyWindow;
	*((UCHAR*)&Scci_rdata+0x210) = (FARPROC)&EndPaint;
	*((UCHAR*)&Scci_rdata+0x214) = (FARPROC)&LoadIconA;
	*((UCHAR*)&Scci_rdata+0x218) = (FARPROC)&DefWindowProcA;
	*((UCHAR*)&Scci_rdata+0x21C) = (FARPROC)&MessageBoxA;
	*((UCHAR*)&Scci_rdata+0x220) = (FARPROC)&SetWindowTextA;
	*((UCHAR*)&Scci_rdata+0x224) = (FARPROC)&wsprintfA;
	*((UCHAR*)&Scci_rdata+0x228) = (FARPROC)&wvsprintfA;
	*((UCHAR*)&Scci_rdata+0x22C) = (FARPROC)&GetDC;
	*((UCHAR*)&Scci_rdata+0x230) = (FARPROC)&ReleaseDC;
	*((UCHAR*)&Scci_rdata+0x234) = (FARPROC)&SendMessageA;
	*((UCHAR*)&Scci_rdata+0x238) = (FARPROC)&UnregisterClassA;
	*((UCHAR*)&Scci_rdata+0x23C) = (FARPROC)&PeekMessageA;
	*((UCHAR*)&Scci_rdata+0x240) = (FARPROC)&SetWindowPos;
	*((UCHAR*)&Scci_rdata+0x244) = (FARPROC)&GetMessageA;
	*((UCHAR*)&Scci_rdata+0x248) = (FARPROC)&TrackPopupMenu;
	*((UCHAR*)&Scci_rdata+0x24C) = (FARPROC)&GetSubMenu;
	*((UCHAR*)&Scci_rdata+0x250) = (FARPROC)&LoadMenuA;
	*((UCHAR*)&Scci_rdata+0x254) = (FARPROC)&IsDialogMessageA;
	*((UCHAR*)&Scci_rdata+0x258) = (FARPROC)&TranslateMessage;
	*((UCHAR*)&Scci_rdata+0x25C) = (FARPROC)&EnableMenuItem;
	*((UCHAR*)&Scci_rdata+0x260) = (FARPROC)&PostMessageA;
	*((UCHAR*)&Scci_rdata+0x264) = (FARPROC)&DispatchMessageA;
	*((UCHAR*)&Scci_rdata+0x268) = (FARPROC)&DestroyMenu;
	*((UCHAR*)&Scci_rdata+0x26C) = (FARPROC)&LoadCursorA;
	*((UCHAR*)&Scci_rdata+0x270) = (FARPROC)&CheckMenuItem;
	*((UCHAR*)&Scci_rdata+0x274) = (FARPROC)&RegisterClassA;
	*((UCHAR*)&Scci_rdata+0x278) = (FARPROC)&GetDlgItem;
	*((UCHAR*)&Scci_rdata+0x27C) = (FARPROC)&EnableWindow;
	*((UCHAR*)&Scci_rdata+0x280) = (FARPROC)&GetDlgItemInt;
	*((UCHAR*)&Scci_rdata+0x284) = (FARPROC)&SetDlgItemInt;
	*((UCHAR*)&Scci_rdata+0x288) = (FARPROC)&DialogBoxParamA;
	*((UCHAR*)&Scci_rdata+0x28C) = (FARPROC)&GetDlgItemTextA;
	*((UCHAR*)&Scci_rdata+0x290) = (FARPROC)&SetDlgItemTextA;
	*((UCHAR*)&Scci_rdata+0x294) = (FARPROC)&SendDlgItemMessageA;
	*((UCHAR*)&Scci_rdata+0x298) = (FARPROC)&EndDialog;
	*((UCHAR*)&Scci_rdata+0x29C) = (FARPROC)&SetForegroundWindow;
	*((UCHAR*)&Scci_rdata+0x2A0) = (FARPROC)&SetWindowLongA;
	*((UCHAR*)&Scci_rdata+0x2A4) = (FARPROC)&GetWindowLongA;
	*((UCHAR*)&Scci_rdata+0x2A8) = (FARPROC)&CreateWindowExA;

	hDll = ::LoadLibraryA("GDI32.dll");
	if(!hDll)
	{
#ifdef _DEBUG
		MessageBoxA(NULL,
			"Please copy the dependent DLL \"GDI32.dll\" to the working directory.",
			"Load DLL Failed",MB_OK|MB_ICONERROR);
#endif
		ASSERT(0);
		return FALSE;
	}
	*((UCHAR*)&Scci_rdata+0x8) = (FARPROC)&BitBlt;
	*((UCHAR*)&Scci_rdata+0xC) = (FARPROC)&CreateDIBSection;
	*((UCHAR*)&Scci_rdata+0x10) = (FARPROC)&DeleteObject;
	*((UCHAR*)&Scci_rdata+0x14) = (FARPROC)&SelectObject;
	*((UCHAR*)&Scci_rdata+0x18) = (FARPROC)&CreateCompatibleDC;

	hDll = ::LoadLibraryA("SHELL32.dll");
	if(!hDll)
	{
#ifdef _DEBUG
		MessageBoxA(NULL,
			"Please copy the dependent DLL \"SHELL32.dll\" to the working directory.",
			"Load DLL Failed",MB_OK|MB_ICONERROR);
#endif
		ASSERT(0);
		return FALSE;
	}
	*((UCHAR*)&Scci_rdata+0x1C8) = (FARPROC)&Shell_NotifyIconA;

	hDll = ::LoadLibraryA("COMCTL32.dll");
	if(!hDll)
	{
#ifdef _DEBUG
		MessageBoxA(NULL,
			"Please copy the dependent DLL \"COMCTL32.dll\" to the working directory.",
			"Load DLL Failed",MB_OK|MB_ICONERROR);
#endif
		ASSERT(0);
		return FALSE;
	}
	*(FARPROC*)((UCHAR*)&Scci.Rdata+0x0) = ::GetProcAddress(hDll,(LPCSTR)0x11);
	if(!*((UCHAR*)&Scci_rdata+0x0))
		return FALSE;

	hDll = ::LoadLibraryA("WINMM.dll");
	if(!hDll)
	{
#ifdef _DEBUG
		MessageBoxA(NULL,
			"Please copy the dependent DLL \"WINMM.dll\" to the working directory.",
			"Load DLL Failed",MB_OK|MB_ICONERROR);
#endif
		ASSERT(0);
		return FALSE;
	}
	*((UCHAR*)&Scci_rdata+0x2B0) = (FARPROC)&timeGetTime;
	*((UCHAR*)&Scci_rdata+0x2B4) = (FARPROC)&timeSetEvent;
	*((UCHAR*)&Scci_rdata+0x2B8) = (FARPROC)&timeKillEvent;
	*((UCHAR*)&Scci_rdata+0x2BC) = (FARPROC)&timeBeginPeriod;
	*((UCHAR*)&Scci_rdata+0x2C0) = (FARPROC)&midiOutPrepareHeader;
	*((UCHAR*)&Scci_rdata+0x2C4) = (FARPROC)&midiOutOpen;
	*((UCHAR*)&Scci_rdata+0x2C8) = (FARPROC)&midiOutClose;
	*((UCHAR*)&Scci_rdata+0x2CC) = (FARPROC)&midiOutLongMsg;
	*((UCHAR*)&Scci_rdata+0x2D0) = (FARPROC)&waveOutPrepareHeader;
	*((UCHAR*)&Scci_rdata+0x2D4) = (FARPROC)&waveOutOpen;
	*((UCHAR*)&Scci_rdata+0x2D8) = (FARPROC)&waveOutUnprepareHeader;
	*((UCHAR*)&Scci_rdata+0x2DC) = (FARPROC)&waveOutReset;
	*((UCHAR*)&Scci_rdata+0x2E0) = (FARPROC)&waveOutWrite;
	*((UCHAR*)&Scci_rdata+0x2E4) = (FARPROC)&midiOutGetNumDevs;
	*((UCHAR*)&Scci_rdata+0x2E8) = (FARPROC)&midiOutGetDevCapsA;
	*((UCHAR*)&Scci_rdata+0x2EC) = (FARPROC)&waveOutClose;
	*((UCHAR*)&Scci_rdata+0x2F0) = (FARPROC)&midiOutUnprepareHeader;

	hDll = ::LoadLibraryA("SETUPAPI.dll");
	if(!hDll)
	{
#ifdef _DEBUG
		MessageBoxA(NULL,
			"Please copy the dependent DLL \"SETUPAPI.dll\" to the working directory.",
			"Load DLL Failed",MB_OK|MB_ICONERROR);
#endif
		ASSERT(0);
		return FALSE;
	}
	*((UCHAR*)&Scci_rdata+0x1B4) = (FARPROC)&SetupDiDestroyDeviceInfoList;
	*((UCHAR*)&Scci_rdata+0x1B8) = (FARPROC)&SetupDiGetDeviceInterfaceDetailA;
	*((UCHAR*)&Scci_rdata+0x1BC) = (FARPROC)&SetupDiEnumDeviceInterfaces;
	*((UCHAR*)&Scci_rdata+0x1C0) = (FARPROC)&SetupDiGetClassDevsA;

	hDll = ::LoadLibraryA("WINUSB.DLL");
	if(!hDll)
	{
#ifdef _DEBUG
		MessageBoxA(NULL,
			"Please copy the dependent DLL \"WINUSB.DLL\" to the working directory.",
			"Load DLL Failed",MB_OK|MB_ICONERROR);
#endif
		ASSERT(0);
		return FALSE;
	}
	*((UCHAR*)&Scci_rdata+0x2F8) = (FARPROC)&WinUsb_QueryInterfaceSettings;
	*((UCHAR*)&Scci_rdata+0x2FC) = (FARPROC)&WinUsb_Initialize;
	*((UCHAR*)&Scci_rdata+0x300) = (FARPROC)&WinUsb_SetPipePolicy;
	*((UCHAR*)&Scci_rdata+0x304) = (FARPROC)&WinUsb_ControlTransfer;
	*((UCHAR*)&Scci_rdata+0x308) = (FARPROC)&WinUsb_FlushPipe;
	*((UCHAR*)&Scci_rdata+0x30C) = (FARPROC)&WinUsb_WritePipe;
	*((UCHAR*)&Scci_rdata+0x310) = (FARPROC)&WinUsb_Free;
	*((UCHAR*)&Scci_rdata+0x314) = (FARPROC)&WinUsb_QueryPipe;

	hDll = ::LoadLibraryA("SHLWAPI.dll");
	if(!hDll)
	{
#ifdef _DEBUG
		MessageBoxA(NULL,
			"Please copy the dependent DLL \"SHLWAPI.dll\" to the working directory.",
			"Load DLL Failed",MB_OK|MB_ICONERROR);
#endif
		ASSERT(0);
		return FALSE;
	}
	*((UCHAR*)&Scci_rdata+0x1D0) = (FARPROC)&PathFileExistsA;

	VirtualProtect(&Scci_InitData, sizeof(Scci_InitData), PAGE_EXECUTE_READWRITE, &oldProtect);

	*(FARPROC*)&fInitData = (FARPROC)&Scci_InitData[0];
	fInitData(g_hScci,Scci_RVA,Scci_GetExport);

	*(FARPROC*)&Scci_DllEntryPoint = (FARPROC)Scci_VA(0x10035818);
	return TRUE;
}

BOOL Scci_LoadLibrary()
{
	return Scci_DllEntryPoint(g_hScci, DLL_PROCESS_ATTACH, 0);
}

BOOL Scci_FreeLibrary()
{
	return Scci_DllEntryPoint(g_hScci, DLL_PROCESS_DETACH, 0);
}

extern "C" __declspec(naked) void getSoundInterfaceManager(){__asm push offset Scci + 0x15690 __asm ret}

