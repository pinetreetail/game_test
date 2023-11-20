#pragma once
#include "SceneBase.h"
#include "Vec2.h"



class Player;
class ShotControl;

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

	static constexpr int ShotMax = 50;

	Player* m_pPlayer;
	ShotControl* m_pShotControl;

};