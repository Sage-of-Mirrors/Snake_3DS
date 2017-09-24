#include "StateMachine.h"
#include "GameState.h"

void StateMachine::ChangeState(GameState* nextState) {
	if (m_currentState)
		m_currentState->Exit();

	m_currentState = nextState;

	if (m_currentState)
		m_currentState->Enter(this);
}

GameState* StateMachine::GetCurrentState() {
	return m_currentState;
}

void StateMachine::Update() {
	m_currentState->Update(this);
}

void StateMachine::Render() {
	m_currentState->Render();
}