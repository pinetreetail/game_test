#include "Player.h"
#include "ShotControl.h"
#include "DxLib.h"
#include "Pad.h"

Player::Player()	:
	m_pShotControl(nullptr),
	m_pos(),
	Speed(6.0f),
	stage(0),
	PlayerMotion(1),
	StopMotionNum(0),
	PlayerSize(40.0f)
{
	m_pShotControl = new ShotControl;

	for (int i = 0; i < 5; i++)
	{
		PlayerImage1[i] = 0;
		PlayerImage2[i] = 0;
	}
}

Player::~Player()
{
	m_pShotControl = nullptr;
	delete m_pShotControl;
}

void Player::init()
{
	// Player�@�̂̉摜�̓ǂݍ���
	LoadDivGraph("image/player/player1.png", 5, 5, 1, 16, 24, PlayerImage1);

	LoadDivGraph("image/player/player2.png", 5, 5, 1, 16, 24, PlayerImage2);
	
	stage = LoadGraph("image/stage/background.png");

	m_pos.x = 250.0f;
	m_pos.y = 100.0f;
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
		m_pos.x -= Speed;
	}
	if (Pad::isPress(PAD_INPUT_RIGHT))
	{
		// �E�ֈړ�
		m_pos.x += Speed;
	}
	if (Pad::isPress(PAD_INPUT_DOWN))
	{
		// ���ֈړ�
		m_pos.y -= Speed;
	}
	if (Pad::isPress(PAD_INPUT_UP))
	{
		// �E�ֈړ�
		m_pos.y += Speed;
	}
	if (Pad::isPress(PAD_INPUT_2))
	{
		m_pShotControl->createShot(m_pos);
	}
	
	
	

	// Player�@�̂���ʂ���o����߂�
	if (m_pos.x < 0.0f)	m_pos.x = 0.0f;
	if (m_pos.x > 500.0f)	m_pos.x = 500.0f;
	if (m_pos.y < 0.0f)	m_pos.y = 0.0f;
	if (m_pos.y > 800.0f)	m_pos.y = 800.0f;


	
}

void Player::draw()
{
	DrawBillboard3D(VGet(250.0f, 400.0f, 200.0f), 0.5f, 0.5f, 830.0f, 0.0f, stage, TRUE);


	// Player�@�̂̕\��
	if (PlayerMotion == 1)	DrawBillboard3D(VGet(m_pos.x, m_pos.y, 100.0f), 0.5f, 0.5f, PlayerSize, 0.0f, PlayerImage1[2], TRUE);
	else  DrawBillboard3D(VGet(m_pos.x, m_pos.y, 100.0f), 0.5f, 0.5f, PlayerSize, 0.0f, PlayerImage2[2], TRUE);

	if (Pad::isPress(PAD_INPUT_2))
	{
		DrawString(0, 0, "���C�����", GetColor(255, 255, 255));
	}
}
