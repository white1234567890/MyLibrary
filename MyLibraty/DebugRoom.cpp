#include "DebugRoom.h"
#include "CircleClass.h"
#include "BoxClass.h"

CircleClass Circle1;
CircleClass Circle2;

BoxClass Box1;
BoxClass Box2;

void DebugInit()
{
	POSITION InitPos = {100,100,0};
	VELOCITY InitVel = {1,0,0};
	ACCELARATION InitAcc = {1,0,0};

	Circle1.Initialize(&InitPos , &InitVel , & InitAcc , 5.0);

	InitPos.m_Vector.y = 200;

	Circle2.Initialize(&InitPos , &InitVel , &InitAcc , 20.0);

	THREE_DIMENSION_VECTOR semilongvector = {10 , 0 , 0};
	THREE_DIMENSION_VECTOR semishortvector = {0 , 5 , 0};

	InitPos.m_Vector.y = 300;

	Box1.Initialize(&InitPos , &InitVel , &InitAcc , &semilongvector , &semishortvector);

	semilongvector.x = 0;
	semilongvector.y = 10;
	semishortvector.x = 5;
	semishortvector.y = 0;
	InitPos.m_Vector.y = 400;

	Box2.Initialize(&InitPos , &InitVel , &InitAcc , &semilongvector , &semishortvector);

	GameMode = GAME_PLAY;
}

void DebugView()
{
	Circle1.Update();
	Circle2.Update();
	Box1.Update();
	Box2.Update();
	Circle1.Render();
	Circle2.Render();
	Box1.Render();
	Box2.Render();
}