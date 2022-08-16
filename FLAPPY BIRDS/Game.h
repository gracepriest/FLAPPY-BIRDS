#pragma once
#include "Common.h"
#include "StackFSM.h"

class Game   : public StackFSM<GAMESTATE>
{
public:
	



  virtual void updateState();

	Game();

	//need a draw/render function
	void Draw(float);

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

	void NewMenu();

	void GameOverMenu();
	
	void Reset();

	void CountScreen(float);



	~Game();




};