#pragma once
#include "Common.h"

//Trying a Header file only setup

class Bird
{
public:
	int width;
	int height;
	float x;
	float y;
	float dx;
	float dy;
	const float GRAVITY = 5;

	Texture2D imgBird;
	Bird();

	//~Bird();
	

	void Render();

	void Update(float dt);
	

};