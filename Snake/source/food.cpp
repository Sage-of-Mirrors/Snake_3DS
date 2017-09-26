#pragma once
#include "..\include\food.h"

Food::Food() {
	m_foodImage = new Image("romfs:/food.png", GFX_TOP, GFX_LEFT);
	m_position = new sf2d_vector_2f();

	srand(osGetTime());
	RandomizePosition();
}

Food::~Food() {
	delete m_foodImage;
	delete m_position;
}

void Food::Update() {
	RandomizePosition();
}

void Food::Render() {
	m_foodImage->RenderImage(int(m_position->u) * 8, int(m_position->v) * 8);
}

sf2d_vector_2f* Food::GetPosition() {
	return m_position;
}

void Food::RandomizePosition() {
	m_position->u = static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 50.0f);
	m_position->v = static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 30.0f);
}