#include "manager.h"
// コンストラクタ
Manager::Manager(HINSTANCE hDll){
	m_hDll = hDll;
	m_pOPNA1 = NULL;
	m_pOPNA2 = NULL;
	m_pOPM1 = NULL;
	m_pOPM2 = NULL;
	m_dBeforeTick = 0;
}

// デストラクタ
Manager::~Manager(){
}

// 初期化
void Manager::Initialize(){
	char cFilePath[MAX_PATH];
	// ここでモジュールのパスを取得して保持する
	GetModuleFileName((HMODULE)m_hDll,cFilePath,MAX_PATH);
	int iPos = strlen(cFilePath) - 1;
	while(cFilePath[iPos] != '\\') iPos--;
	cFilePath[++iPos] = 0x00;

	// OPNA1初期化
	m_pOPNA1 = new FM::OPNA();
	m_pOPNA1->Init(7987200,8000,false,cFilePath);
	m_pOPNA1->Reset();
	m_pOPNA1->SetRate(7987200,50000,false);

	// OPNA2初期化
	m_pOPNA2 = new FM::OPNA();
	m_pOPNA2->Init(7987200,8000,false,cFilePath);
	m_pOPNA2->Reset();
	m_pOPNA2->SetRate(7987200,50000,false);

	// OPM1初期化
	m_pOPM1 = new FM::OPM();
	m_pOPM1->Init(4000000,8000);
	m_pOPM1->Reset();
	m_pOPM1->SetRate(4000000,50000,false);

	// OPM2初期化
	m_pOPM2 = new FM::OPM();
	m_pOPM2->Init(3579545,8000);
	m_pOPM2->Reset();
	m_pOPM2->SetRate(3579545,50000,false);

	m_dBeforeTick = timeGetTime();		// 現在時刻を取得
}

// 開放
void Manager::UnInitialize(){
	// OPNA1開放
	if(m_pOPNA1){
		m_pOPNA1->Reset();
		delete m_pOPNA1;
		m_pOPNA1 = NULL;
	}

	// OPNA2開放
	if(m_pOPNA2){
		m_pOPNA2->Reset();
		delete m_pOPNA2;
		m_pOPNA2 = NULL;
	}

	// OPM1開放
	if(m_pOPM1){
		m_pOPM1->Reset();
		delete m_pOPM1;
		m_pOPM1 = NULL;
	}

	// OPM2開放
	if(m_pOPM2){
		m_pOPM2->Reset();
		delete m_pOPM2;
		m_pOPM2 = NULL;
	}
}

// リセット
void Manager::Reset(){
	// OPNA1リセット
	if(m_pOPNA1){
		m_pOPNA1->Reset();
	}

	// OPNA2リセット
	if(m_pOPNA2){
		m_pOPNA2->Reset();
	}

	// OPM1リセット
	if(m_pOPM1){
		m_pOPM1->Reset();
	}

	// OPM2リセット
	if(m_pOPM2){
		m_pOPM2->Reset();
	}
}

// 時間更新
void Manager::UpdateTime(){
	DWORD dNowTick = timeGetTime();
	DWORD dTick = (dNowTick - m_dBeforeTick) * 1000;
	m_dBeforeTick = dNowTick;
	// 各音源に経過時間を設定する
	if(m_pOPNA1){
		m_pOPNA1->Count(dTick);
	}

	// OPNA2リセット
	if(m_pOPNA2){
		m_pOPNA2->Count(dTick);
	}

	// OPM1リセット
	if(m_pOPM1){
		m_pOPM1->Count(dTick);
	}

	// OPM2リセット
	if(m_pOPM2){
		m_pOPM2->Count(dTick);
	}
}

// レジスタ設定
void Manager::SetRegister(DWORD dModuleNum,DWORD dReg,DWORD dData){
	switch(dModuleNum){
		case	0:
			if(m_pOPNA1) m_pOPNA1->SetReg(dReg,dData);
			break;
		case	1:
			if(m_pOPNA2) m_pOPNA2->SetReg(dReg,dData);
			break;
		case	2:
			if(m_pOPM1) m_pOPM1->SetReg(dReg,dData);
			break;
		case	3:
			if(m_pOPM2) m_pOPM2->SetReg(dReg,dData);
			break;
	}
}

// PCM合成
void Manager::SoundMixing(FM::Sample *pBuff,int size){
	if(m_pOPNA1){
		m_pOPNA1->Mix(pBuff,size);
	}
	if(m_pOPNA2){
		m_pOPNA2->Mix(pBuff,size);
	}
	if(m_pOPM1){
		m_pOPM1->Mix(pBuff,size);
	}
	if(m_pOPM2){
		m_pOPM2->Mix(pBuff,size);
	}
}

