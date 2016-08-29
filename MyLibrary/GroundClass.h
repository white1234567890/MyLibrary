#pragma once
#include "boxclass.h"
class GroundClass :
	public BoxClass
{
public:
	static const double GROUND_HEIGHT;

	GroundClass(void);
	~GroundClass(void);
};

extern GroundClass Ground;