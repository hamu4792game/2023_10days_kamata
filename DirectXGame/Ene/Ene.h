#pragma once
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

class Ene {
public:
	enum class BottomTypeClass {
		kA,
		kB,
		kX,
		kY
	};

	enum BottomType {
		kA,
		kB,
		kX,
		kY
	};

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(const Vector3& position, const int& bottomType, const int& num, Model* model);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	// <summary>
	/// 描画
	/// </summary>
	/// <param name="viewProjection">ビュープロジェクション(参照渡し)</param>
	void Draw(const ViewProjection& viewProjection);

	BottomTypeClass GetBottomType() { return bottomType_; }

	int GetNum() { return num_; }

	void Die() { isDead_ = true; }

	bool IsDead() { return isDead_; }

private:
private:
	// モデル
	Model* model_ = nullptr;

	WorldTransform worldTransform_;

	BottomTypeClass bottomType_ = BottomTypeClass::kA;

	int num_ = 0;

	bool isDead_ = false;
};
