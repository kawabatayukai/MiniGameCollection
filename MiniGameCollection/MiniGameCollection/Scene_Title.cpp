#include"DxLib.h"
#include"Scene_Title.h"
#include"Scene_GameMain.h"

//�R���X�g���N�^
TitleScene::TitleScene()
{
	//�摜�ǂݍ���
	titleimage = LoadGraph("images/titletest.png");
	select_num = 0;

	//�����ǂݍ���
	se_start = LoadSoundMem("sounds/se_title_button.wav");
	se_select = LoadSoundMem("sounds/se_cursor.wav");
}

//�X�V
void TitleScene::Update()
{
	//�R���g���[���[�őI��
	if (keyflg & PAD_INPUT_DOWN)
	{
		//���ʉ��Đ�
		PlaySoundMem(se_select, DX_PLAYTYPE_BACK);

		select_num++;     //�J�[�\����
		if (select_num > 1) select_num = 0;
	}
	if (keyflg & PAD_INPUT_UP)
	{
		//���ʉ��Đ�
		PlaySoundMem(se_select, DX_PLAYTYPE_BACK);

		select_num--;     //�J�[�\����
		if (select_num < 0) select_num = 1;
	}
}

//�`��
void TitleScene::Draw() const
{
	//�^�C�g���摜
	DrawGraph(0, 0, titleimage, FALSE);

	//�I���J�[�\���`��
	DrawCircle(440, 520 + (select_num * 120), 20, 0x000000, TRUE);
}

//�V�[���̕ύX
AbstractScene* TitleScene::ChangeScene()
{
	//A�{�^���Ń��C���V�[����
	if (keyflg & PAD_INPUT_A)
	{
		//���ʉ��Đ�
		PlaySoundMem(se_start, DX_PLAYTYPE_BACK);

		switch (select_num)
		{
		case 0:
			//�Q�[�����C����
			return dynamic_cast<AbstractScene*>(new GameMainScene());
			break;

		case 1:
			return nullptr;    //nullptr(�Q�[�����I��)
			break;

		default:
			break;
		}
	}

	//�X�V�Ȃ�
	return this;
}