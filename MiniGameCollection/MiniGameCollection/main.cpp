#include"DxLib.h"
#include"DxLib.h"
#include<Windows.h>
#include"Game_Pass.h"


/*　　変数　　*/
int g_OldKey;      // 前回の入力キー 
int g_NowKey;      // 今回の入力キー 
int g_KeyFlg;      // 入力キー情報

const int Cursor_INIT_X = 40;    //カーソル初期ｘ座標
const int Cursor_INIT_Y = 100;   //カーソル初期ｙ座標
int Cursor_x = 0;                //カーソルｘ座標
int Cursor_y = 0;                //カーソルｙ座標
int Cursor_numX = 0;             //現在〇番目　ｘ方向
int Cursor_numY = 0;             //現在〇番目　ｙ方向

int Game_Num = 0;                //起動するゲーム

int HomeImage;                   //ホーム画面画像
int CursorImage;                 //カーソル画像

int font_exp;                    //画面上部の説明文用フォント

PROCESS_INFORMATION process_info;      //CreateProcessによって生成されるプロセスの情報
STARTUPINFO start_info;                //スタートアップの情報（表示情報） 

//*************************関数*********************//
void CursorUpdate();             //カーソル移動
void CursorDraw();               //カーソル描画

void StartUP(PROCESS_INFORMATION* process, STARTUPINFO* start);                  //ゲームを起動
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
	CursorImage = LoadGraph("images/frame.png");

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
		CursorDraw();

		//カーソル移動
		CursorUpdate();

		//起動
		StartUP(&process_info, &start_info);

		DrawFormatString(0, 0, 0xffffff, "%d", Game_Num);

		ScreenFlip();

	}
	DxLib_End();

	return 0;
}

//カーソル移動
void CursorUpdate()
{
	//右
	if (g_KeyFlg & PAD_INPUT_RIGHT)
	{
		Cursor_numX++;
		if (Cursor_numX > 5) Cursor_numX = 0;
	}

	//左
	if (g_KeyFlg & PAD_INPUT_LEFT)
	{
		Cursor_numX--;
		if (Cursor_numX < 0) Cursor_numX = 5;
	}

	//下
	if (g_KeyFlg & PAD_INPUT_DOWN)
	{
		Cursor_numY++;
		if (Cursor_numY > 1) Cursor_numY = 0;
	}

	//上
	if (g_KeyFlg & PAD_INPUT_UP)
	{
		Cursor_numY--;
		if (Cursor_numY < 0) Cursor_numY = 1;
	}

	//描画カーソルの座標を設定
	Cursor_x = Cursor_INIT_X + Cursor_numX * 200;
	Cursor_y = Cursor_INIT_Y + (Cursor_numY * 200) + (Cursor_numY == 0 ? 0 : 20);

	//起動するゲーム番号  上段0～5,下段6～11
	Game_Num = Cursor_numX + (Cursor_numY * 6);
}

//カーソル描画
void CursorDraw()
{
	//描画　基準点は左上
	DrawGraph(Cursor_x, Cursor_y, CursorImage, TRUE);

	//タイトル　説明文
	DrawFormatStringToHandle(160, 20, 0xffffff, font_exp, Title_Text[Game_Num]);
}

//ゲームを起動
void StartUP(PROCESS_INFORMATION* process, STARTUPINFO* start)
{
	//Aボタンで実行
	if (g_KeyFlg & PAD_INPUT_A)
	{
		//0～10(画面上では11個)
		if (Game_Num < GAME_MAX)
		{
			//実行対象の.exe
			const char* Start_Game = Game_Pass[Game_Num];

			//実行対象の.exeが置いてある場所(ｶﾚﾝﾄﾃﾞｨﾚｸﾄﾘ)
			const char* Start_Current = Current_Pass[Game_Num];

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