#include "Bird.h"


Texture2D Bird::imgBird;
Bird::Bird()
{			 
	 scale = 2;
	 dx = 0;
	 dy = 0;
}

void Bird::Init()
{
	width = imgBird.width * scale;
	height = imgBird.height * scale;
	recMask.width = width;
	recMask.height = height;

	 x = SCREENWIDTH / 2 - (width / 2);
	 y = SCREENHEIGHT / 2 - (height / 2);
}

void Bird::Update(float dt)
{
	
	if (getCurrentState() == GAMESTATE::PLAY)
	{
		dy = +dy + GRAVITY * dt;
		y = +y + dy;
		recMask.x = x;
		recMask.y = y;
		if (IsKeyPressed(KEY_SPACE))
		{
			dy = -3;
		}
	}
	else
	{
		dy = 0;
	}

	
	
}

void Bird::updateState()
{
	/*if (IsKeyPressed(KEY_ENTER) && getCurrentState() != GAMESTATE::PLAY)
	{
		pushState(GAMESTATE::PAUSE);
	}
	else if (IsKeyPressed(KEY_ENTER) && getCurrentState() == GAMESTATE::PAUSE)
	{
		pushState(GAMESTATE::PLAY);
	}*/
}


void Bird::Render()
{
		DrawTextureEx(imgBird, { x, y }, 0.0f, scale, WHITE);
		//used for debugging
		//DrawRectangleRec(recMask, Color(255, 255, 255, 128));
		//DrawText(to_string(y).c_str(), 0, 0, 50, WHITE);
}


bool Bird::Collides(const Pipe& pipe)
{
	

	if (recMask.x > pipe.recMask.x + pipe.recMask.width -15 or pipe.recMask.x > recMask.x + recMask.width -15)
		return false;
	
	// then check to see if the bottom edge of either is higher than the top
	// edge of the other
	
	


	if (recMask.y > pipe.recMask.y + pipe.recMask.height-15 or pipe.recMask.y > recMask.y + recMask.height-15)
		return false;

	
		// if the above aren't true, they're overlapping
	else
		return true;

	//return CheckCollisionRecs(recMask, pipe.recMask);

}




void Bird::Reset()
{
	scale = 2;
	dx = 0;
	dy = 0;
	Init();
	pushState(GAMESTATE::NEWGAME);
}


