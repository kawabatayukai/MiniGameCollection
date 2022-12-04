#pragma once

//ゲームを起動するモノ
class ProcessStarter
{
public:
	ProcessStarter();   //コンストラクタ
	~ProcessStarter();  //デストラクタ

	//ゲームを起動する　　.exeまでのパス　、　カレントディレクトリ名（exeファイルが置いてある場所）
	void StartUp(const char* game_path, const char* current_path);

	//結果取得
	bool GetStartResult();

private:
	bool result;        //起動成功:TRUE　失敗:FALSE
};
