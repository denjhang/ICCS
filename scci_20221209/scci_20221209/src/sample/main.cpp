//----------------------------------------
// scciサンプルプログラム
//----------------------------------------
#include <Windows.h>
#include "scci.h"
#include "SCCIDefines.h"
#include <stdio.h>

// メイン関数
int	main(int argc,char **argv){
	HMODULE	hScci = NULL;

	// scci.dllの読込み
	hScci = ::LoadLibrary((LPCSTR)"scci");
	if(hScci == NULL){
		::FreeLibrary(hScci);
		return GetLastError();
	}

	// サウンドインターフェースマネージャー取得用関数アドレス取得
	SCCIFUNC getSoundInterfaceManager  = (SCCIFUNC)(::GetProcAddress(hScci,"getSoundInterfaceManager"));
	if(getSoundInterfaceManager == NULL){
		::FreeLibrary(hScci);
		return GetLastError();
	}

	// サウンドインターフェースマネージャー取得
	SoundInterfaceManager *pManager = getSoundInterfaceManager();

	// サウンドインターフェースマネージャーインスタンス初期化
	// 必ず最初に実行してください
	pManager->initializeInstance();

	// リセットを行う
	pManager->reset();

	// データ送信遅延時間設定
	// 設定しない場合は、scci.iniファイルに定義されている時間が適用されます
	pManager->setDelay(20);

	// サウンドデバイス取得
	// 第一引数　サウンドチップID
	// 第二引数　サウンドチップクロック
	//         　クロックについては、接続されているサウンドチップで
	//         　一番近いクロックのものが払い出しされます
	// 戻り値  　サウンドチップクラスのインスタンス
	//         　サウンドチップが取得できない場合NULLが返却されます。
	SoundChip *pChip = pManager->getSoundChip(SC_TYPE_YM2608,SC_CLOCK_7987200);
	if(pChip == NULL){
		// サウンドチップ取得できず
		printf("getSoundChip Error \r\n");
		return -1;
	}

	// データの送信
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

	// チップの開放（チップ単位で開放の場合）
	pManager->releaseSoundChip(pChip);

	// 一括開放する場合（チップ一括開放の場合）
	pManager->releaseAllSoundChip();

	// サウンドインターフェースマネージャーインスタンス開放
	// FreeLibraryを行う前に必ず呼び出ししてください
	pManager->releaseInstance();

	// ＤＬＬの開放
	::FreeLibrary(hScci);

	return	0;
}

