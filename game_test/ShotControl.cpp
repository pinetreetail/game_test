#include "ShotControl.h"

ShotControl::ShotControl()	:
	stopmax(10),
	stopnum(0)
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

	stopnum++;
	if (stopnum > stopmax) stopnum = stopmax;
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
		if (shot.isExist() == false && stopnum == stopmax)
		{
			shot.ShotStart(pos);
			stopnum = 0;
		}
	}
}
