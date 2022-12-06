#pragma once
#define GAME_MAX 11

/*****************************************************************/   /***************************************/
/*                                                               */   /*  "LPSTR"型　==  char*型             */
/*  配列の順番は選択画面のアイコンと同じになるようにしてください */   /*  "LPCSTR"   ==  const char* 　      */
/*                                                               */   /*                         らしいです  */
/*****************************************************************/   /***************************************/

// 0番　ヘビ
// 1番　ネコ
// 2番  ポーカー
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


//カレントディレクトリ名（exeファイルが置いてある場所）
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

//説明文　タイトル
const char* Title_Text[GAME_MAX + 1] =
{
	"ヘビゲーム",       //0
	"Corriend",         //1
	"Open Poker",       //2
	"神経衰弱",         //3
	"近日登場予定",     //4
	"イライラ棒",       //5
	"エアホッケー",     //6
	"twins",            //7
	"近日登場予定",     //8
	"コマンドバトル",     //9
	"オセロ",           //10
	"タイトルへ戻る",   //(11)
};