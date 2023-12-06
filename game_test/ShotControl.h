#pragma once
#include "DxLib.h"

#include "Shot.h"

class ShotControl
{
public:
	ShotControl();
	virtual ~ShotControl();

	void init();
	void end();
	void update();
	void draw();

	void createShot(VECTOR pos);

private:

	static constexpr int ShotMax = 50;

private:
	
	Shot shot[ShotMax];
};

