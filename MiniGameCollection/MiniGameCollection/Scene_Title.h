#pragma once
#include"AbstractScene.h"

//タイトル
class TitleScene : public AbstractScene
{
public:
	//コンストラクタ
	TitleScene();

	//デストラクタ
	//~TitleScene();

	//更新
	void Update();

	//描画
	void Draw() const;

	//シーンの変更
	AbstractScene* ChangeScene() override;

};