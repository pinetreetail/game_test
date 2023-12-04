#include "Shot.h"
#include "game.h"
#include "DxLib.h"

Shot::Shot()	:
	m_pos(),
	ShotSpeed(1.5f),
	ShotSaiz(3.0f)
{
	for (int i = 0; i < 4; i++)
	{
		ShotImage[i] = 0;
	}
	for (int i = 0; i < ShotMax; i++)
	{
		shotX[i] = 0.0f;
		shotY[i] = 0.0f;
		exist[i] = false;
	}
}

Shot::~Shot()
{
}

void Shot::init()
{
	LoadDivGraph("image/shot/laser-bolts.png", 4, 2, 2, 16, 16, ShotImage);

	m_pos.x = 0.0f;
	m_pos.y = 0.0f;
	m_pos.z = 0.0f;
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
	for (int i = 0; i < ShotMax; i++)
	{
		if (exist[i] = true)
		{
			m_pos.y -= ShotSpeed;

			if (m_pos.y > 54.0f + ShotSaiz)
			{
				exist[i] = false;
				shotX[i] = 0.0f;
				shotY[i] = 0.0f;
			}
		}
	}
	

}

void Shot::draw()
{
	for (int i = 0; i < ShotMax; i++)
	{
		if (exist[i] = true)
		{
			DrawBillboard3D(VGet(shotX[i], shotY[i], 0.0f), 0.5f, 0.5f, ShotSaiz, 0.0f, ShotImage[2], true);
		}
	}
	
}

void Shot::ShotStart(const float x, const float y)
{
	exist[i] = true;
	shotX[i] = 0.0f;
	shotY[i] = 0.0f;
}

bool Shot::isExist()
{
	return false;
}

