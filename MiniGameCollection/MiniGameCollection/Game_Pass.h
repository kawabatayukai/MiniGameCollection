#pragma once
#define GAME_MAX 11

/*****************************************************************/   /***************************************/
/*                                                               */   /*                                     */
/*  配列の順番は選択画面のアイコンと同じになるようにしてください */   /*   "LPSTR"型　==  const char*型　    */
/*                                                               */   /*                         らしいです  */
/*****************************************************************/   /***************************************/

// 0番　ヘビ
// 1番　ネコ
// 2番
// 3番
// 4番
// 5番
// 6番
// 7番
// 8番
// 9番
//10番


//exeファイルの相対パス（このプラグラムから見てどこにあるか）
const char* Game_Pass[GAME_MAX] =
{
	// 0
	"All_Games\\Snake_Game\\SnakeGame_MyProject_ver 0.20.exe",
	// 1
	"All_Games\\Neko_Game\\Mini_Neco.exe",
	// 2
	"All_Games\\Pac_Man\\Game_PACMAN.exe",
};


//カレントディレクトリ名（exeファイルが置いてある場所）
const char* Current_Pass[GAME_MAX] =
{
	"All_Games\\Snake_Game",
	"All_Games\\Neko_Game",
	"All_Games\\Pac_Man"
};

//説明文　タイトル
const char* Title_Text[GAME_MAX + 1] =
{
	"ヘビゲーム",       //0
	"Corriend",         //1
	"PAC - MAN",        //2
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