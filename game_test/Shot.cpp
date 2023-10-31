#include "Shot.h"

#include "DxLib.h"

Shot::Shot()	:
	X(0.0f),
	Y(0.0f),
	exist(false),
	ShotSpeed(10.0f)
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
	if (exist = true)
	{
		Y -= ShotSpeed;

		if (Y < 800.0f)
		{
			exist = false;
		}
	}

}

void Shot::draw()
{
	if (exist == true)
	{
		DrawBillboard3D(VGet(X, Y, 100.0f), 0.5f, 0.5f, 30.0f, 0.0f, ShotImage[2], true);
	}
}

void Shot::ShotStart(float x, float y)
{
	exist = true;

	X = x;
	Y = y;
}

