#pragma once
#define GAME_MAX 11

/*****************************************************************/   /***************************************/
/*                                                               */   /*                                     */
/*  �z��̏��Ԃ͑I����ʂ̃A�C�R���Ɠ����ɂȂ�悤�ɂ��Ă������� */   /*   "LPSTR"�^�@==  const char*�^�@    */
/*                                                               */   /*                         �炵���ł�  */
/*****************************************************************/   /***************************************/

// 0�ԁ@�w�r
// 1�ԁ@�l�R
// 2��
// 3��
// 4��
// 5��
// 6��
// 7��
// 8��
// 9��
//10��


//exe�t�@�C���̑��΃p�X�i���̃v���O�������猩�Ăǂ��ɂ��邩�j
const char* Game_Pass[GAME_MAX] =
{
	// 0
	"All_Games\\Snake_Game\\SnakeGame_MyProject_ver 0.20.exe",
	// 1
	"All_Games\\Neko_Game\\Mini_Neco.exe",
	// 2
	"All_Games\\Pac_Man\\Game_PACMAN.exe",
};


//�J�����g�f�B���N�g�����iexe�t�@�C�����u���Ă���ꏊ�j
const char* Current_Pass[GAME_MAX] =
{
	"All_Games\\Snake_Game",
	"All_Games\\Neko_Game",
	"All_Games\\Pac_Man"
};

//�������@�^�C�g��
const char* Title_Text[GAME_MAX + 1] =
{
	"�w�r�Q�[��",       //0
	"Corriend",         //1
	"PAC - MAN",        //2
	"�ߓ��o��\��",     //3
	"�ߓ��o��\��",     //4
	"�ߓ��o��\��",     //5
	"�ߓ��o��\��",     //6
	"�ߓ��o��\��",     //7
	"�ߓ��o��\��",     //8
	"�ߓ��o��\��",     //9
	"�ߓ��o��\��",     //10
	"12�ځ@HELP�Ȃ�", //(11)
};