#include"DxLib.h"
#include"Scene_Title.h"
#include"Scene_GameMain.h"

//コンストラクタ
TitleScene::TitleScene()
{
	//画像読み込み
	titleimage = LoadGraph("images/titletest.png");
	select_num = 0;

	//音声読み込み
	se_start = LoadSoundMem("sounds/se_title_button.wav");
	se_select = LoadSoundMem("sounds/se_cursor.wav");
}

//更新
void TitleScene::Update()
{
	//コントローラーで選択
	if (keyflg & PAD_INPUT_DOWN)
	{
		//効果音再生
		PlaySoundMem(se_select, DX_PLAYTYPE_BACK);

		select_num++;     //カーソル↓
		if (select_num > 1) select_num = 0;
	}
	if (keyflg & PAD_INPUT_UP)
	{
		//効果音再生
		PlaySoundMem(se_select, DX_PLAYTYPE_BACK);

		select_num--;     //カーソル↑
		if (select_num < 0) select_num = 1;
	}
}

//描画
void TitleScene::Draw() const
{
	//タイトル画像
	DrawGraph(0, 0, titleimage, FALSE);

	//選択カーソル描画
	DrawCircle(440, 520 + (select_num * 120), 20, 0x000000, TRUE);
}

//シーンの変更
AbstractScene* TitleScene::ChangeScene()
{
	//Aボタンでメインシーンへ
	if (keyflg & PAD_INPUT_A)
	{
		//効果音再生
		PlaySoundMem(se_start, DX_PLAYTYPE_BACK);

		switch (select_num)
		{
		case 0:
			//ゲームメインへ
			return dynamic_cast<AbstractScene*>(new GameMainScene());
			break;

		case 1:
			return nullptr;    //nullptr(ゲームを終了)
			break;

		default:
			break;
		}
	}

	//更新なし
	return this;
}