#include "..\include\segment.h"

Segment::Segment() {
	m_segmentImage = new Image("romfs:/player_head.png", GFX_TOP, GFX_LEFT);
	m_position = new sf2d_vector_2f();
	m_next = NULL;
}

Segment::Segment(float xPos, float yPos) {
	m_segmentImage = new Image("romfs:/player_head.png", GFX_TOP, GFX_LEFT);
	m_position = new sf2d_vector_2f();

	m_position->u = xPos;
	m_position->v = yPos;

	m_next = NULL;
}

Segment::~Segment() {
	if (m_next)
		delete m_next;

	delete m_segmentImage;
	delete m_position;;
}

void Segment::Update(float newXPos, float newYPos) {
	float m_oldXPos, m_oldYPos;
	m_oldXPos = m_position->u;
	m_oldYPos = m_position->v;

	m_position->u = newXPos;
	m_position->v = newYPos;

	if (m_next)
		m_next->Update(m_oldXPos, m_oldYPos);
}

void Segment::AddSegment() {
	printf("Adding new segment");
	if (m_next)
		m_next->AddSegment();

	else
		m_next = new Segment(m_position->u, m_position->v);
}

void Segment::Render() {
	m_segmentImage->RenderImage(int(m_position->u) * 8, int(m_position->v) * 8);

	if (m_next)
		m_next->Render();
}