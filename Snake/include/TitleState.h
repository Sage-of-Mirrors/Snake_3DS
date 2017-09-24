#pragma once
#include "GameState.h"
#include "image.h"

class TitleState : public GameState {
private:
	void RenderTopScreen();
	void RenderBottomScreen();
	Image* m_titleImg;
	Image* m_pressStartImg;
	float m_rad;
	int m_pressStartBlinkSpeed;
	int m_pressStartBlinkAlpha;
	int m_frameCount;
public:
	TitleState();
	~TitleState();
	void Enter(const StateMachine* machine);
	void Update(StateMachine* machine);
	void Render();
	void Exit();
};