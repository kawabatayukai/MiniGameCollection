#pragma once
#define GAME_MAX 11

/*****************************************************************/   /***************************************/
/*                                                               */   /*  "LPSTR"�^�@==  char*�^             */
/*  �z��̏��Ԃ͑I����ʂ̃A�C�R���Ɠ����ɂȂ�悤�ɂ��Ă������� */   /*  "LPCSTR"   ==  const char* �@      */
/*                                                               */   /*                         �炵���ł�  */
/*****************************************************************/   /***************************************/

// 0�ԁ@�w�r
// 1�ԁ@�l�R
// 2��  �|�[�J�[
// 3��
// 4��
// 5��
// 6��
// 7��
// 8��
// 9��
//10��


//exe�t�@�C���̑��΃p�X�i���̃v���O�������猩�Ăǂ��ɂ��邩�j
const char* Game_Path[GAME_MAX] =
{
	// 0
	"All_Games\\0_Yoza_Snake\\SnakeGame_MyProject_ver 0.45.exe",
	// 1
	"All_Games\\1_Kawabata_Neko\\Mini_Neco.exe",
	// 2
	"All_Games\\2_Arakaki_Poker\\2OpenPoker.exe",
	// 3
	"All_Games\\3_Miyagi_Shinkei\\Shinkei.exe",
	// 4
	"All_Games\\4_Okuhama_Baba",
	// 5
	"All_Games\\5_Bise_Iraira\\irairabou.exe",
	// 6
	"All_Games\\6_Miyara_Air",
	// 7
	"All_Games\\7_Nakayoshi_Twins\\twins.exe",
	// 9
    "All_Games\\8_Tanahara_Setsuna",
    // 8
    "All_Games\\9_Tamayose_Command\\miniGame.exe",
    // 10
    "All_Games\\10_Yonahara_Osero",
};


//�J�����g�f�B���N�g�����iexe�t�@�C�����u���Ă���ꏊ�j
const char* Current_Path[GAME_MAX] =
{
	"All_Games\\0_Yoza_Snake",
	"All_Games\\1_Kawabata_Neko",
	"All_Games\\2_Arakaki_Poker",
	"All_Games\\3_Miyagi_Shinkei",
	"All_Games\\4_Okuhama_Baba",
	"All_Games\\5_Bise_Iraira",
	"All_Games\\6_Miyara_Air",
	"All_Games\\7_Nakayoshi_Twins",
	"All_Games\\8_Tanahara_Setsuna",
	"All_Games\\9_Tamayose_Command",
	"All_Games\\10_Yonahara_Osero",
};

//�������@�^�C�g��
const char* Title_Text[GAME_MAX + 1] =
{
	"�w�r�Q�[��",       //0
	"Corriend",         //1
	"Open Poker",       //2
	"�_�o����",         //3
	"�ߓ��o��\��",     //4
	"�C���C���_",       //5
	"�G�A�z�b�P�[",     //6
	"twins",            //7
	"�ߓ��o��\��",     //8
	"�R�}���h�o�g��",     //9
	"�I�Z��",           //10
	"�^�C�g���֖߂�",   //(11)
};