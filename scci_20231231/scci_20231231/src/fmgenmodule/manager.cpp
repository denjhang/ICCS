#include "manager.h"
// �R���X�g���N�^
Manager::Manager(HINSTANCE hDll){
	m_hDll = hDll;
	m_pOPNA1 = NULL;
	m_pOPNA2 = NULL;
	m_pOPM1 = NULL;
	m_pOPM2 = NULL;
	m_dBeforeTick = 0;
}

// �f�X�g���N�^
Manager::~Manager(){
}

// ������
void Manager::Initialize(){
	char cFilePath[MAX_PATH];
	// �����Ń��W���[���̃p�X���擾���ĕێ�����
	GetModuleFileName((HMODULE)m_hDll,cFilePath,MAX_PATH);
	int iPos = strlen(cFilePath) - 1;
	while(cFilePath[iPos] != '\\') iPos--;
	cFilePath[++iPos] = 0x00;

	// OPNA1������
	m_pOPNA1 = new FM::OPNA();
	m_pOPNA1->Init(7987200,8000,false,cFilePath);
	m_pOPNA1->Reset();
	m_pOPNA1->SetRate(7987200,50000,false);

	// OPNA2������
	m_pOPNA2 = new FM::OPNA();
	m_pOPNA2->Init(7987200,8000,false,cFilePath);
	m_pOPNA2->Reset();
	m_pOPNA2->SetRate(7987200,50000,false);

	// OPM1������
	m_pOPM1 = new FM::OPM();
	m_pOPM1->Init(4000000,8000);
	m_pOPM1->Reset();
	m_pOPM1->SetRate(4000000,50000,false);

	// OPM2������
	m_pOPM2 = new FM::OPM();
	m_pOPM2->Init(3579545,8000);
	m_pOPM2->Reset();
	m_pOPM2->SetRate(3579545,50000,false);

	m_dBeforeTick = timeGetTime();		// ���ݎ������擾
}

// �J��
void Manager::UnInitialize(){
	// OPNA1�J��
	if(m_pOPNA1){
		m_pOPNA1->Reset();
		delete m_pOPNA1;
		m_pOPNA1 = NULL;
	}

	// OPNA2�J��
	if(m_pOPNA2){
		m_pOPNA2->Reset();
		delete m_pOPNA2;
		m_pOPNA2 = NULL;
	}

	// OPM1�J��
	if(m_pOPM1){
		m_pOPM1->Reset();
		delete m_pOPM1;
		m_pOPM1 = NULL;
	}

	// OPM2�J��
	if(m_pOPM2){
		m_pOPM2->Reset();
		delete m_pOPM2;
		m_pOPM2 = NULL;
	}
}

// ���Z�b�g
void Manager::Reset(){
	// OPNA1���Z�b�g
	if(m_pOPNA1){
		m_pOPNA1->Reset();
	}

	// OPNA2���Z�b�g
	if(m_pOPNA2){
		m_pOPNA2->Reset();
	}

	// OPM1���Z�b�g
	if(m_pOPM1){
		m_pOPM1->Reset();
	}

	// OPM2���Z�b�g
	if(m_pOPM2){
		m_pOPM2->Reset();
	}
}

// ���ԍX�V
void Manager::UpdateTime(){
	DWORD dNowTick = timeGetTime();
	DWORD dTick = (dNowTick - m_dBeforeTick) * 1000;
	m_dBeforeTick = dNowTick;
	// �e�����Ɍo�ߎ��Ԃ�ݒ肷��
	if(m_pOPNA1){
		m_pOPNA1->Count(dTick);
	}

	// OPNA2���Z�b�g
	if(m_pOPNA2){
		m_pOPNA2->Count(dTick);
	}

	// OPM1���Z�b�g
	if(m_pOPM1){
		m_pOPM1->Count(dTick);
	}

	// OPM2���Z�b�g
	if(m_pOPM2){
		m_pOPM2->Count(dTick);
	}
}

// ���W�X�^�ݒ�
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

// PCM����
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

