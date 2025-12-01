#pragma once
#include "Scene.h"
#include "FadeManager.h"
#include "Animation.h"


class GameManager {

	public:

		// シングルトンインスタンス取得　参照で返す
		static GameManager& GetInstance();


		

		int fadeDir = 0;

		int titleBG;

		int titleLogo;

		int titleBGM;

		int noiseY = 0;          // ノイズの描画Y位置
		int noiseMoveCounter = 0; // ノイズ移動用のカウンタ

		int noiseTimer = 0;


	void GameInit();

	void GameUpdate();

	void GameDraw();

	void GameEnd();

	void ChangeScene(SceneType next);



private:

	Animation hibana;

	Animation noize;

	FadeManager fader;

	//	コンストラクタ・デストラクタをデフォルト化
	GameManager() = default;
	~GameManager() = default;

	//	コピーコンストラクタ・代入演算子を削除
	GameManager(const GameManager&) = delete;

	GameManager& operator=(const GameManager&) = delete;

	SceneType currentScene = SceneType::TITLE;

	bool prevSpace = false;

	void UpdateTitle();

	void UpdateGame();

	void UpdateEnd();

	void DrawTitle();

	void DrawGame();

	void DrawEnd();





	};
