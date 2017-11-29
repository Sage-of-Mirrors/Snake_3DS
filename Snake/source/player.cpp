#include "..\include\Player.h"
#include <stdio.h>

const float VELOCITY = 0.25f;

Player::Player() {
	m_playerHead = new Image("romfs:/player_head.png", GFX_TOP, GFX_LEFT);
	m_firstSegment = NULL;

	m_xPos = 0.0f;
	m_yPos = 0.0f;
	m_xVel = 0.0f;
	m_yVel = VELOCITY;
}

Player::~Player() {
	delete m_playerHead;
	if (m_firstSegment)
		delete m_firstSegment;
}

void Player::Update() {
	ProcessInput();

	float m_oldXPos, m_oldYPos;
	m_oldXPos = m_xPos;
	m_oldYPos = m_yPos;

	m_xPos += m_xVel;
	m_yPos += m_yVel;

	if ((m_firstSegment))
		m_firstSegment->Update(m_oldXPos, m_oldYPos);
}

void Player::ProcessInput() {
	if (hidKeysDown() & KEY_CPAD_LEFT) {
		m_xVel = -VELOCITY;
		m_yVel = 0;
	}
	else if (hidKeysDown() & KEY_CPAD_RIGHT) {
		m_xVel = VELOCITY;
		m_yVel = 0;
	}
	else if (hidKeysDown() & KEY_CPAD_UP) {
		m_xVel = 0;
		m_yVel = -VELOCITY;
	}
	else if (hidKeysDown() & KEY_CPAD_DOWN) {
		m_xVel = 0;
		m_yVel = VELOCITY;
	}
}

int Player::CheckCollision(Food* food) {
	if (m_xPos < 0 || m_yPos < 0 || m_xPos > 50 || m_yPos > 30) // Game over if the player hits the edges of the screen
		return 1;

	CheckFoodCollision(food);

	return 0; // No collisions
}

void Player::CheckFoodCollision(Food* food) {
	int playerXBlock = int(m_xPos);
	int playerYBlock = int(m_yPos);

	int foodXBlock = int(food->GetPosition()->u);
	int foodYBlock = int(food->GetPosition()->v);

	if (playerXBlock == foodXBlock && playerYBlock == foodYBlock)
	{
		food->Update();
		
		if (m_firstSegment)
			m_firstSegment->AddSegment();
		else
		{
			m_firstSegment = new Segment(m_xPos, m_yPos);
			printf("Adding first segment %i", 1);
		}
	}
}

void Player::Render() {
	m_playerHead->RenderImage(int(m_xPos) * 8, int(m_yPos) * 8);
	//consoleClear();
	//printf("Position: (%f,%f)\n", m_xPos * 8, m_yPos * 8);
	//printf("Blocks: (%i,%i)\n", int(m_xPos), int(m_yPos));

	if (m_firstSegment)
		m_firstSegment->Render();
}