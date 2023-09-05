#include "Ene.h"
#include <cassert>

void Ene::Initialize(const Vector3& position, const int& bottomType, const int& num, Model* model) {

	assert(model);
	model_ = model;

	switch (bottomType) {
	case kA:

		bottomType_ = BottomTypeClass::kA;
		break;
	case kB:
		bottomType_ = BottomTypeClass::kB;
		break;
	case kX:
		bottomType_ = BottomTypeClass::kX;
		break;
	case kY:
		bottomType_ = BottomTypeClass::kY;
		break;

	default:
		break;
	}

	num_ = num;

	worldTransform_.Initialize();
	worldTransform_.translation_ = position;

	//worldTransform_.UpdateMatrix();
}

void Ene::Update() {

	//Vector3 move = {0.0f, 0.0f, -1.0f};
	//
	//move *= speed;

	////move = move * Matrix4x4::MakeRotateXYZMatrix(worldTransform_.rotation_);

	//worldTransform_.translation_ += move;

	//worldTransform_.UpdateMatrix();
	
}

void Ene::Draw(const ViewProjection& viewProjection) {
	model_->Draw(worldTransform_, viewProjection);
}