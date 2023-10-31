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

	void ShotStart(float x, float y);
	bool isExist()	const { return exist; }

private:

	int ShotImage[4];

	bool exist;

	float X;
	float Y;
	float ShotSpeed;

};

