#pragma once
#define GAME_MAX 11

/*****************************************************************/   /***************************************/
/*                                                               */   /*  "LPSTR"型　==  char*型             */
/*  配列の順番は選択画面のアイコンと同じになるようにしてください */   /*  "LPCSTR"   ==  const char* 　      */
/*                                                               */   /*                         らしいです  */
/*****************************************************************/   /***************************************/

// 0番　ヘビ
// 1番　ネコ
// 2番  パックマン　テスト
// 3番
// 4番
// 5番
// 6番
// 7番
// 8番
// 9番
//10番


//exeファイルの相対パス（このプラグラムから見てどこにあるか）
const char* Game_Path[GAME_MAX] =
{
	// 0
	"All_Games\\Yoza_Snake\\SnakeGame_MyProject_ver Test0.15.exe",
	// 1
	"All_Games\\Kawabata_Neko\\Mini_Neco.exe",
	// 2
	"All_Games\\Arakaki_Poker",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
};


//カレントディレクトリ名（exeファイルが置いてある場所）
const char* Current_Path[GAME_MAX] =
{
	"All_Games\\Yoza_Snake",
	"All_Games\\Kawabata_Neko",
	"All_Games\\Arakaki_Poker",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
};

//説明文　タイトル
const char* Title_Text[GAME_MAX + 1] =
{
	"ヘビゲーム",       //0
	"Corriend",         //1
	"Open Poker",       //2
	"近日登場予定",     //3
	"近日登場予定",     //4
	"近日登場予定",     //5
	"近日登場予定",     //6
	"近日登場予定",     //7
	"近日登場予定",     //8
	"近日登場予定",     //9
	"近日登場予定",     //10
	"12個目　HELPなど", //(11)
};