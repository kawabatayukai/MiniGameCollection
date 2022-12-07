#pragma once
#include"AbstractScene.h"
#include"Cursor.h"
#include"ProcessStarter.h"

//�Q�[�����C��
class GameMainScene : public AbstractScene
{
public:
	//�R���X�g���N�^
	GameMainScene();

	//�f�X�g���N�^
	~GameMainScene();

	//�X�V
	void Update();

	//�`��
	void Draw() const;

	//�V�[���̕ύX
	AbstractScene* ChangeScene() override;

	//�Q�[�����N��
	void Process_Start(int GameNum = 0);

private:
	Cursor* obj_cursor;              //�J�[�\���I�u�W�F�N�g
	ProcessStarter* obj_starter;     //�N���N���X�I�u�W�F�N�g

	int homeImage;                   //�z�[����ʉ摜
	int font_exp;                    //��ʏ㕔�̐������p�t�H���g

	int se_start;                    //����{�^����
};
