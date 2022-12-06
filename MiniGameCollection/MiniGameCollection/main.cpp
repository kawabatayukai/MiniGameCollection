#include"DxLib.h"

#include"SceneManager.h"
#include"Scene_Title.h"


/*�@�@�ϐ��@�@*/
int g_OldKey;      // �O��̓��̓L�[ 
int g_NowKey;      // ����̓��̓L�[ 
int g_KeyFlg;      // ���̓L�[���


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("TEST");              //�^�C�g����ݒ�
	ChangeWindowMode(TRUE);                 //�E�B���h�E���[�h�ŋN��
	//SetWindowSize(1280, 720);
	SetGraphMode(1280, 720, 32);            //�E�B���h�E�T�C�Y��ݒ�
	if (DxLib_Init() == -1) { return -1; }  //Dxײ���؏�������

	//�V�[���}�l�[�W���[     �@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�^�C�g����ݒ�
	SceneManager sceneMng(dynamic_cast<AbstractScene*>(new TitleScene()));

	SetDrawScreen(DX_SCREEN_BACK);         //�`����ʂ𗠂ɂ���

	while (ProcessMessage() == 0 && !(g_NowKey & PAD_INPUT_9) && !(g_NowKey & PAD_INPUT_7))
	{
		//�L�[���͎擾 
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

		// ��ʂ̏����� 
		ClearDrawScreen();

		sceneMng.SetKeyFlg(g_KeyFlg, g_NowKey);  //�L�[����
		sceneMng.Update();     //�X�V
		sceneMng.Draw();       //�`��

		//�V�[���̕ύX   END�̏ꍇ�@nullptr
		if (sceneMng.ChangeScene() == nullptr)
		{
			DxLib_End();  //DxLib�I������
			return 0;
		}

		ScreenFlip();

	}
	DxLib_End();

	return 0;
}
