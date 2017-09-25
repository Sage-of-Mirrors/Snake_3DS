#include "..\include\PlayState.h"
#include "..\include\TitleState.h"
#include <sf2d.h>

PlayState::PlayState() {
	m_player = new Player();
}

PlayState::~PlayState() {
	delete m_player;
}

void PlayState::Enter(const StateMachine* machine) {
}

void PlayState::Update(StateMachine* machine) {
	if (m_player->Update())
	{
		TitleState* title = new TitleState();
		machine->ChangeState(title);
		delete this;
	}
}

void PlayState::Render() {
	RenderTopScreen();
	RenderBottomScreen();
}

void PlayState::RenderTopScreen() {
	sf2d_start_frame(GFX_TOP, GFX_LEFT);

	m_player->Render();

	sf2d_end_frame();
}

void PlayState::RenderBottomScreen() {
	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);



	sf2d_end_frame();
}

void PlayState::Exit() {

}