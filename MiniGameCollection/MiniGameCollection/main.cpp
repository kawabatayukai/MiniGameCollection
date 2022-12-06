#include"DxLib.h"

#include"SceneManager.h"
#include"Scene_Title.h"


/*　　変数　　*/
int g_OldKey;      // 前回の入力キー 
int g_NowKey;      // 今回の入力キー 
int g_KeyFlg;      // 入力キー情報


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("TEST");              //タイトルを設定
	ChangeWindowMode(TRUE);                 //ウィンドウモードで起動
	//SetWindowSize(1280, 720);
	SetGraphMode(1280, 720, 32);            //ウィンドウサイズを設定
	if (DxLib_Init() == -1) { return -1; }  //Dxﾗｲﾌﾞﾗﾘ初期処理

	//シーンマネージャー     　　　　　　　　　　　　　　　タイトルを設定
	SceneManager sceneMng(dynamic_cast<AbstractScene*>(new TitleScene()));

	SetDrawScreen(DX_SCREEN_BACK);         //描画先画面を裏にする

	while (ProcessMessage() == 0 && !(g_NowKey & PAD_INPUT_9) && !(g_NowKey & PAD_INPUT_7))
	{
		//キー入力取得 
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

		// 画面の初期化 
		ClearDrawScreen();

		sceneMng.SetKeyFlg(g_KeyFlg, g_NowKey);  //キー入力
		sceneMng.Update();     //更新
		sceneMng.Draw();       //描画

		//シーンの変更   ENDの場合　nullptr
		if (sceneMng.ChangeScene() == nullptr)
		{
			DxLib_End();  //DxLib終了処理
			return 0;
		}

		ScreenFlip();

	}
	DxLib_End();

	return 0;
}
