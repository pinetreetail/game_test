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

	void ShotStart(VECTOR pos);
	bool isExist() const { return exist; }

private:

	int ShotImage[4];

	//static constexpr int ShotMax = 50;

	bool exist;

	float ShotSaiz;
	float ShotSpeed;
	

	// •\Ž¦ˆÊ’u
	VECTOR	m_pos;

};

