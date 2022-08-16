#pragma once
#include "Common.h"

class SceneBase
{
public:
	
	float data;
	SceneBase();
	virtual void Init() = 0;
	void Exit();
	void Update(float);
	void Render();

};

