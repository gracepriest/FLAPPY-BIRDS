#pragma once
#include "Common.h"
#include "SceneBase.h"
using namespace std;
 template<class T>
class SceneManager
{
public:
	 //SM WILL TAKE A LIST OF GAMEOBJECT, INIT THEM AND HANDLE UPDATE AND RENDER
	vector<T> scenes;
	SceneManager(vector<T> &List_Sences)
	{
		scenes = List_Sences;
	}
	void Init()
	{
		
			scenes.Init();
		
	}

	void Update()
	{
		scenes.Update();
	}

	void Render()
	{
		scenes.Render();
	}
	//template<typename T>
	void Changescene()
	{
		//find scenc and set
		//scenes = scene;
		//data = options;

	}
};