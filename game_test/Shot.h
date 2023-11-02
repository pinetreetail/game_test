#pragma once
#include "Vec2.h"

class Shot
{
public:
	Shot();
	virtual ~Shot();

	void init();
	void end();
	void update();
	void draw();

	void ShotStart(Vec2 pos);
	bool isExist()	const { return exist; }

private:

	int ShotImage[4];

	bool exist;

	float ShotSpeed;

	// •\Ž¦ˆÊ’u
	Vec2	m_pos;

};

