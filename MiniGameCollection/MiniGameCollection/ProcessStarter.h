#pragma once

//�Q�[�����N�����郂�m
class ProcessStarter
{
public:
	ProcessStarter();   //�R���X�g���N�^
	~ProcessStarter();  //�f�X�g���N�^

	//�Q�[�����N������@�@.exe�܂ł̃p�X�@�A�@�J�����g�f�B���N�g�����iexe�t�@�C�����u���Ă���ꏊ�j
	void StartUp(const char* game_path, const char* current_path);

	//���ʎ擾
	bool GetStartResult();

private:
	bool result;        //�N������:TRUE�@���s:FALSE
};
