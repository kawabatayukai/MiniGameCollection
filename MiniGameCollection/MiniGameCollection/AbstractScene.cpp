#include"AbstractScene.h"

int AbstractScene::keyflg;
int AbstractScene::nowkey;

//ƒL[“ü—Í’l‚ðŽæ“¾
void AbstractScene::SetKeyFlg(int keyflg, int nowkey)
{
	this->keyflg = keyflg;
	this->nowkey = nowkey;
}