#include "CircleCharactorClass.h"
#include "GroundClass.h"
#include "system.h"


CircleCharactorClass::CircleCharactorClass(void) : CircleClass()
{
}


CircleCharactorClass::~CircleCharactorClass(void)
{
}

//////////////////////////////////////////////////////////////////////////////
//publicΦ
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//Tͺ:
//	Ϊn»θ
//ψ:
//	*ground:nΚ
//////////////////////////////////////////////////////////////////////////////
void CircleCharactorClass::IsGrounded(GroundClass *ground)
{
	if(m_GroundedFlag = CheckHitCircleandBox(this , ground))
	{
		m_Position.m_Vector.y = ground->GetPosition().m_Vector.y - ground->GROUND_HEIGHT - m_Radius;
	}
}

//////////////////////////////////////////////////////////////////////////////
//Tͺ:
//	XV
//////////////////////////////////////////////////////////////////////////////
bool CircleCharactorClass::Update(GroundClass *ground)
{
	MoveObject(m_GroundedFlag);
	AccelObject();
	IsGrounded(ground);
	
	return true;
}

//////////////////////////////////////////////////////////////////////////////
//Tͺ:
//	`ζ
//////////////////////////////////////////////////////////////////////////////
void CircleCharactorClass::Render()
{
	DrawCircle((int)m_Position.m_Vector.x , (int)m_Position.m_Vector.y , (int)m_Radius , 0xffffff);
}