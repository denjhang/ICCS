//----------------------------------------
// scci�T���v���v���O����
//----------------------------------------
#include <Windows.h>
#include "scci.h"
#include "SCCIDefines.h"
#include <stdio.h>

// ���C���֐�
int	main(int argc,char **argv){
	HMODULE	hScci = NULL;

	// scci.dll�̓Ǎ���
	hScci = ::LoadLibrary((LPCSTR)"scci");
	if(hScci == NULL){
		::FreeLibrary(hScci);
		return GetLastError();
	}

	// �T�E���h�C���^�[�t�F�[�X�}�l�[�W���[�擾�p�֐��A�h���X�擾
	SCCIFUNC getSoundInterfaceManager  = (SCCIFUNC)(::GetProcAddress(hScci,"getSoundInterfaceManager"));
	if(getSoundInterfaceManager == NULL){
		::FreeLibrary(hScci);
		return GetLastError();
	}

	// �T�E���h�C���^�[�t�F�[�X�}�l�[�W���[�擾
	SoundInterfaceManager *pManager = getSoundInterfaceManager();

	// �T�E���h�C���^�[�t�F�[�X�}�l�[�W���[�C���X�^���X������
	// �K���ŏ��Ɏ��s���Ă�������
	pManager->initializeInstance();

	// ���Z�b�g���s��
	pManager->reset();

	// �f�[�^���M�x�����Ԑݒ�
	// �ݒ肵�Ȃ��ꍇ�́Ascci.ini�t�@�C���ɒ�`����Ă��鎞�Ԃ��K�p����܂�
	pManager->setDelay(20);

	// �T�E���h�f�o�C�X�擾
	// �������@�T�E���h�`�b�vID
	// �������@�T�E���h�`�b�v�N���b�N
	//         �@�N���b�N�ɂ��ẮA�ڑ�����Ă���T�E���h�`�b�v��
	//         �@��ԋ߂��N���b�N�̂��̂������o������܂�
	// �߂�l  �@�T�E���h�`�b�v�N���X�̃C���X�^���X
	//         �@�T�E���h�`�b�v���擾�ł��Ȃ��ꍇNULL���ԋp����܂��B
	SoundChip *pChip = pManager->getSoundChip(SC_TYPE_YM2608,SC_CLOCK_7987200);
	if(pChip == NULL){
		// �T�E���h�`�b�v�擾�ł���
		printf("getSoundChip Error \r\n");
		return -1;
	}

	// �f�[�^�̑��M
	pChip->setRegister(0x00,0xf0);
	pChip->setRegister(0x01,0xf0);
	pChip->setRegister(0x02,0xf0);
	pChip->setRegister(0x03,0xf0);
	pChip->setRegister(0x04,0xf0);
	pChip->setRegister(0x05,0xf0);
	pChip->setRegister(0x07,0x00);
	pChip->setRegister(0x08,0x0f);
	pChip->setRegister(0x09,0x0f);
	pChip->setRegister(0x01,0x0f);

	Sleep(1000);

	// �`�b�v�̊J���i�`�b�v�P�ʂŊJ���̏ꍇ�j
	pManager->releaseSoundChip(pChip);

	// �ꊇ�J������ꍇ�i�`�b�v�ꊇ�J���̏ꍇ�j
	pManager->releaseAllSoundChip();

	// �T�E���h�C���^�[�t�F�[�X�}�l�[�W���[�C���X�^���X�J��
	// FreeLibrary���s���O�ɕK���Ăяo�����Ă�������
	pManager->releaseInstance();

	// �c�k�k�̊J��
	::FreeLibrary(hScci);

	return	0;
}

