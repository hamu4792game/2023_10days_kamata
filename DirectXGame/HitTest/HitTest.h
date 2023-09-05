#pragma once

class Score;

class Pla;

class Ene;

class HitTest {
public:
	
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update(Ene* enemy);

	void Reset();

	void SetPlayer(Pla* player) { player_ = player; }

	void SetScore(Score* score) { score_ = score; }

private:
	
	void HitEvalution(Ene* enemy);

private:

	enum Evalution { 
		kPerfect,
		kGreat,
		kGood,
		//kMiss
	};

	//Input* input_ = nullptr;

	// 一番遅いフレーム。これを基準にコンボ数によって早くする。
	const int kIntervalFrame_ = 30;

	int intervalCount_ = 0;

	int kEvalutionframe_[3] = {20, 60, 120};

	int evalutionCount_ = 0;

	Pla* player_ = nullptr;

	Score* score_ = nullptr;

};