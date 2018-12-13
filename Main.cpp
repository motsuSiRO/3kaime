#include "DxLib.h"
#include "common.h"
#include "scene.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

#endif

	SetOutApplicationLogValidFlag(false);

	//�A�C�R���̕ύX
	//SetWindowIconID(33);

	SetMainWindowText("Team03����");

	//�E�C���h�E�̃T�C�Y�����R�ɕύX�o����悤�ɂ���
	SetWindowSizeChangeEnableFlag(TRUE);

	// �`��\�T�C�Y���f�B�X�v���C�̃T�C�Y��
	//SetGraphMode(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), 32);    //���C���E�C���h�E�̃N���C�A���g�̈�̃T�C�Y��ݒ肷��

	//�E�B���h�E���[�h�ɕύX  0:Full / 1:windows
	ChangeWindowMode(0);

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 16);

	SetWindowStyleMode(10);


	//SRand((unsigned int)time(NULL));

	if (DxLib_Init() == -1) return -1;    // �c�w���C�u�������������� �G���[���N������I��

	SetDrawScreen(DX_SCREEN_BACK);

	sceneManager scenemanager;

	scenemanager.changeScene(scenemanager.TITLE);

	while (gameexit && ProcessMessage() == 0)
	{
		ClearDrawScreen();// ����ʂ̃f�[�^��S�č폜

		
		InputKey();
		

		//InputJoypad();

		scenemanager.execute();

		ScreenFlip();

		//if (ProcessMessage() == -1) break;                 //�G���[���N������I��

	}

	//InitSoundMem();
	scenemanager.unInit();
	

	DxLib_End();                                            // �c�w���C�u�����g�p�̏I������
	return 0;                                               // �\�t�g�̏I��
}
