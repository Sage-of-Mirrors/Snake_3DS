#pragma once
#include "GameState.h"
#include "Player.h"

class PlayState : public GameState {
private:
	void RenderTopScreen();
	void RenderBottomScreen();
	Player* m_player;
public:
	PlayState();
	~PlayState();
	void Enter(const StateMachine* machine);
	void Update(StateMachine* machine);
	void Render();
	void Exit();
};
