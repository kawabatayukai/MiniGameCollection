#pragma once
#include<Windows.h>
#include"AbstractScene.h"
#include"Cursor.h"

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
	void StartUp(PROCESS_INFORMATION* process, STARTUPINFO* start, int GameNum = 0);

private:
	Cursor* obj_cursor;    //�J�[�\���I�u�W�F�N�g

	int homeImage;                   //�z�[����ʉ摜
	int font_exp;                    //��ʏ㕔�̐������p�t�H���g

	PROCESS_INFORMATION process_info;      //CreateProcess�ɂ���Đ��������v���Z�X�̏��
	STARTUPINFO start_info;                //�X�^�[�g�A�b�v�̏��i�\�����j 
};
