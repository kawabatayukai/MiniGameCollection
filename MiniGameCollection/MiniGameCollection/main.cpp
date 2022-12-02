#include"DxLib.h"
#include"DxLib.h"
#include<Windows.h>
#include"Game_Pass.h"
#include"Cursor.h"


/*　　変数　　*/
int g_OldKey;      // 前回の入力キー 
int g_NowKey;      // 今回の入力キー 
int g_KeyFlg;      // 入力キー情報

Cursor* obj_cursor;     //カーソルオブジェクト

int HomeImage;                   //ホーム画面画像
int CursorImage;                 //カーソル画像

int font_exp;                    //画面上部の説明文用フォント

PROCESS_INFORMATION process_info;      //CreateProcessによって生成されるプロセスの情報
STARTUPINFO start_info;                //スタートアップの情報（表示情報） 

//*************************関数*********************//

void StartUP(PROCESS_INFORMATION* process, STARTUPINFO* start, int GameNum = 0);                  //ゲームを起動
/***************************************************/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("TEST");              //タイトルを設定
	ChangeWindowMode(TRUE);                 //ウィンドウモードで起動
	//SetWindowSize(1280, 720);
	SetGraphMode(1280, 720, 32);            //ウィンドウサイズを設定
	if (DxLib_Init() == -1) { return -1; }  //Dxﾗｲﾌﾞﾗﾘ初期処理


	ZeroMemory(&start_info, sizeof(start_info));    //start_info(STARTUPINFO構造体型)を初期化
	start_info.cb = sizeof(start_info);             //メンバcb（構造体サイズ）を設定

	//フォントの作成
	font_exp = CreateFontToHandle(NULL, 80, 3, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);

	//画像読み込み
	HomeImage = LoadGraph("images/testHome.png");
	obj_cursor = new Cursor();
	
	SetDrawScreen(DX_SCREEN_BACK);         //描画先画面を裏にする

	while (ProcessMessage() == 0)
	{
		//キー入力取得 
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

		// 画面の初期化 
		ClearDrawScreen();

		//ホーム画面の描画
		DrawGraph(0, 0, HomeImage, TRUE);

		//カーソルの描画
		obj_cursor->CursorDraw();

		//カーソル移動
		obj_cursor->CursorUpdate(g_KeyFlg);

		//起動
		StartUP(&process_info, &start_info, obj_cursor->GetGameNum());

		//DrawFormatString(0, 0, 0xffffff, "%d", Game_Num);

		ScreenFlip();

	}
	DxLib_End();

	return 0;
}

//ゲームを起動
void StartUP(PROCESS_INFORMATION* process, STARTUPINFO* start, int GameNum)
{
	//Aボタンで実行
	if (g_KeyFlg & PAD_INPUT_A)
	{
		//0～10(画面上では11個)
		if (GameNum < GAME_MAX)
		{
			//実行対象の.exe
			const char* Start_Game = Game_Pass[GameNum];

			//実行対象の.exeが置いてある場所(ｶﾚﾝﾄﾃﾞｨﾚｸﾄﾘ)
			const char* Start_Current = Current_Pass[GameNum];

			//exe実行               ゲームのパス　　　　
			int ret = CreateProcess(Start_Game, (LPSTR)"", NULL, NULL, FALSE, NULL, NULL,
				Start_Current, start, process);

			if (ret)
			{
				//起動に失敗！
				return;
			}
			else
			{
				//CloseHandle(process->hThread);

				//実行対象が終了するまで待つ
				//WaitForSingleObject(process->hProcess, INFINITE);
				CloseHandle(process->hProcess);
			}
		}
		else
		{
			//Game_Num == 11 (画面上では12個目)

			DrawString(0, 20, "HELP", 0xffffff);
		}

	}
}