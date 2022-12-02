#pragma once

//���ۃV�[���N���X
class AbstractScene
{
public:
    // �f�X�g���N�^
    virtual ~AbstractScene() {};

    /**�@�������z�֐��@**/

    //�`��ȊO�̍X�V����������
    virtual void Update() = 0;

    //�`��Ɋւ��邱�Ƃ���������
    virtual void Draw() const = 0;

    //�V�[���̕ύX����
    virtual AbstractScene* ChangeScene() = 0;

    //�L�[���͂��擾����
    void SetKeyFlg(int keyflg, int nowkey = 0);

protected:
    static int keyflg;  //�L�[���͒l
    static int nowkey;  //�L�[���͒l

};

