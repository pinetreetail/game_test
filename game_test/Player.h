#pragma once

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
	int stage;

	float X;
	float Y;

	float Speed;
};

