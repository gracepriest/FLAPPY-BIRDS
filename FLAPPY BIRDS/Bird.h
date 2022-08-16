#pragma once

#include "StackFSM.h"
#include "Pipe.h"

//Trying a Header file only setup

class Bird : public StackFSM<GAMESTATE>
{
public:
	static Texture2D imgBird;

	int width;
	int height;
	float x;
	float y;
	float dx;
	float dy;
	const float GRAVITY = 5;
	float scale;

	Rectangle recMask;

	
	Bird();

	//~Bird();
	
	void Init();

	void Render();

	void Update(float dt);

	void updateState();

	bool Collides(const Pipe&);

	void Reset();
	
	

};