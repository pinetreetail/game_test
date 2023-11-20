#pragma once

#include "Vec2.h"


class ShotControl;

class Player
{
public:
	Player();
	virtual ~Player();


	void init();
	void end();

	void update();
	void draw();

	
private:

	int PlayerImage1[5];
	int PlayerImage2[5];
	int PlayerMotion;
	int StopMotionNum;

	float PlayerSize;
	float Speed;

	// •\Ž¦ˆÊ’u
	Vec2 m_pos;

	ShotControl* m_pShotControl;

	int stage;
};

