#include "image.h"

Image::Image() {

}

Image::Image(const char* fileName, gfxScreen_t imageScreen, gfx3dSide_t imageSide) {
	m_screen = imageScreen;
	m_side = imageSide;
	m_texture = sfil_load_PNG_file(fileName, SF2D_PLACE_RAM);
}

Image::~Image() {
	sf2d_free_texture(m_texture);
}

void Image::RenderImage(int positionX, int positionY) {
	sf2d_start_frame(m_screen, m_side);
		sf2d_draw_texture(m_texture, positionX, positionY);
	sf2d_end_frame();
}