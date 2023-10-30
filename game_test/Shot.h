#pragma once
class Shot
{
public:
	Shot();
	virtual ~Shot();

	void init();
	void end();
	void update();
	void draw();

private:

	int ShotImage[4];

	bool exist;

	float X;
	float Y;
	float ShotSpeed;

};

