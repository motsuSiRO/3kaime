#include "DxLib.h"
#include "common.h"
#include "scene.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

#endif

	SetOutApplicationLogValidFlag(false);

	//アイコンの変更
	//SetWindowIconID(33);

	SetMainWindowText("Team03仮題");

	//ウインドウのサイズを自由に変更出来るようにする
	SetWindowSizeChangeEnableFlag(TRUE);

	// 描画可能サイズをディスプレイのサイズに
	//SetGraphMode(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), 32);    //メインウインドウのクライアント領域のサイズを設定する

	//ウィンドウモードに変更  0:Full / 1:windows
	ChangeWindowMode(0);

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 16);

	SetWindowStyleMode(10);


	//SRand((unsigned int)time(NULL));

	if (DxLib_Init() == -1) return -1;    // ＤＸライブラリ初期化処理 エラーが起きたら終了

	SetDrawScreen(DX_SCREEN_BACK);

	sceneManager scenemanager;

	scenemanager.changeScene(scenemanager.TITLE);

	while (gameexit && ProcessMessage() == 0)
	{
		ClearDrawScreen();// 裏画面のデータを全て削除

		
		InputKey();
		

		//InputJoypad();

		scenemanager.execute();

		ScreenFlip();

		//if (ProcessMessage() == -1) break;                 //エラーが起きたら終了

	}

	//InitSoundMem();
	scenemanager.unInit();
	

	DxLib_End();                                            // ＤＸライブラリ使用の終了処理
	return 0;                                               // ソフトの終了
}