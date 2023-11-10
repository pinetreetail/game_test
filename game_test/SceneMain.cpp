#include "DxLib.h"

#include "SceneMain.h"
#include "SceneTitle.h"
#include "Player.h"

#include "Pad.h"

SceneMain::SceneMain()	:
	m_pPlayer(nullptr)
{
	m_pPlayer = new Player;
}

SceneMain::~SceneMain()
{
	m_pPlayer = nullptr;
	delete m_pPlayer;
}

void SceneMain::init()
{
	m_pPlayer->init();


	for (auto& shot : shot)
	{
		shot->init();
	}
	
}

void SceneMain::end()
{
	m_pPlayer->end();

	for (auto& shot : shot)
	{
		shot->end();
	}
}

SceneBase* SceneMain::update()
{
	// パッドのアップデート処理
	Pad::update();

	if (Pad::isTrigger(PAD_INPUT_1))
	{
		return (new SceneTitle);
	}

	m_pPlayer->update();

	for (auto& shot : shot)
	{
		shot->update();
	}
	




	return this;
}

void SceneMain::draw()
{
	//DrawString(0, 0, "メイン画面", GetColor(255, 255, 255));

	m_pPlayer->draw();
	for (auto& shot : shot)
	{
		shot->draw();
	}
	
}

void SceneMain::createShot(Vec2 pos)
{
	for (auto& shot : shot)
	{
		if (shot->isExist() == false)
		{
			shot->ShotStart(pos);
		}
	}
}
