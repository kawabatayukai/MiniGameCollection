#include"DxLib.h"
#include"DxLib.h"
#include<Windows.h>
#include"Game_Pass.h"


/*�@�@�ϐ��@�@*/
int g_OldKey;      // �O��̓��̓L�[ 
int g_NowKey;      // ����̓��̓L�[ 
int g_KeyFlg;      // ���̓L�[���

const int Cursor_INIT_X = 40;    //�J�[�\�����������W
const int Cursor_INIT_Y = 100;   //�J�[�\�����������W
int Cursor_x = 0;                //�J�[�\�������W
int Cursor_y = 0;                //�J�[�\�������W
int Cursor_numX = 0;             //���݁Z�Ԗځ@������
int Cursor_numY = 0;             //���݁Z�Ԗځ@������

int Game_Num = 0;                //�N������Q�[��

int HomeImage;                   //�z�[����ʉ摜
int CursorImage;                 //�J�[�\���摜

int font_exp;                    //��ʏ㕔�̐������p�t�H���g

PROCESS_INFORMATION process_info;      //CreateProcess�ɂ���Đ��������v���Z�X�̏��
STARTUPINFO start_info;                //�X�^�[�g�A�b�v�̏��i�\�����j 

//*************************�֐�*********************//
void CursorUpdate();             //�J�[�\���ړ�
void CursorDraw();               //�J�[�\���`��

void StartUP(PROCESS_INFORMATION* process, STARTUPINFO* start);                  //�Q�[�����N��
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
	CursorImage = LoadGraph("images/frame.png");

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
		CursorDraw();

		//�J�[�\���ړ�
		CursorUpdate();

		//�N��
		StartUP(&process_info, &start_info);

		DrawFormatString(0, 0, 0xffffff, "%d", Game_Num);

		ScreenFlip();

	}
	DxLib_End();

	return 0;
}

//�J�[�\���ړ�
void CursorUpdate()
{
	//�E
	if (g_KeyFlg & PAD_INPUT_RIGHT)
	{
		Cursor_numX++;
		if (Cursor_numX > 5) Cursor_numX = 0;
	}

	//��
	if (g_KeyFlg & PAD_INPUT_LEFT)
	{
		Cursor_numX--;
		if (Cursor_numX < 0) Cursor_numX = 5;
	}

	//��
	if (g_KeyFlg & PAD_INPUT_DOWN)
	{
		Cursor_numY++;
		if (Cursor_numY > 1) Cursor_numY = 0;
	}

	//��
	if (g_KeyFlg & PAD_INPUT_UP)
	{
		Cursor_numY--;
		if (Cursor_numY < 0) Cursor_numY = 1;
	}

	//�`��J�[�\���̍��W��ݒ�
	Cursor_x = Cursor_INIT_X + Cursor_numX * 200;
	Cursor_y = Cursor_INIT_Y + (Cursor_numY * 200) + (Cursor_numY == 0 ? 0 : 20);

	//�N������Q�[���ԍ�  ��i0�`5,���i6�`11
	Game_Num = Cursor_numX + (Cursor_numY * 6);
}

//�J�[�\���`��
void CursorDraw()
{
	//�`��@��_�͍���
	DrawGraph(Cursor_x, Cursor_y, CursorImage, TRUE);

	//�^�C�g���@������
	DrawFormatStringToHandle(160, 20, 0xffffff, font_exp, Title_Text[Game_Num]);
}

//�Q�[�����N��
void StartUP(PROCESS_INFORMATION* process, STARTUPINFO* start)
{
	//A�{�^���Ŏ��s
	if (g_KeyFlg & PAD_INPUT_A)
	{
		//0�`10(��ʏ�ł�11��)
		if (Game_Num < GAME_MAX)
		{
			//���s�Ώۂ�.exe
			const char* Start_Game = Game_Pass[Game_Num];

			//���s�Ώۂ�.exe���u���Ă���ꏊ(�����ިڸ��)
			const char* Start_Current = Current_Pass[Game_Num];

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