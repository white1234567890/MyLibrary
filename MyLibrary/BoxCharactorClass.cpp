#include "BoxCharactorClass.h"
#include "GroundClass.h"
#include "system.h"


BoxCharactorClass::BoxCharactorClass(void)
{
}


BoxCharactorClass::~BoxCharactorClass(void)
{
}

//////////////////////////////////////////////////////////////////////////////
//äTó™:
//	ê⁄ínîªíË
//à¯êî:
//	*ground:ínñ 
//////////////////////////////////////////////////////////////////////////////
void BoxCharactorClass::IsGrounded(GroundClass *ground)
{
	m_GroundedFlag = CheckHitBoxandBox(this , ground);
}