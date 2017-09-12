#include "TitleState.h"
#include <sf2d.h>

TitleState::TitleState() {
	
}

void TitleState::Enter(const StateMachine* machine) {
	m_titleImg = new Image("romfs:/title.png", GFX_TOP, GFX_LEFT);
}

void TitleState::Update(const StateMachine* machine) {
	m_titleImg->RenderImage(96, 89);
}

void TitleState::Exit() {
	delete m_titleImg;
}