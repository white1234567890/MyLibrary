#include "DebugRoom.h"
#include "CircleClass.h"
#include "BoxClass.h"

CircleClass Circle1;
CircleClass Circle2;

BoxClass Ground;

void DebugInit()
{
	POSITION InitPos = {100,100,0};
	VELOCITY InitVel = {1,0,0};
	ACCELARATION InitAcc = {1,0,0};

	Circle1.Initialize(&InitPos , &InitVel , & InitAcc , 5.0);

	InitPos.m_Vector.y = 200;

	Circle2.Initialize(&InitPos , &InitVel , &InitAcc , 20.0);

	THREE_DIMENSION_VECTOR semilongvector = {SCREEN_WIDTH , 0 , 0};
	THREE_DIMENSION_VECTOR semishortvector = {0 , 10 , 0};

	InitPos.m_Vector.x = SCREEN_WIDTH / 2;
	InitPos.m_Vector.y = SCREEN_HEIGHT;
	InitVel.m_Vector = c_ZeroVector;
	InitAcc.m_Vector = c_ZeroVector;

	Ground.Initialize(&InitPos , &InitVel , &InitAcc , &semilongvector , &semishortvector);

	GameMode = GAME_PLAY;
}

void DebugView()
{
	Circle1.Update();
	Circle2.Update();
	Ground.Update();
	Circle1.Render();
	Circle2.Render();
	Ground.Render();
}