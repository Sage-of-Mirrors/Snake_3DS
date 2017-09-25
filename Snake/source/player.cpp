#include "..\include\Player.h"
#include <stdio.h>

const float VELOCITY = 0.25f;

Player::Player() {
	m_playerHead = new Image("romfs:/player_head.png", GFX_TOP, GFX_LEFT);

	m_xPos = 0.0f;
	m_yPos = 0.0f;
	m_xVel = 0.0f;
	m_yVel = VELOCITY;
}

Player::~Player() {
	delete m_playerHead;
}

int Player::Update() {
	if (m_xPos < 0 || m_yPos < 0 || m_xPos > 50 || m_yPos > 30) // Game over if the player hits the edges of the screen
		return 1;

	ProcessInput();

	m_xPos += m_xVel;
	m_yPos += m_yVel;

	return 0; // Nothing happened to end gameplay, yay
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

void Player::Render() {
	m_playerHead->RenderImage(int(m_xPos) * 8, int(m_yPos) * 8);
	consoleClear();
	printf("Position: (%f,%f)\n", m_xPos * 8, m_yPos * 8);
	printf("Blocks: (%i,%i)\n", int(m_xPos), int(m_yPos));
}