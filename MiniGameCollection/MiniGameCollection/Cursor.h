#pragma once

//�J�[�\��
class Cursor
{
public:
	Cursor();                        //�R���X�g���N�^

	void CursorUpdate(int keyflg);   //�X�V
	void CursorDraw() const;         //�`��

	//�N������Q�[���ԍ��擾
	int GetGameNum() const { return Game_Num; } 

private:
	int image;                       //�J�[�\���摜

	int Cursor_x = 0;                //�J�[�\�������W
	int Cursor_y = 0;                //�J�[�\�������W
	int Cursor_numX = 0;             //���݁Z�Ԗځ@������
	int Cursor_numY = 0;             //���݁Z�Ԗځ@������

	int Game_Num = 0;                //�N������Q�[��
};