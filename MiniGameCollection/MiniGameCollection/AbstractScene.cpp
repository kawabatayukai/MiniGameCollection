#include"AbstractScene.h"

int AbstractScene::keyflg;
int AbstractScene::nowkey;

//�L�[���͒l���擾
void AbstractScene::SetKeyFlg(int keyflg, int nowkey)
{
	this->keyflg = keyflg;
	this->nowkey = nowkey;
}