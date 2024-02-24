#pragma once
#include <Windows.h>

#include "fmgen\fmgen.h"
#include "fmgen\opna.h"
#include "fmgen\opm.h"

class Manager
{
private:
	FM::OPNA *m_pOPNA1;
	FM::OPNA *m_pOPNA2;
	FM::OPM *m_pOPM1;
	FM::OPM *m_pOPM2;
	DWORD m_dBeforeTick;
	HINSTANCE m_hDll;
public:
	// コンストラクタ
	Manager(HINSTANCE hDll);
	// デストラクタ
	~Manager();
	// 初期化
	void Initialize();
	// 開放
	void UnInitialize();
	// リセット
	void Reset();
	// 時間更新
	void UpdateTime();
	// レジスタ設定
	void SetRegister(DWORD dModuleNum,DWORD dReg,DWORD dData);
	// PCM合成
	void SoundMixing(FM::Sample *pBuff,int size);
};
