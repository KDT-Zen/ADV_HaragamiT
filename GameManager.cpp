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


void GameManager::GameInit() {}


void GameManager::GameUpdate() {

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
}

void GameManager::GameEnd() {}


// シーン変更
void GameManager::ChangeScene(SceneType next) {
	currentScene = next;
}


//　GameManager::Instance().ChangeScene(SceneType::Main);　変える時の書き方の例















	// タイトルの更新処理

	/*	bool now = (CheckHitKey(KEY_INPUT_SPACE) != 0);


		if ((now && !prevSpace))
		{
			GameManager::GetInstance().ChangeScene(SceneType::GAME);
		}*/

