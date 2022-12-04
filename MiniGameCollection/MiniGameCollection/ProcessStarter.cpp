#include<Windows.h>
#include"ProcessStarter.h"

//コンストラクタ
ProcessStarter::ProcessStarter() : result(FALSE)
{
}

//デストラクタ
ProcessStarter::~ProcessStarter(){}

//ゲームを起動する　　.exeまでのパス　、　カレントディレクトリ名（exeファイルが置いてある場所）
void ProcessStarter::StartUp(const char* game_path, const char* current_path)
{
	result = TRUE;   //起動開始の合図

	PROCESS_INFORMATION process_info = {};           //CreateProcessによって生成されるプロセスの情報を格納する構造体
	STARTUPINFO start_info = {};                     //起動するプロセスの表示状態を格納する構造体

	ZeroMemory(&process_info, sizeof(process_info)); //process_infoを初期化
	ZeroMemory(&start_info, sizeof(start_info));     //start_infoを初期化
	start_info.cb = sizeof(start_info);              //メンバcb（構造体サイズ）を設定

	//スタートアップ情報を得る
	GetStartupInfo(&start_info);

	//元ウィンドウが見えない状態で起動させる
	start_info.dwFlags = STARTF_USESHOWWINDOW;       //"wShowWindow"を有効化する
	start_info.wShowWindow = SW_HIDE;                //元ウィンドウを非アクティブに、他のウィンドウをアクティブにする

	//起動    
	result = CreateProcess(game_path, NULL, NULL, NULL, FALSE, NULL, NULL, current_path, &start_info, &process_info);

	//実行対象が終了するまで待つ
	WaitForSingleObject(process_info.hProcess, INFINITE);

	//ハンドル（プロセス（実行対象）へのポインタ?）を閉じる  
	CloseHandle(process_info.hProcess);              
	CloseHandle(process_info.hThread); 

	//終了の合図
	result = FALSE;
}

//結果を取得
bool ProcessStarter::GetStartResult() { return result; }