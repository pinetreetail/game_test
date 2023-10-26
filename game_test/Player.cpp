#include "Player.h"

#include "DxLib.h"
#include "Pad.h"

Player::Player()	:
	X(250.0f),
	Y(100.0f),
	Speed(6.0f)
{
	for (int i = 0; i < 10; i++)
	{
		GrHandle[i] = 0;
	}
}

Player::~Player()
{
}

void Player::init()
{
	LoadDivGraph("image/playe/ship.png", 10, 5, 2, 16, 24, GrHandle);
}

void Player::end()
{
	for (int i = 0; i < 10; i++)
	{
		DeleteGraph(GrHandle[i]);
	}
}

void Player::update()
{
	// �p�b�h�̃A�b�v�f�[�g����
	Pad::update();

	

	if (Pad::isPress(PAD_INPUT_LEFT))
	{
		// ���ֈړ�
		X -= Speed;
	}
	if (Pad::isPress(PAD_INPUT_RIGHT))
	{
		// �E�ֈړ�
		X += Speed;
	}
	if (Pad::isPress(PAD_INPUT_DOWN))
	{
		// ���ֈړ�
		Y -= Speed;
	}
	if (Pad::isPress(PAD_INPUT_UP))
	{
		// �E�ֈړ�
		Y += Speed;
	}


	//	��ʂ���o�Ȃ�
	if (X < 0.0f)	X = 0.0f;
	if (X > 500.0f)	X = 500.0f;
	if (Y < 0.0f)	Y = 0.0f;
	if (Y > 800.0f)	Y = 800.0f;


	
}

void Player::draw()
{
	DrawBillboard3D(VGet(X, Y, 100.0f), 0.5f, 0.5f, 40.0f, 0.0f, GrHandle[2], TRUE);
}
