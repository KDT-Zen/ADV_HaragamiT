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


void GameManager::GameInit() {


	titleBG = LoadGraph("data/bg.jpeg");

	titleLogo = LoadGraph("data/logo.png");



}


void GameManager::GameUpdate() {

	updateFade();


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

	DrawFade();

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

void GameManager::GameEnd(){

	DeleteGraph(titleBG);

	DeleteGraph(titleLogo);


};


// シーン変更
void GameManager::ChangeScene(SceneType next) {
	currentScene = next;
}



void GameManager::updateFade()
{

	//　フェードしていない状態の時
	if (fadeDir == 0) return;

	fadealpha += fadeDir * 5;

	if (fadealpha < 0) {

		fadealpha = 0;

		fadeDir = 0;

	}

	if (fadealpha > 255) {

		fadealpha = 255;

		fadeDir = 0;

	}

};

void GameManager::DrawTitle()
{
	DrawExtendGraph(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, titleBG, TRUE);

	DrawGraph(200, 100, titleLogo, TRUE);


}


void GameManager::DrawFade()
{

	//　半透明合成
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fadealpha);


	//　黒で画面全体を塗る
	DrawBox(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, GetColor(0, 0, 0), TRUE);

	//　合成終了
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}














