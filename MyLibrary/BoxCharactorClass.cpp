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
//�T��:
//	�ڒn����
//����:
//	*ground:�n��
//////////////////////////////////////////////////////////////////////////////
void BoxCharactorClass::IsGrounded(GroundClass *ground)
{
	m_GroundedFlag = CheckHitBoxandBox(this , ground);
}