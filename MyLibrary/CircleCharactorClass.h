#pragma once
#include "circleclass.h"

//�g�p�N���X
class GroundClass;

class CircleCharactorClass :
	public CircleClass
{
public:
	CircleCharactorClass(void);
	~CircleCharactorClass(void);

	//////////////////////////////////////////////////////////////////////////////
	//�T��:
	//	�ڒn����
	//����:
	//	*ground:�n��
	//////////////////////////////////////////////////////////////////////////////
	void IsGrounded(GroundClass *ground);
	bool Update(GroundClass *ground);
	void Render();
};

