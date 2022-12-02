#include"DxLib.h"
#include"DxLib.h"
#include<Windows.h>
#include"Game_Pass.h"
#include"Cursor.h"


/*�@�@�ϐ��@�@*/
int g_OldKey;      // �O��̓��̓L�[ 
int g_NowKey;      // ����̓��̓L�[ 
int g_KeyFlg;      // ���̓L�[���

Cursor* obj_cursor;     //�J�[�\���I�u�W�F�N�g

int HomeImage;                   //�z�[����ʉ摜
int CursorImage;                 //�J�[�\���摜

int font_exp;                    //��ʏ㕔�̐������p�t�H���g

PROCESS_INFORMATION process_info;      //CreateProcess�ɂ���Đ��������v���Z�X�̏��
STARTUPINFO start_info;                //�X�^�[�g�A�b�v�̏��i�\�����j 

//*************************�֐�*********************//

void StartUP(PROCESS_INFORMATION* process, STARTUPINFO* start, int GameNum = 0);                  //�Q�[�����N��
/***************************************************/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("TEST");              //�^�C�g����ݒ�
	ChangeWindowMode(TRUE);                 //�E�B���h�E���[�h�ŋN��
	//SetWindowSize(1280, 720);
	SetGraphMode(1280, 720, 32);            //�E�B���h�E�T�C�Y��ݒ�
	if (DxLib_Init() == -1) { return -1; }  //Dxײ���؏�������


	ZeroMemory(&start_info, sizeof(start_info));    //start_info(STARTUPINFO�\���̌^)��������
	start_info.cb = sizeof(start_info);             //�����ocb�i�\���̃T�C�Y�j��ݒ�

	//�t�H���g�̍쐬
	font_exp = CreateFontToHandle(NULL, 80, 3, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);

	//�摜�ǂݍ���
	HomeImage = LoadGraph("images/testHome.png");
	obj_cursor = new Cursor();
	
	SetDrawScreen(DX_SCREEN_BACK);         //�`����ʂ𗠂ɂ���

	while (ProcessMessage() == 0)
	{
		//�L�[���͎擾 
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

		// ��ʂ̏����� 
		ClearDrawScreen();

		//�z�[����ʂ̕`��
		DrawGraph(0, 0, HomeImage, TRUE);

		//�J�[�\���̕`��
		obj_cursor->CursorDraw();

		//�J�[�\���ړ�
		obj_cursor->CursorUpdate(g_KeyFlg);

		//�N��
		StartUP(&process_info, &start_info, obj_cursor->GetGameNum());

		//DrawFormatString(0, 0, 0xffffff, "%d", Game_Num);

		ScreenFlip();

	}
	DxLib_End();

	return 0;
}

//�Q�[�����N��
void StartUP(PROCESS_INFORMATION* process, STARTUPINFO* start, int GameNum)
{
	//A�{�^���Ŏ��s
	if (g_KeyFlg & PAD_INPUT_A)
	{
		//0�`10(��ʏ�ł�11��)
		if (GameNum < GAME_MAX)
		{
			//���s�Ώۂ�.exe
			const char* Start_Game = Game_Pass[GameNum];

			//���s�Ώۂ�.exe���u���Ă���ꏊ(�����ިڸ��)
			const char* Start_Current = Current_Pass[GameNum];

			//exe���s               �Q�[���̃p�X�@�@�@�@
			int ret = CreateProcess(Start_Game, (LPSTR)"", NULL, NULL, FALSE, NULL, NULL,
				Start_Current, start, process);

			if (ret)
			{
				//�N���Ɏ��s�I
				return;
			}
			else
			{
				//CloseHandle(process->hThread);

				//���s�Ώۂ��I������܂ő҂�
				//WaitForSingleObject(process->hProcess, INFINITE);
				CloseHandle(process->hProcess);
			}
		}
		else
		{
			//Game_Num == 11 (��ʏ�ł�12��)

			DrawString(0, 20, "HELP", 0xffffff);
		}

	}
}