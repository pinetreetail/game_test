#include "DxLib.h"

#include "SceneMain.h"
#include "SceneTitle.h"
#include "Player.h"
#include "ShotControl.h"
#include "Pad.h"

SceneMain::SceneMain()	
{
}

SceneMain::~SceneMain()
{
	
}

void SceneMain::init()
{

	player.setShotControl();

	player.init();
	shotcontrol.init();

	
	// Near, Far クリップの距離を設定
	SetCameraNearFar(0.1f, 1000.0f);

	SetCameraPositionAndAngle(VGet(0.0f, 0.0f, -100.0f), 0.0f, 0.0f, 0.0f);
}

void SceneMain::end()
{
	player.end();
	shotcontrol.end();
	
}

SceneBase* SceneMain::update()
{
	// パッドのアップデート処理
	Pad::update();

	if (Pad::isTrigger(PAD_INPUT_1))
	{
		return (new SceneTitle);
	}

	player.update();
	shotcontrol.update();
	
	




	return this;
}

void SceneMain::draw()
{
	//DrawString(0, 0, "メイン画面", GetColor(255, 255, 255));

	player.draw();
	shotcontrol.draw();
	
}

