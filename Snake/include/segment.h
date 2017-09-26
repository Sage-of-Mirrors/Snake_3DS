#pragma once
#include "image.h"
#include <stdio.h>
#include <sf2d.h>

class Segment {
private:
	Image* m_segmentImage;
	sf2d_vector_2f* m_position;
	Segment* m_next;
public:
	Segment();
	Segment(float xPos, float yPos);
	~Segment();
	void Update(float newXPos, float newYPos);
	void AddSegment();
	void Render();
};