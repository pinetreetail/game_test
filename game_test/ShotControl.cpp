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
	shot.init();
	
}

void ShotControl::end()
{
	shot.end();
	
}

void ShotControl::update()
{
	if (shot.isExist() == true)
	{
		shot.update();
	}

	

	
	
}

void ShotControl::draw()
{
	shot.draw();
	//DrawFormatString(0, 75, GetColor(255, 255, 255), "•\Ž¦‚µ‚Ü‚·");
	
}

void ShotControl::createShot(const float x, const float y)
{
	if (shot.isExist() == false)	
	{
		shot.ShotStart(x, y);
		
	}
	
}
