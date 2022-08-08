#include "Player.h"
#include "Common.h"

//---------------------------------------------------------------------------------------------------------------------------------------
//Init Player
Player::Player(float x, float y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->dy = 0;
	this->dx = 0;
	//this->ai = false;

}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Used in old game Kept just in case i need
template<typename T>
T newMax(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;

}
template<typename T>
T newMin(T a, T b)
{
	if (a < b)
		return a;
	else
		return b;
}
//----------------------------------------------------------------------------------------------------------------------------------------
//Update the player
void Player::Update(float dt)   // dt as detlatime
{

}
//----------------------------------------------------------------------------------------------------------------------------------------
//draw player
void Player::Render()
{
	DrawRectangle(this->x, this->y, this->width, this->height, RAYWHITE);
}
//---------------------------------------------------------------------------------------
//~ clean up if needed
Player::~Player()
{

}
