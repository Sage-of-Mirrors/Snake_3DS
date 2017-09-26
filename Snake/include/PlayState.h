#pragma once
#include "GameState.h"
#include "Player.h"
#include "food.h"

class PlayState : public GameState {
private:
	void RenderTopScreen();
	void RenderBottomScreen();
	Player* m_player;
	Food* m_food;
public:
	PlayState();
	~PlayState();
	void Enter(const StateMachine* machine);
	void Update(StateMachine* machine);
	void Render();
	void Exit();
};
