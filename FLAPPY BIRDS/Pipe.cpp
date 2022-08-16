#include "Pipe.h"


Texture2D Pipe::PIPE_IMAGE; 
float Pipe::PIPE_SCROLL = -100;

Pipe::Pipe(bool istop) : isTop(istop)
{
	scale = 2;

	width = PIPE_IMAGE.width * scale;
	height = PIPE_IMAGE.height;
	
	x = SCREENWIDTH + width  + width * isTop;
	
	y = isTop ? height -rand() % 150 + 100: rand() % 90 + (SCREENHEIGHT - height);

	recMask.width = width;
	recMask.height = height;
	
}

void Pipe::Update(float dt)
{
	x += PIPE_SCROLL * dt;
	recMask.x = x - width * isTop;

	recMask.y = y - height * isTop;
}

void Pipe::Render()
{
	
  DrawTextureEx(PIPE_IMAGE, { x, y },180.f * isTop, 2, WHITE);
  //used for debugging
  //DrawRectangleRec(recMask,Color(255,255,255,128));
	   
}

 Pipe::~Pipe()
{

}