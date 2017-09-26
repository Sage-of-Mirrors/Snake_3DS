#pragma once
#include "image.h"
#include <sf2d.h>
#include <stdlib.h>

class Food {
private:
	void RandomizePosition();
	Image* m_foodImage;
	sf2d_vector_2f* m_position;
public:
	Food();
	~Food();
	void Update();
	void Render();
	sf2d_vector_2f* GetPosition();
};