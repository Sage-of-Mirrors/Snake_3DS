#include "..\include\PlayState.h"
#include <sf2d.h>

PlayState::PlayState() {

}

void PlayState::Enter(const StateMachine* machine) {
}

void PlayState::Update(StateMachine* machine) {

}

void PlayState::Render() {
	RenderTopScreen();
	RenderBottomScreen();
}

void PlayState::RenderTopScreen() {
	sf2d_start_frame(GFX_TOP, GFX_LEFT);

	sf2d_draw_fill_circle(0, 0, 200, RGBA8(100, 50, 50, 255));

	sf2d_end_frame();
}

void PlayState::RenderBottomScreen() {
	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);



	sf2d_end_frame();
}

void PlayState::Exit() {

}