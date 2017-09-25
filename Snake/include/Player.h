#pragma once
#include "image.h"
#include <sf2d.h>

class Player {
private:
	void ProcessInput();
	Image* m_playerHead;
	float m_xPos, m_yPos;
	float m_xVel, m_yVel;
public:
	Player();
	~Player();
	int Update();
	void Render();
};