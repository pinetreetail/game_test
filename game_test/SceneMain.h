#pragma once
#include "SceneBase.h"

#include "Shot.h"

class Player;

class SceneMain : public SceneBase
{
public:
	SceneMain();

	virtual ~SceneMain();


	virtual void init() override;
	virtual void end() override;

	virtual SceneBase* update() override;
	virtual void draw() override;

	void createShot(Vec2 pos);

private:

	static constexpr int ShotMax = 50;

	Player* m_pPlayer;
	Shot* shot[ShotMax];

};