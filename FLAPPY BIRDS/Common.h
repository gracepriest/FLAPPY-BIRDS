#pragma once
#include <raylib.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <stack>
#include <vector>
#include "TitleScene.h"
#include "StateMachine.h"



 static const int SCREENWIDTH = 1100;
 static const int SCREENHEIGHT = 750;

enum class GAMESTATE : int
{
	START,
	LOAD,
	PLAY,
	PAUSE,
	OVER,
	NEWGAME,
	COUNTSCREEN


};



