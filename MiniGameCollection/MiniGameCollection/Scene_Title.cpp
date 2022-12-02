#include"DxLib.h"
#include"Scene_Title.h"
#include"Scene_GameMain.h"

//�R���X�g���N�^
TitleScene::TitleScene()
{
}

//�X�V
void TitleScene::Update()
{

}

//�`��
void TitleScene::Draw() const
{
	SetFontSize(40);
	DrawString(100, 0, "�^�C�g��", 0xffffff);
	DrawString(100, 300, "A�{�^���ŃX�^�[�g", 0xffffff);
	SetFontSize(DX_FONTTYPE_NORMAL);
}

//�V�[���̕ύX
AbstractScene* TitleScene::ChangeScene()
{
	//A�{�^���Ń��C���V�[����
	if (keyflg & PAD_INPUT_A)
	{
		return dynamic_cast<AbstractScene*>(new GameMainScene());
	}

	//�X�V�Ȃ�
	return this;
}