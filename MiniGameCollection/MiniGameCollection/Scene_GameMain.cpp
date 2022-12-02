#include"DxLib.h"
#include"Scene_GameMain.h"
#include"Game_Pass.h"

//コンストラクタ
GameMainScene::GameMainScene()
{
	// 選択画面読み込み
	homeImage = LoadGraph("images/testHome.png");

	//カーソルオブジェクト生成・コンストラクタ呼び出し
	obj_cursor = new Cursor();

	//フォントの作成
	font_exp = CreateFontToHandle(NULL, 80, 3, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);

	ZeroMemory(&start_info, sizeof(start_info));    //start_info(STARTUPINFO構造体型)を初期化
	start_info.cb = sizeof(start_info);             //メンバcb（構造体サイズ）を設定
}

//デストラクタ
GameMainScene::~GameMainScene()
{
	DeleteFontToHandle(font_exp);
}

//更新
void GameMainScene::Update()
{
	//カーソル移動
	obj_cursor->CursorUpdate(keyflg);

	//ゲームを起動
	StartUp(&process_info, &start_info, obj_cursor->GetGameNum());
}

//描画
void GameMainScene::Draw() const
{
	DrawString(0, 0, "GameMainScene", 0xffffff);

	//ホーム画面の描画
	DrawGraph(0, 0, homeImage, TRUE);

	//カーソルの描画
	obj_cursor->CursorDraw();

	//ゲームタイトル 説明等
	DrawFormatStringToHandle(160, 20, 0xffffff, font_exp, Title_Text[obj_cursor->GetGameNum()]);
}

//シーンの変更
AbstractScene* GameMainScene::ChangeScene()
{
	//更新なし
	return this;
}

//ゲームを起動
void GameMainScene::StartUp(PROCESS_INFORMATION* process, STARTUPINFO* start, int GameNum)
{
	//Aボタンで実行
	if (keyflg & PAD_INPUT_A)
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