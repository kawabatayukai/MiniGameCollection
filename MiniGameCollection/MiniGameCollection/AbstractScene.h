#pragma once

//抽象シーンクラス
class AbstractScene
{
public:
    // デストラクタ
    virtual ~AbstractScene() {};

    /**　純粋仮想関数　**/

    //描画以外の更新を実装する
    virtual void Update() = 0;

    //描画に関することを実装する
    virtual void Draw() const = 0;

    //シーンの変更処理
    virtual AbstractScene* ChangeScene() = 0;

    //キー入力を取得する
    void SetKeyFlg(int keyflg, int nowkey = 0);

protected:
    static int keyflg;  //キー入力値
    static int nowkey;  //キー入力値

};

