#pragma once

//カーソル
class Cursor
{
public:
	Cursor();                        //コンストラクタ

	void CursorUpdate(int keyflg);   //更新
	void CursorDraw() const;         //描画

	//起動するゲーム番号取得
	int GetGameNum() const { return Game_Num; } 

private:
	int image;                       //カーソル画像

	int Cursor_x = 0;                //カーソルｘ座標
	int Cursor_y = 0;                //カーソルｙ座標
	int Cursor_numX = 0;             //現在〇番目　ｘ方向
	int Cursor_numY = 0;             //現在〇番目　ｙ方向

	int Game_Num = 0;                //起動するゲーム
};