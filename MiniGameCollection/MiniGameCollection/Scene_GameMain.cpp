#include"DxLib.h"
#include"Scene_GameMain.h"
#include"Scene_Title.h"
#include"Game_Pass.h"

//最小化 アリ/ナシ
#define WINDOW_MINIMIZE

//コンストラクタ                               BGMをタイトルから引継ぎたい
GameMainScene::GameMainScene(int bgmHandle) : bgm_main(bgmHandle)
{
	// 選択画面読み込み
	homeImage = LoadGraph("images/testHome.png");

	//カーソルオブジェクト生成・コンストラクタ呼び出し
	obj_cursor = new Cursor();

	//起動クラスオブジェクト
	obj_starter = new ProcessStarter();

	//フォントの作成
	font_exp = CreateFontToHandle(NULL, 80, 1, DX_FONTTYPE_ANTIALIASING_8X8);

	//音声読み込み
	se_start = LoadSoundMem("sounds/se_main_button.wav");

	//音量
	ChangeVolumeSoundMem(150, bgm_main);
}

//デストラクタ
GameMainScene::~GameMainScene()
{
	DeleteSoundMem(se_start);
	DeleteSoundMem(bgm_main);
	DeleteFontToHandle(font_exp);
}

//更新
void GameMainScene::Update()
{
	//BGM
	if (bgm_main != 0)
	{
		if (CheckSoundMem(bgm_main) == 0) PlaySoundMem(bgm_main, DX_PLAYTYPE_LOOP);
	}

	//カーソル移動
	obj_cursor->CursorUpdate(keyflg);

	//ゲームを起動
	Process_Start(obj_cursor->GetGameNum());
}

//描画
void GameMainScene::Draw() const
{
	//ホーム画面の描画
	DrawGraph(0, 0, homeImage, TRUE);

	//カーソルの描画
	obj_cursor->CursorDraw();

	//ゲームタイトル 説明等
	DrawFormatStringToHandle(200, 540, 0x000000, font_exp, Title_Text[obj_cursor->GetGameNum()]);
}

//シーンの変更
AbstractScene* GameMainScene::ChangeScene()
{
	//11番目(画面上は12番目)でAボタンでタイトルへ
	if (keyflg & PAD_INPUT_A && obj_cursor->GetGameNum() == 11)
	{
		//タイトルへ
		return dynamic_cast<AbstractScene*>(new TitleScene());
	}

	//更新なし
	return this;
}

//ゲームを起動
void GameMainScene::Process_Start(int GameNum)
{
	//Aボタンで実行
	if (keyflg & PAD_INPUT_A && (Game_Path[GameNum] != ""))
	{

		//0〜10(画面上では11個)
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