#pragma once
#include "boxclass.h"
class BoxCharactorClass :
	public BoxClass
{
protected:
	//////////////////////////////////////////////////////////////////////////////
	//ŠT—ª:
	//	Ú’n”»’è
	//ˆø”:
	//	*ground:’n–Ê
	//////////////////////////////////////////////////////////////////////////////
	void IsGrounded(GroundClass *ground);

public:
	BoxCharactorClass(void);
	~BoxCharactorClass(void);
};

