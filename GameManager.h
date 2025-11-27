#pragma once
#include "Scene.h"



class GameManager {

	public:

		// シングルトンインスタンス取得　参照で返す
		static GameManager& GetInstance();

	void GameInit();

	void GameUpdate();

	void GameDraw();

	void GameEnd();

	void ChangeScene(SceneType next);

	void FadeOut();


private:

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
