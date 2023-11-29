#include "Shot.h"
#include "game.h"
#include "DxLib.h"

Shot::Shot()	:
	m_pos(),
	exist(false),
	ShotSpeed(10.0f),
	ShotSaiz(30.0f)
{
	for (int i = 0; i < 4; i++)
	{
		ShotImage[i] = 0;
	}
}

Shot::~Shot()
{
}

void Shot::init()
{
	LoadDivGraph("image/shot/laser-bolts.png", 4, 2, 2, 16, 16, ShotImage);
}

void Shot::end()
{
	for (int i = 0; i < 4; i++)
	{
		DeleteGraph(ShotImage[i]);
	}
}

void Shot::update()
{
	if (exist == true)
	{
		m_pos.y -= ShotSpeed;
		DrawString(0, 0, "ƒƒCƒ“‰æ–Ê", GetColor(255, 255, 255));
		if (m_pos.y > Game::kScreenHeight + ShotSaiz)
		{
			exist = false;
		}
	}

}

void Shot::draw()
{
	if (exist == true)
	{
		DrawBillboard3D(VGet(m_pos.x, m_pos.y, 100.0f), 0.5f, 0.5f, ShotSaiz, 0.0f, ShotImage[2], true);
	}
}

void Shot::ShotStart(Vec2 pos)
{
	exist = true;
	m_pos = pos;
}

