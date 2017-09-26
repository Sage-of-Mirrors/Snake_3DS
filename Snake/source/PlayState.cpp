#include "..\include\PlayState.h"
#include "..\include\TitleState.h"
#include <sf2d.h>

PlayState::PlayState() {
	m_player = new Player();
	m_food = new Food();
}

PlayState::~PlayState() {
	delete m_player;
	delete m_food;
}

void PlayState::Enter(const StateMachine* machine) {
}

void PlayState::Update(StateMachine* machine) {
	m_player->Update();

	int colResult = m_player->CheckCollision(m_food);

	if (colResult == 0) // No change, continue the game
		return;
	else if (colResult == 1) // Game over. Switch to game over state
	{
		TitleState* title = new TitleState();
		machine->ChangeState(title);
		delete this;
	}
	else if (colResult == 2) // Win! Switch to win state.
	{

	}
}

void PlayState::Render() {
	RenderTopScreen();
	RenderBottomScreen();
}

void PlayState::RenderTopScreen() {
	sf2d_start_frame(GFX_TOP, GFX_LEFT);

	m_player->Render();
	m_food->Render();

	sf2d_end_frame();
}

void PlayState::RenderBottomScreen() {
	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);



	sf2d_end_frame();
}

void PlayState::Exit() {

}