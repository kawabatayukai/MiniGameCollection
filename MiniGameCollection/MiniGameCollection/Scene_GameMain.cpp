#include"DxLib.h"
#include"Scene_GameMain.h"
#include"Game_Pass.h"

//�R���X�g���N�^
GameMainScene::GameMainScene()
{
	// �I����ʓǂݍ���
	homeImage = LoadGraph("images/testHome.png");

	//�J�[�\���I�u�W�F�N�g�����E�R���X�g���N�^�Ăяo��
	obj_cursor = new Cursor();

	//�t�H���g�̍쐬
	font_exp = CreateFontToHandle(NULL, 80, 3, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);

	ZeroMemory(&start_info, sizeof(start_info));    //start_info(STARTUPINFO�\���̌^)��������
	start_info.cb = sizeof(start_info);             //�����ocb�i�\���̃T�C�Y�j��ݒ�
}

//�f�X�g���N�^
GameMainScene::~GameMainScene()
{
	DeleteFontToHandle(font_exp);
}

//�X�V
void GameMainScene::Update()
{
	//�J�[�\���ړ�
	obj_cursor->CursorUpdate(keyflg);

	//�Q�[�����N��
	StartUp(&process_info, &start_info, obj_cursor->GetGameNum());
}

//�`��
void GameMainScene::Draw() const
{
	DrawString(0, 0, "GameMainScene", 0xffffff);

	//�z�[����ʂ̕`��
	DrawGraph(0, 0, homeImage, TRUE);

	//�J�[�\���̕`��
	obj_cursor->CursorDraw();

	//�Q�[���^�C�g�� ������
	DrawFormatStringToHandle(160, 20, 0xffffff, font_exp, Title_Text[obj_cursor->GetGameNum()]);
}

//�V�[���̕ύX
AbstractScene* GameMainScene::ChangeScene()
{
	//�X�V�Ȃ�
	return this;
}

//�Q�[�����N��
void GameMainScene::StartUp(PROCESS_INFORMATION* process, STARTUPINFO* start, int GameNum)
{
	//A�{�^���Ŏ��s
	if (keyflg & PAD_INPUT_A)
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