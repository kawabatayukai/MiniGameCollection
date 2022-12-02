#include"Cursor.h"
#include"DxLib.h"

#define Cursor_INIT_X  40   //�J�[�\�����������W
#define Cursor_INIT_Y  100  //�J�[�\�����������W

//�R���X�g���N�^
Cursor::Cursor()
{
	//�摜�ǂݍ���
	image= LoadGraph("images/frame.png");
}

//�X�V�i����j
void Cursor::CursorUpdate(int keyflg)
{
	//�E
	if (keyflg & PAD_INPUT_RIGHT)
	{
		Cursor_numX++;
		if (Cursor_numX > 5) Cursor_numX = 0;
	}

	//��
	if (keyflg & PAD_INPUT_LEFT)
	{
		Cursor_numX--;
		if (Cursor_numX < 0) Cursor_numX = 5;
	}

	//��
	if (keyflg & PAD_INPUT_DOWN)
	{
		Cursor_numY++;
		if (Cursor_numY > 1) Cursor_numY = 0;
	}

	//��
	if (keyflg & PAD_INPUT_UP)
	{
		Cursor_numY--;
		if (Cursor_numY < 0) Cursor_numY = 1;
	}

	//�`��J�[�\���̍��W��ݒ�
	Cursor_x = Cursor_INIT_X + Cursor_numX * 200;
	Cursor_y = Cursor_INIT_Y + (Cursor_numY * 200) + (Cursor_numY == 0 ? 0 : 20);

	//�N������Q�[���ԍ�  ��i0�`5,���i6�`11
	Game_Num = Cursor_numX + (Cursor_numY * 6);
}

//�`��
void Cursor::CursorDraw() const
{
	//�`��@��_�͍���
	DrawGraph(Cursor_x, Cursor_y, image, TRUE);
}