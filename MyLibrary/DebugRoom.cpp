#include "DebugRoom.h"
#include "CircleCharactorClass.h"
#include "GroundClass.h"
#include "SceneManagerClass.h"

SceneManagerClass manag = SingletonClass<SceneManagerClass>::GetInstance();

CircleClass Circle1;
CircleCharactorClass Circle2;

void DebugInit()
{
	Circle1.Initialize(&POSITION(10 , 100) , &VELOCITY(1) , &ACCELARATION(0.1) , 5.0);

	Circle2.Initialize(&POSITION(10 , 200) , &VELOCITY(1) , &ACCELARATION(0.1) , 20.0);

	GameMode = GAME_PLAY;
}

void DebugView()
{
	Circle1.Update();
	Circle2.Update(&Ground);
	Circle1.Render();
	Circle2.Render();
	Ground.Render();
}