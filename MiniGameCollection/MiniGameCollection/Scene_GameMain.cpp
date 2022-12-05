#include"DxLib.h"
#include"Scene_GameMain.h"
#include"Game_Pass.h"

//最小化 アリ/ナシ
#define WINDOW_MINIMIZE

//コンストラクタ
GameMainScene::GameMainScene()
{
	// 選択画面読み込み
	homeImage = LoadGraph("images/testHome.png");

	//カーソルオブジェクト生成・コンストラクタ呼び出し
	obj_cursor = new Cursor();

	//起動クラスオブジェクト
	obj_starter = new ProcessStarter();

	//フォントの作成
	font_exp = CreateFontToHandle(NULL, 80, 3, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
}

//デストラクタ
GameMainScene::~GameMainScene()
{
	delete obj_cursor;
	delete obj_starter;
	DeleteFontToHandle(font_exp);
}

//更新
void GameMainScene::Update()
{
	//カーソル移動
	obj_cursor->CursorUpdate(keyflg);

	//ゲームを起動
	Process_Start(obj_cursor->GetGameNum());
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
void GameMainScene::Process_Start(int GameNum)
{
	//Aボタンで実行
	if (keyflg & PAD_INPUT_A && (Game_Path[GameNum] != ""))
	{
		//0～10(画面上では11個)
		if (GameNum < GAME_MAX)
		{
			//別のプロセスが起動していない時
			if (obj_starter->GetStartResult() == false)
			{

#ifdef WINDOW_MINIMIZE
				SetWindowMinimizeFlag(TRUE);   //元ウィンドウを最小化
#endif 

				//プロセスを起動
				obj_starter->StartUp(Game_Path[GameNum], Current_Path[GameNum]);
			}
		}
		else
		{
			//Game_Num == 11 (画面上では12個目)
			DrawString(0, 20, "HELP", 0xffffff);
		}
	}

#ifdef WINDOW_MINIMIZE
	SetWindowMinimizeFlag(FALSE);              //最小化を解除
#endif
}