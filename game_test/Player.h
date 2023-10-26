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

	int GrHandle[10];

	float X;
	float Y;

	float Speed;
};

