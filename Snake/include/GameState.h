#pragma once
#include <stdio.h>
#include "StateMachine.h"

class GameState {
public:
	virtual void Enter(const StateMachine* machine) = 0;
	virtual void Update(const StateMachine* machine) = 0;
	virtual void Exit() = 0;
};