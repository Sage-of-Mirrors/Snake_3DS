#pragma once
#include "image.h"
#include "segment.h"
#include "food.h"
#include <sf2d.h>

class Player {
private:
	void ProcessInput();
	void CheckFoodCollision(Food* food);
	Image* m_playerHead;
	Segment* m_firstSegment;
	float m_xPos, m_yPos;
	float m_xVel, m_yVel;
public:
	Player();
	~Player();
	void Update();
	int CheckCollision(Food* food);
	void Render();
};