#pragma once
#include<Windows.h>
#include"AbstractScene.h"
#include"Cursor.h"

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
	void StartUp(PROCESS_INFORMATION* process, STARTUPINFO* start, int GameNum = 0);

private:
	Cursor* obj_cursor;    //カーソルオブジェクト

	int homeImage;                   //ホーム画面画像
	int font_exp;                    //画面上部の説明文用フォント

	PROCESS_INFORMATION process_info;      //CreateProcessによって生成されるプロセスの情報
	STARTUPINFO start_info;                //スタートアップの情報（表示情報） 
};
