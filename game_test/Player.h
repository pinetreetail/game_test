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

	int ShotImage[4];	//


	float PlayerSize;
	float Speed;

	const int stopmax;
	int stopnum;

	// �\���ʒu
	Vec2 m_pos;

	ShotControl* m_pShotControl;

	int stage;
};

