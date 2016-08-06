#pragma once
#include "common.h"

class BaseObjectClass
{
protected:
	bool m_Flag;	//�t���O
	POSITION m_Position;	//���S���W
	VELOCITY m_Velocity;	//���x
	ACCELARATION m_Accelaration;	//�����x

public:
	BaseObjectClass(void);
	~BaseObjectClass(void);
	
	//////////////////////////////////////////////////////////////////////////////
	//�T��:
	//	���S���W���擾����
	//�߂�l:
	//�@m_Position:���S���W
	//////////////////////////////////////////////////////////////////////////////
	POSITION GetPosition();

	virtual bool Initialize(POSITION* position , VELOCITY* velocity , ACCELARATION* accelaration , bool flag = false) = 0;
};

