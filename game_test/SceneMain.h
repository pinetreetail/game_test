#pragma once
#include "SceneBase.h"
#include "Vec2.h"

#include "Player.h"
#include "ShotControl.h"

class SceneMain : public SceneBase
{
public:
	SceneMain();

	virtual ~SceneMain();


	virtual void init() override;
	virtual void end() override;

	virtual SceneBase* update() override;
	virtual void draw() override;

	

private:

	Player player;
	ShotControl shotcontrol;

};