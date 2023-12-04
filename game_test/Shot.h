#pragma once
#include "DxLib.h"

class Shot
{
public:
	Shot();
	virtual ~Shot();

	void init();
	void end();
	void update();
	void draw();

	void ShotStart(const float x, const float y);
	bool isExist();

private:

	int ShotImage[4];

	static constexpr int ShotMax = 50;

	float shotX[ShotMax];
	float shotY[ShotMax];
	bool exist[ShotMax];

	float ShotSaiz;
	float ShotSpeed;
	

	// •\Ž¦ˆÊ’u
	VECTOR	m_pos;

};

