#pragma once
#include"AbstractScene.h"

//�^�C�g��
class TitleScene : public AbstractScene
{
public:
	//�R���X�g���N�^
	TitleScene();

	//�f�X�g���N�^
	//~TitleScene();

	//�X�V
	void Update();

	//�`��
	void Draw() const;

	//�V�[���̕ύX
	AbstractScene* ChangeScene() override;

};