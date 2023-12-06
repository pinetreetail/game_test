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
	
	//DrawFormatString(0, 75, GetColor(255, 255, 255), "•\Ž¦‚µ‚Ü‚·");
	
}

void ShotControl::createShot(VECTOR pos)
{
	for (auto& shot : shot)
	{
		if (shot.isExist() == false)
		{
			shot.ShotStart(pos);

			return;
		}
		
	}
}
