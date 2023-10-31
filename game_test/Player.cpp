#include "Player.h"


#include "DxLib.h"
#include "Pad.h"

Player::Player()	:
	X(250.0f),
	Y(100.0f),
	Speed(6.0f),
	stage(0),
	PlayerMotion(1),
	StopMotionNum(0),
	PlayerSize(40.0f)
{
	for (int i = 0; i < 5; i++)
	{
		PlayerImage1[i] = 0;
		PlayerImage2[i] = 0;
	}
}

Player::~Player()
{
}

void Player::init()
{
	// Player�@�̂̉摜�̓ǂݍ���
	LoadDivGraph("image/playe/ship1.png", 5, 5, 1, 16, 24, PlayerImage1);
	LoadDivGraph("image/playe/ship2.png", 5, 5, 1, 16, 24, PlayerImage2);
	
	stage = LoadGraph("image/stage/background.png");
}

void Player::end()
{
	for (int i = 0; i < 5; i++)
	{
		DeleteGraph(PlayerImage1[i]);
		DeleteGraph(PlayerImage2[i]);
	}

	DeleteGraph(stage);
}

void Player::update()
{
	// �p�b�h�̃A�b�v�f�[�g����
	Pad::update();


	// Player�@�̂̉΁H�̓���
	StopMotionNum++;
	if (StopMotionNum > 5)
	{
		StopMotionNum = 0;
		if (PlayerMotion == 1)	PlayerMotion = 0;
		else PlayerMotion = 1;
	}

	// Player�@�̂̈ړ�
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
	/*
	if (Pad::isPress(PAD_INPUT_2))
	{
		scenemain.createShot(X, Y);
	}
	*/
	

	// Player�@�̂���ʂ���o����߂�
	if (X < 0.0f)	X = 0.0f;
	if (X > 500.0f)	X = 500.0f;
	if (Y < 0.0f)	Y = 0.0f;
	if (Y > 800.0f)	Y = 800.0f;


	
}

void Player::draw()
{
	DrawBillboard3D(VGet(250.0f, 400.0f, 200.0f), 0.5f, 0.5f, 830.0f, 0.0f, stage, TRUE);


	// Player�@�̂̕\��
	if (PlayerMotion == 1)	DrawBillboard3D(VGet(X, Y, 100.0f), 0.5f, 0.5f, PlayerSize, 0.0f, PlayerImage1[2], TRUE);
	else  DrawBillboard3D(VGet(X, Y, 100.0f), 0.5f, 0.5f, PlayerSize, 0.0f, PlayerImage2[2], TRUE);

	
}
