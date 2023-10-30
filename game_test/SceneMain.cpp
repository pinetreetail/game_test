#include "DxLib.h"

#include "SceneMain.h"
#include "SceneTitle.h"


#include "Pad.h"

SceneMain::SceneMain()
{
}

SceneMain::~SceneMain()
{
}

void SceneMain::init()
{
	player.init();


	for (auto& shot : shot)
	{
		shot.init();
	}
	
}

void SceneMain::end()
{
	player.end();

	for (auto& shot : shot)
	{
		shot.end();
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

	player.update();

	for (auto& shot : shot)
	{
		shot.update();
	}
	




	return this;
}

void SceneMain::draw()
{
	DrawString(0, 0, "メイン画面", GetColor(255, 255, 255));

	player.draw();
	for (auto& shot : shot)
	{
		shot.draw();
	}
	
}