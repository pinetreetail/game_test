#pragma once
#include "SceneBase.h"
#include "Player.h"
#include "Shot.h"



class SceneMain : public SceneBase
{
public:
	SceneMain();

	virtual ~SceneMain();


	virtual void init() override;
	virtual void end() override;

	virtual SceneBase* update() override;
	virtual void draw() override;

	void createShot(float x,float y);

private:

	static constexpr int ShotMax = 50;

	Player player;
	Shot shot[ShotMax];

};