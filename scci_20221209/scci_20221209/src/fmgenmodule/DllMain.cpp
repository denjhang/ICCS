#include	<windows.h>
#include	"manager.h"
// ���C�u�����̃C���|�[�g
#pragma comment(lib,"winmm.lib")

// data segment
#pragma data_seg (".fmgemmoduleseg")
	DWORD						g_dAttachCount = 0;
	Manager						*g_pManager = NULL;
	HINSTANCE					g_hDll = NULL;
#pragma data_seg()

//--------------------------------------------------
// dll main
//--------------------------------------------------
BOOL WINAPI DllMain
( HINSTANCE hinstDLL, DWORD dwDllMainEvent ,LPVOID lpvReserved )
{
    switch( dwDllMainEvent )
    {    case DLL_PROCESS_ATTACH:
			// create Sound Interface Manager instance
			g_dAttachCount++;
			g_hDll = hinstDLL; 
			break;
         case DLL_PROCESS_DETACH:
			 // decrement attach count
			 g_dAttachCount--;
			break;
         case DLL_THREAD_ATTACH:
			 break;
         case DLL_THREAD_DETACH:
			 break;
     }
     return TRUE;
}

//--------------------------------------------------
// get sound manager function
//--------------------------------------------------
extern "C" __declspec(dllexport) void Initialize(){
	// �����ŁA�e�������W���[���𐶐�
	g_pManager = new Manager(g_hDll);
	if(g_pManager){
		g_pManager->Initialize();
	}
}

extern "C" __declspec(dllexport) void UnInitialize(){
	// �����ŁA�e�������W���[����j��
	if(g_pManager){
		g_pManager->UnInitialize();
		delete g_pManager;
		g_pManager = NULL;
	}
}

// ���Z�b�g
extern "C" __declspec(dllexport) void Reset(){
	if(g_pManager){
		g_pManager->Reset();
	}
}

// ���ԍX�V
extern "C" __declspec(dllexport) void UpdateTime(){
	if(g_pManager){
		g_pManager->UpdateTime();
	}
}

// ���W�X�^�ݒ�
extern "C" __declspec(dllexport) void SetRegister(DWORD dModuleNum,DWORD dReg,DWORD dData){
	if(g_pManager){
		g_pManager->SetRegister(dModuleNum,dReg,dData);
	}
}

// PCM����
extern "C" __declspec(dllexport) void SoundMixing(void *pBuff,int size){
	if(g_pManager){
		g_pManager->SoundMixing((FM::Sample*)pBuff,size);
	}
}

