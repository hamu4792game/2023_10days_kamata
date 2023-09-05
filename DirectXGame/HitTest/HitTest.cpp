#include "HitTest.h"

#include "Pla/Pla.h"
#include "Ene/Ene.h"
#include "Score/Score.h"

#include "Input.h"

void HitTest::Initialize() {


}

void HitTest::Reset() {
	evalutionCount_ = 0;
	intervalCount_ = 0;
}

void HitTest::HitEvalution(Ene* enemy) {

	if (evalutionCount_ <= kEvalutionframe_[kPerfect]) {
		
		enemy->Die();
		score_->AddPer();

		evalutionCount_ = 0;

	} else if (evalutionCount_ <= kEvalutionframe_[kGreat]) {

		enemy->Die();
		score_->AddGre();

		evalutionCount_ = 0;

	} else if (evalutionCount_ <= kEvalutionframe_[kGood]) {

		enemy->Die();
		score_->AddGood();

		evalutionCount_ = 0;
	} else {

		//enemy->Die();
		score_->AddMiss();

		evalutionCount_ = 0;
	}
}

void HitTest::Update(Ene* enemy) {

	// 毎フレーム1回のみの更新。カウントがフレーム数と一致しなくなるため。

	score_->ResetEvalution();

	evalutionCount_++;

	XINPUT_STATE joyState;

	if (Input::GetInstance()->GetJoystickState(0, joyState)) {
	
		if (joyState.Gamepad.wButtons & XINPUT_GAMEPAD_A) {
			
			if (enemy->GetBottomType() == Ene::BottomTypeClass::kA) {
				
				HitEvalution(enemy);
			}

		}else if (joyState.Gamepad.wButtons & XINPUT_GAMEPAD_B) {
			if (enemy->GetBottomType() == Ene::BottomTypeClass::kB) {
				HitEvalution(enemy);
			}

		} else if (joyState.Gamepad.wButtons & XINPUT_GAMEPAD_X) {
			if (enemy->GetBottomType() == Ene::BottomTypeClass::kX) {
				HitEvalution(enemy);
			}

		}else if (joyState.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {
			if (enemy->GetBottomType() == Ene::BottomTypeClass::kY) {
				HitEvalution(enemy);
			}

		}
	}


}