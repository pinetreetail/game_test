#include "DxLib.h"

#include "SceneTitle.h"
#include "SceneMain.h"
#include "Pad.h"


SceneTitle::SceneTitle() :
	m_isEnd(false)
{
	for (int i = 0; i < 2; i++)
	{
		for (int f = 0; f < 5; f++)
		{
			GrHandle[i][f] = 0;

		}
	}
	
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::init()
{

	LoadDivGraph("image/playe/ship1.png", 10, 5, 2, 16, 24, GrHandle[1]);
	LoadDivGraph("image/playe/ship2.png", 10, 5, 2, 16, 24, GrHandle[2]);

	m_isEnd = false;
}

SceneBase* SceneTitle::update()
{
	// パッドのアップデート処理
	Pad::update();
	
	if (Pad::isTrigger(PAD_INPUT_1))
	{
		// Mainに切り替え
		return(new SceneMain);
	}



	DrawBillboard3D(VGet(250.0f, 100.0f, 100.0f), 0.5f, 0.5f, 40.0f, 0.0f, GrHandle[2], TRUE);










	return this;
}

void SceneTitle::draw()
{
	DrawString(0, 0, "タイトル画面", GetColor(255, 255, 255));
}