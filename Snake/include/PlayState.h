#pragma once
#include "GameState.h"

class PlayState : public GameState {
private:
	void RenderTopScreen();
	void RenderBottomScreen();
public:
	PlayState();
	void Enter(const StateMachine* machine);
	void Update(StateMachine* machine);
	void Render();
	void Exit();
};
