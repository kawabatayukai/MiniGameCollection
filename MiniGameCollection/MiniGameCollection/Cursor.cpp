#include"Cursor.h"
#include"DxLib.h"

#define Cursor_INIT_X  40   //カーソル初期ｘ座標
#define Cursor_INIT_Y  100  //カーソル初期ｙ座標

//コンストラクタ
Cursor::Cursor()
{
	//画像読み込み
	image= LoadGraph("images/frame.png");
}

//更新（操作）
void Cursor::CursorUpdate(int keyflg)
{
	//右
	if (keyflg & PAD_INPUT_RIGHT)
	{
		Cursor_numX++;
		if (Cursor_numX > 5) Cursor_numX = 0;
	}

	//左
	if (keyflg & PAD_INPUT_LEFT)
	{
		Cursor_numX--;
		if (Cursor_numX < 0) Cursor_numX = 5;
	}

	//下
	if (keyflg & PAD_INPUT_DOWN)
	{
		Cursor_numY++;
		if (Cursor_numY > 1) Cursor_numY = 0;
	}

	//上
	if (keyflg & PAD_INPUT_UP)
	{
		Cursor_numY--;
		if (Cursor_numY < 0) Cursor_numY = 1;
	}

	//描画カーソルの座標を設定
	Cursor_x = Cursor_INIT_X + Cursor_numX * 200;
	Cursor_y = Cursor_INIT_Y + (Cursor_numY * 200) + (Cursor_numY == 0 ? 0 : 20);

	//起動するゲーム番号  上段0～5,下段6～11
	Game_Num = Cursor_numX + (Cursor_numY * 6);
}

//描画
void Cursor::CursorDraw() const
{
	//描画　基準点は左上
	DrawGraph(Cursor_x, Cursor_y, image, TRUE);
}