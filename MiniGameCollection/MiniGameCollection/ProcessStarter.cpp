#include<Windows.h>
#include"ProcessStarter.h"

//�R���X�g���N�^
ProcessStarter::ProcessStarter() : result(FALSE)
{
}

//�f�X�g���N�^
ProcessStarter::~ProcessStarter(){}

//�Q�[�����N������@�@.exe�܂ł̃p�X�@�A�@�J�����g�f�B���N�g�����iexe�t�@�C�����u���Ă���ꏊ�j
void ProcessStarter::StartUp(const char* game_path, const char* current_path)
{
	result = TRUE;   //�N���J�n�̍��}

	PROCESS_INFORMATION process_info = {};           //CreateProcess�ɂ���Đ��������v���Z�X�̏����i�[����\����
	STARTUPINFO start_info = {};                     //�N������v���Z�X�̕\����Ԃ��i�[����\����

	ZeroMemory(&process_info, sizeof(process_info)); //process_info��������
	ZeroMemory(&start_info, sizeof(start_info));     //start_info��������
	start_info.cb = sizeof(start_info);              //�����ocb�i�\���̃T�C�Y�j��ݒ�

	//�X�^�[�g�A�b�v���𓾂�
	GetStartupInfo(&start_info);

	//���E�B���h�E�������Ȃ���ԂŋN��������
	start_info.dwFlags = STARTF_USESHOWWINDOW;       //"wShowWindow"��L��������
	start_info.wShowWindow = SW_HIDE;                //���E�B���h�E���A�N�e�B�u�ɁA���̃E�B���h�E���A�N�e�B�u�ɂ���

	//�N��    
	result = CreateProcess(game_path, NULL, NULL, NULL, FALSE, NULL, NULL, current_path, &start_info, &process_info);

	//���s�Ώۂ��I������܂ő҂�
	WaitForSingleObject(process_info.hProcess, INFINITE);

	//�n���h���i�v���Z�X�i���s�Ώہj�ւ̃|�C���^?�j�����  
	CloseHandle(process_info.hProcess);              
	CloseHandle(process_info.hThread); 

	//�I���̍��}
	result = FALSE;
}

//���ʂ��擾
bool ProcessStarter::GetStartResult() { return result; }