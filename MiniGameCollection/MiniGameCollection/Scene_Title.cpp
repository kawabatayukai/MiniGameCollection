#include"DxLib.h"
#include"Scene_Title.h"
#include"Scene_GameMain.h"

//コンストラクタ
TitleScene::TitleScene()
{
}

//更新
void TitleScene::Update()
{

}

//描画
void TitleScene::Draw() const
{
	SetFontSize(40);
	DrawString(100, 0, "タイトル", 0xffffff);
	DrawString(100, 300, "Aボタンでスタート", 0xffffff);
	SetFontSize(DX_FONTTYPE_NORMAL);
}

//シーンの変更
AbstractScene* TitleScene::ChangeScene()
{
	//Aボタンでメインシーンへ
	if (keyflg & PAD_INPUT_A)
	{
		return dynamic_cast<AbstractScene*>(new GameMainScene());
	}

	//更新なし
	return this;
}