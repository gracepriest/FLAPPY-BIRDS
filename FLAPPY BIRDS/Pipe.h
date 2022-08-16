#pragma once

#include "Common.h"
class Pipe 
{
public:
	static Texture2D PIPE_IMAGE; 

	static float PIPE_SCROLL;

	float x;
	float y;
	float width = PIPE_IMAGE.width;
	float height = PIPE_IMAGE.height;

	bool scored = false;

	bool isTop;

	Rectangle recMask;
	float scale;

	Pipe(bool);
	~Pipe();
	void Update(float);
	void  Render();
	

};


