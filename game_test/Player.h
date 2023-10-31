#pragma once

//#include "SceneMain.h"

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

	float X;
	float Y;
	float PlayerSize;
	float Speed;

	//SceneMain scenemain;

	int stage;
};

