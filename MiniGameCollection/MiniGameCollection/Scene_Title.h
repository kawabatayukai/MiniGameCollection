#pragma once
#include"AbstractScene.h"

//タイトル
class TitleScene : public AbstractScene
{
public:
	//コンストラクタ
	TitleScene();

	//デストラクタ
	~TitleScene();

	//更新
	void Update();

	//描画
	void Draw() const;

	//シーンの変更
	AbstractScene* ChangeScene() override;

private:
	int titleimage;   //タイトル画像
	int select_num;   //選択番号

	int se_start;     //スタート効果音
	int se_select;    //セレクト効果音
	int bgm_title;    //BGM
};