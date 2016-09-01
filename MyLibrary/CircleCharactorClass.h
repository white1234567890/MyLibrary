#pragma once
#include "circleclass.h"

//使用クラス
class GroundClass;

class CircleCharactorClass :
	public CircleClass
{
public:
	CircleCharactorClass(void);
	~CircleCharactorClass(void);

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	接地判定
	//引数:
	//	*ground:地面
	//////////////////////////////////////////////////////////////////////////////
	void IsGrounded(GroundClass *ground);
	bool Update(GroundClass *ground);
	void Render();
};

