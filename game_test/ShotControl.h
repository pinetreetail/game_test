#pragma once
#include "Vec2.h"

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

	void createShot(Vec2 pos);

private:
	static constexpr int ShotMax = 50;
	Shot shot[ShotMax];

	Vec2	m_pos;
};

