#pragma once

#include "Vec2.h"


class SceneMain;

class Player
{
public:
	Player();
	virtual ~Player();

	void setMain(SceneMain* pMain) { m_pMain = pMain; }


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

	SceneMain* m_pMain;

	int stage;
};

