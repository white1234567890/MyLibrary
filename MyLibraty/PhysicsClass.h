#pragma once
#include "common.h"
#include "TimerClass.h"

class PhysicsClass
{
protected:
	//�����o�ϐ�

	static const double m_GravityAccelaration;
	THREE_DIMENSION_VECTOR m_GravityVelocity;
	bool m_GroundedFlag;

	TimerClass m_GavityTime;

	//�����o�֐�

	//////////////////////////////////////////////////////////////////////////////
	//�T��:
	//	���̂��ړ�������
	//////////////////////////////////////////////////////////////////////////////
	virtual void MoveObject() = 0;

	//////////////////////////////////////////////////////////////////////////////
	//�T��:
	//	���̂�����������
	//////////////////////////////////////////////////////////////////////////////
	virtual void AccelObject() = 0;


public:
	//�R���X�g���N�^
	PhysicsClass(void);
	//�f�X�g���N�^
	~PhysicsClass(void);
};

