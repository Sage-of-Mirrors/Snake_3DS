#pragma once
#include <stdio.h>
#include "StateMachine.h"

class GameState {
protected:
	virtual void RenderTopScreen() = 0;
	virtual void RenderBottomScreen() = 0;
public:
	virtual ~GameState() { }
	virtual void Enter(const StateMachine* machine) = 0;
	virtual void Update(StateMachine* machine) = 0;
	virtual void Render() = 0;
	virtual void Exit() = 0;
};