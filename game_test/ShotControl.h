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

	void createShot(const float x, const float y);

private:
	
	Shot shot;

	

	VECTOR	m_pos;
};

