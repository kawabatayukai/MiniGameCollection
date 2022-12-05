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
	"All_Games\\Yoza_Snake\\SnakeGame_MyProject_ver Test0.15.exe",
	// 1
	"All_Games\\Kawabata_Neko\\Mini_Neco.exe",
	// 2
	"All_Games\\Arakaki_Poker",
	// 3
	"All_Games\\Miyagi_Shinkei",
	// 4
	"All_Games\\Okuhama_Baba",
	// 5
	"All_Games\\Bise_Iraira",
	// 6
	"All_Games\\Miyara_Air",
	// 7
	"All_Games\\Nakayoshi_Twins",
	// 8
	"All_Games\\Tamayose_Command",
	// 9
	"All_Games\\Tanahara_Setsuna",
	// 10
	"All_Games\\Yonahara_Reversi",
};


//�J�����g�f�B���N�g�����iexe�t�@�C�����u���Ă���ꏊ�j
const char* Current_Path[GAME_MAX] =
{
	"All_Games\\Yoza_Snake",
	"All_Games\\Kawabata_Neko",
	"All_Games\\Arakaki_Poker",
	"All_Games\\Miyagi_Shinkei",
	"All_Games\\Okuhama_Baba",
	"All_Games\\Bise_Iraira",
	"All_Games\\Miyara_Air",
	"All_Games\\Nakayoshi_Twins",
	"All_Games\\Tamayose_Command",
	"All_Games\\Tanahara_Setsuna",
	"All_Games\\Yonahara_Reversi",
};

//�������@�^�C�g��
const char* Title_Text[GAME_MAX + 1] =
{
	"�w�r�Q�[��",       //0
	"Corriend",         //1
	"Open Poker",       //2
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