#include "Player.h"
#include "ShotControl.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	constexpr float Speed = 0.75f;
	constexpr int stopmax = 60;

	float playerX = 0.0f;
	float playerY = 0.0f;
}

Player::Player()	:
	m_pSControl(nullptr),
	m_pos(),
	stage(0),
	PlayerMotion(1),
	StopMotionNum(0),
	PlayerSize(5.0f),
	stopnum(0)
{

	for (int i = 0; i < 5; i++)
	{
		PlayerImage1[i] = 0;
		PlayerImage2[i] = 0;
	}


	for (int i = 0; i < 4; i++)
	{
		ShotImage[i] = 0;
	}		//
}

Player::~Player()
{
}

void Player::init()
{
	// Player機体の画像の読み込み
	LoadDivGraph("image/player/player1.png", 5, 5, 1, 16, 24, PlayerImage1);

	LoadDivGraph("image/player/player2.png", 5, 5, 1, 16, 24, PlayerImage2);
	

	stage = LoadGraph("image/stage/background.png");
	LoadDivGraph("image/shot/laser-bolts.png", 4, 2, 2, 16, 16, ShotImage);	//


	m_pos.x = 0.0f;
	m_pos.y = 0.0f;
	m_pos.z = 0.0f;
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
	// パッドのアップデート処理
	Pad::update();


	// Player機体の火？の動き
	StopMotionNum++;
	if (StopMotionNum > 5)
	{
		StopMotionNum = 0;
		if (PlayerMotion == 1)	PlayerMotion = 0;
		else PlayerMotion = 1;
	}

	// Player機体の移動
	if (Pad::isPress(PAD_INPUT_LEFT))
	{
		// 左へ移動
		m_pos.x -= Speed;
	}
	if (Pad::isPress(PAD_INPUT_RIGHT))
	{
		// 右へ移動
		m_pos.x += Speed;
	}
	if (Pad::isPress(PAD_INPUT_DOWN))
	{
		// 左へ移動
		m_pos.y -= Speed;
	}
	if (Pad::isPress(PAD_INPUT_UP))
	{
		// 右へ移動
		m_pos.y += Speed;
	}


	if (stopnum < stopmax)	stopnum++;
	if (Pad::isPress(PAD_INPUT_2))
	{
		if (stopnum == stopmax)
		{
		

			m_pSControl->createShot(m_pos);
			stopnum = 0;
		}
	}
	
	
	

	// Player機体が画面から出たら戻す	
	if (m_pos.x < -33.0f)	m_pos.x = -33.0f;
	if (m_pos.x > 33.0f)	m_pos.x = 33.0f;
	if (m_pos.y < -54.0f)	m_pos.y = -54.0f;
	if (m_pos.y > 54.0f)	m_pos.y = 54.0f;


	
}

void Player::draw()
{
	DrawBillboard3D(VGet(0.0f, 0.0f, 100.0f), 0.5f, 0.5f, 200.0f, 0.0f, stage, TRUE);
	DrawBillboard3D(VGet(0, 0, 100.0f), 0.5f, 0.5f, 60.0f, 0.0f, ShotImage[2], TRUE);

	DrawFormatString(0, 0, GetColor(255, 255, 255), "player X %f", m_pos.x);
	DrawFormatString(0, 25, GetColor(255, 255, 255), "player Y %f", m_pos.y);
	DrawFormatString(0, 50, GetColor(255, 255, 255), " %d", stopnum);

	// Player機体の表示
	if (PlayerMotion == 1)	DrawBillboard3D(VGet(m_pos.x, m_pos.y, 0.0f), 0.5f, 0.5f, PlayerSize, 0.0f, PlayerImage1[2], TRUE);
	else  DrawBillboard3D(VGet(m_pos.x, m_pos.y, 0.0f), 0.5f, 0.5f, PlayerSize, 0.0f, PlayerImage2[2], TRUE);

	/*if (Pad::isPress(PAD_INPUT_2))
	{
		
	}*/
}
