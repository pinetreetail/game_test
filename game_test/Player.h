#pragma once

#include "DxLib.h"

#include "ShotControl.h"

class ShotControl;

class Player
{
public:
	Player();
	virtual ~Player();

	void setShotControl(ShotControl* pSControl) { m_pSControl = pSControl; }

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

	// �\���ʒu
	VECTOR m_pos;

	ShotControl* m_pSControl;

	int stage;
};

