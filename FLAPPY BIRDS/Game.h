#pragma once
#include "Common.h"
class Game
{
public:
	



	void UpdateState();

	Game();

	//need a draw/render function
	void Draw();

	//load or init function 
	//return number greater than 0 if load fails
	int load();

	//update function that provides detla time
	void Update();

	//close or shutdow function
	void Close();

	//keypress function

	char CheckKeyPress();

	bool IsKeyPress();

	void Start();




	~Game();




};