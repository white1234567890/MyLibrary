#pragma once
#include "boxclass.h"
class BoxCharactorClass :
	public BoxClass
{
protected:
	//////////////////////////////////////////////////////////////////////////////
	//�T��:
	//	�ڒn����
	//����:
	//	*ground:�n��
	//////////////////////////////////////////////////////////////////////////////
	void IsGrounded(GroundClass *ground);

public:
	BoxCharactorClass(void);
	~BoxCharactorClass(void);
};

