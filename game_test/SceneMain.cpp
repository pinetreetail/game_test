#include "DxLib.h"

#include "SceneMain.h"
#include "SceneTitle.h"
#include "Player.h"
#include "ShotControl.h"
#include "Pad.h"

SceneMain::SceneMain()	:
	m_pPlayer(nullptr),
	m_pShotControl(nullptr)
{
	m_pPlayer = new Player;
	m_pShotControl = new ShotControl;
}

SceneMain::~SceneMain()
{
	m_pPlayer = nullptr;
	delete m_pPlayer;
	m_pShotControl = nullptr;
	delete m_pShotControl;
}

void SceneMain::init()
{
	m_pPlayer->init();
	m_pShotControl->init();

	
	
}

void SceneMain::end()
{
	m_pPlayer->end();
	m_pShotControl->end();
	
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
	m_pShotControl->update();
	
	




	return this;
}

void SceneMain::draw()
{
	//DrawString(0, 0, "メイン画面", GetColor(255, 255, 255));

	m_pPlayer->draw();
	m_pShotControl->draw();
	
}

