#include "GameManager.h"
#include "Scene.h"
#include "DxLib.h"
#include "GameDefine.h"

//メモ GameManager&は戻値の型
//GameManager型の参照を返す関数　という意味


GameManager& GameManager::GetInstance() {

	//　GameManagerの唯一のインスタンスを生成・保持
	static GameManager instance;

	return instance;
}

void GameManager::UpdateTitle() {

}


void GameManager::UpdateGame() {

}

void GameManager::UpdateEnd() {

}


// シーン変更
void GameManager::ChangeScene(SceneType next) {
	currentScene = next;
}




void GameManager::DrawTitle()
{
	DrawExtendGraph(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, titleBG, TRUE);

	DrawGraph(200, 100, titleLogo, TRUE);


}

void GameManager::DrawGame() {

}

void GameManager::DrawEnd() {

}

void GameManager::GameInit() {

	fader.Init();

	fader.StartFadeIn(2);

	titleBG = LoadGraph("data/bg.jpg");

	titleLogo = LoadGraph("data/logo.png");

}

void GameManager::GameUpdate() {

	fader.Update();

	if (fader.IsFading())return;

	//　各シーンの切り替え
	switch (currentScene) {

	case SceneType::TITLE:

		GameManager::UpdateTitle();
	
			break;

	case SceneType::GAME:

		// 本編（ADV文章進行）の更新処理

		GameManager::UpdateGame();

		break;

	case SceneType::ENDING:

		// エンディングの更新処理

		GameManager::UpdateEnd();

		break;

	}

}

void GameManager::GameDraw() {


	switch (currentScene) {

	case SceneType::TITLE:

		// タイトルの描画処理
		GameManager::DrawTitle();

		break;

	case SceneType::GAME:
		// 本編（ADV文章進行）の描画処理

		GameManager::DrawGame();

		break;

	case SceneType::ENDING:
		// エンディングの描画処理

		GameManager::DrawEnd();

		break;

	}

	fader.Draw();
}

void GameManager::GameEnd(){

	DeleteGraph(titleBG);

	DeleteGraph(titleLogo);


};









