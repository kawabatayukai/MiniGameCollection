#pragma once
#include"AbstractScene.h"
#include"Cursor.h"
#include"ProcessStarter.h"

//ゲームメイン
class GameMainScene : public AbstractScene
{
public:
	//コンストラクタ
	GameMainScene();

	//デストラクタ
	~GameMainScene();

	//更新
	void Update();

	//描画
	void Draw() const;

	//シーンの変更
	AbstractScene* ChangeScene() override;

	//ゲームを起動
	void Process_Start(int GameNum = 0);

private:
	Cursor* obj_cursor;              //カーソルオブジェクト
	ProcessStarter* obj_starter;     //起動クラスオブジェクト

	int homeImage;                   //ホーム画面画像
	int font_exp;                    //画面上部の説明文用フォント

	int se_start;                    //決定ボタン音
};
