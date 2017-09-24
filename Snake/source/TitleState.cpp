#include "TitleState.h"
#include "..\include\PlayState.h"
#include <sf2d.h>

TitleState::TitleState() {
	
}

void TitleState::Enter(const StateMachine* machine) {
	m_titleImg = new Image("romfs:/title.png", GFX_TOP, GFX_LEFT);
	m_pressStartImg = new Image("romfs:/press_start.png", GFX_TOP, GFX_LEFT);

	m_pressStartBlinkSpeed = 45;
	m_pressStartBlinkAlpha = 0;
	m_frameCount = 0;
}

void TitleState::Update(StateMachine* machine) {
	m_frameCount++;

	if (m_frameCount == m_pressStartBlinkSpeed)
	{
		if (m_pressStartBlinkAlpha == 0)
			m_pressStartBlinkAlpha = 255;
		else
			m_pressStartBlinkAlpha = 0;

		m_frameCount = 0;
	}

	if (hidKeysDown() & KEY_START || hidKeysDown() & KEY_A)
	{
		PlayState* play = new PlayState();
		machine->ChangeState(play);
		delete this;
	}
}

void TitleState::Render() {
	RenderTopScreen();
	RenderBottomScreen();
}

void TitleState::RenderTopScreen() {
	sf2d_start_frame(GFX_TOP, GFX_LEFT);

	m_titleImg->RenderImage(96, 89);

	sf2d_end_frame();
}

void TitleState::RenderBottomScreen() {
	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);

	m_pressStartImg->RenderImage(0, 0);
	sf2d_draw_rectangle(0, 0, 320, 240, RGBA8(0, 0, 0, m_pressStartBlinkAlpha));

	sf2d_end_frame();
}

void TitleState::Exit() {
}

TitleState::~TitleState() {
	delete m_titleImg;
	delete m_pressStartImg;
}