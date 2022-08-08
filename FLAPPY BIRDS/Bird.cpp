#include "Bird.h"



Bird::Bird()
{
	
	//Texture2D img1 = LoadTexture("Images/bird.png");
	 imgBird = LoadTexture("Images/bird.png");
	
	 x = SCREENWIDTH / 2 - (imgBird.width / 2);
	 y = SCREENHEIGHT / 2 - (imgBird.height / 2);
	 dx = 0;
	 dy = 0;
	 width = imgBird.width;
	 height = imgBird.height;

}

void Bird::Update(float dt)
{
	dy =+ dy + GRAVITY * dt;
	y =+ y + dy;
}

void Bird::Render()
{
	DrawTextureEx(imgBird, { x, y }, 0.0f, 2, WHITE);
}
