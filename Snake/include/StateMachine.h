#pragma once

class GameState;

class StateMachine {
private:
	GameState* m_currentState;
public:
	void ChangeState(GameState*);
	GameState* GetCurrentState();
	void Update();
	void Render();
};