#include"AbstractScene.h"

int AbstractScene::keyflg;
int AbstractScene::nowkey;

//キー入力値を取得
void AbstractScene::SetKeyFlg(int keyflg, int nowkey)
{
	this->keyflg = keyflg;
	this->nowkey = nowkey;
}