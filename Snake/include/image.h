#pragma once
#include <3ds.h>
#include <sf2d.h>
#include <sfil.h>

class Image {
private:
	int m_width, m_height;
	gfxScreen_t m_screen;
	gfx3dSide_t m_side;
	sf2d_texture* m_texture;
public:
	void RenderImage(int x, int y);
	Image();
	Image(const char* fileName, gfxScreen_t imageScreen, gfx3dSide_t imageSide);
	~Image();
};