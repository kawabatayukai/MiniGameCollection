#include"DxLib.h"
#include"Scene_GameMain.h"
#include"Game_Pass.h"

//�ŏ��� �A��/�i�V
#define WINDOW_MINIMIZE

//�R���X�g���N�^
GameMainScene::GameMainScene()
{
	// �I����ʓǂݍ���
	homeImage = LoadGraph("images/testHome.png");

	//�J�[�\���I�u�W�F�N�g�����E�R���X�g���N�^�Ăяo��
	obj_cursor = new Cursor();

	//�N���N���X�I�u�W�F�N�g
	obj_starter = new ProcessStarter();

	//�t�H���g�̍쐬
	font_exp = CreateFontToHandle(NULL, 80, 3, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
}

//�f�X�g���N�^
GameMainScene::~GameMainScene()
{
	delete obj_cursor;
	delete obj_starter;
	DeleteFontToHandle(font_exp);
}

//�X�V
void GameMainScene::Update()
{
	//�J�[�\���ړ�
	obj_cursor->CursorUpdate(keyflg);

	//�Q�[�����N��
	Process_Start(obj_cursor->GetGameNum());
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
void GameMainScene::Process_Start(int GameNum)
{
	//A�{�^���Ŏ��s
	if (keyflg & PAD_INPUT_A && (Game_Path[GameNum] != ""))
	{
		//0�`10(��ʏ�ł�11��)
		if (GameNum < GAME_MAX)
		{
			//�ʂ̃v���Z�X���N�����Ă��Ȃ���
			if (obj_starter->GetStartResult() == false)
			{

#ifdef WINDOW_MINIMIZE
				SetWindowMinimizeFlag(TRUE);   //���E�B���h�E���ŏ���
#endif 

				//�v���Z�X���N��
				obj_starter->StartUp(Game_Path[GameNum], Current_Path[GameNum]);
			}
		}
		else
		{
			//Game_Num == 11 (��ʏ�ł�12��)
			DrawString(0, 20, "HELP", 0xffffff);
		}
	}

#ifdef WINDOW_MINIMIZE
	SetWindowMinimizeFlag(FALSE);              //�ŏ���������
#endif
}