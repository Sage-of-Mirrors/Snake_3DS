#pragma once
#include "GameState.h"
#include "image.h"

class TitleState : public GameState {
private:
	Image* m_titleImg;
	float m_rad;
public:
	TitleState();
	void Enter(const StateMachine* machine);
	void Update(const StateMachine* machine);
	void Exit();
};