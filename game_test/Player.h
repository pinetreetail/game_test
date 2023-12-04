#pragma once

#include "DxLib.h"

#include "ShotControl.h"

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

	int stopnum;

	// •\Ž¦ˆÊ’u
	VECTOR m_pos;

	ShotControl shotcontrol;

	int stage;
};

