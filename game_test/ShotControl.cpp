#include "ShotControl.h"

#include "DxLib.h"

ShotControl::ShotControl()	
{
}

ShotControl::~ShotControl()
{
}

void ShotControl::init()
{
	for (auto& shot : shot)
	{
		shot.init();
	}
}

void ShotControl::end()
{
	for (auto& shot : shot)
	{
		shot.end();
	}
}

void ShotControl::update()
{

	for (auto& shot : shot)
	{
		shot.update();
	}

	
	
}

void ShotControl::draw()
{
	

	for (auto& shot : shot)
	{
		shot.draw();
	}
}

void ShotControl::createShot(Vec2 pos)
{
	for (auto& shot : shot)
	{
		if (shot.isExist() == false)	
		{
			shot.ShotStart(pos);
			break;
		}
	}

	for (auto& shot : shot)
	{
		if (shot.isExist() == true)
		{
			DrawFormatString(0, 75, GetColor(255, 255, 255), "•\Ž¦‚µ‚Ü‚·");
		}
	}
}
