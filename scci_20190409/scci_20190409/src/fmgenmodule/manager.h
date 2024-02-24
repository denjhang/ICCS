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
	// �R���X�g���N�^
	Manager(HINSTANCE hDll);
	// �f�X�g���N�^
	~Manager();
	// ������
	void Initialize();
	// �J��
	void UnInitialize();
	// ���Z�b�g
	void Reset();
	// ���ԍX�V
	void UpdateTime();
	// ���W�X�^�ݒ�
	void SetRegister(DWORD dModuleNum,DWORD dReg,DWORD dData);
	// PCM����
	void SoundMixing(FM::Sample *pBuff,int size);
};
