#pragma once
#include "BaseObjectClass.h"

class CircleClass:
	public BaseObjectClass
{
private:
	//�����o�ϐ�
	double m_Radius;	//���a

public:
	//�R���X�g���N�^
	CircleClass(void);

	//�f�X�g���N�^
	~CircleClass(void);

	//�����o�֐�

	//////////////////////////////////////////////////////////////////////////////
	//�T��:
	//	�~�̔��a���擾����
	//�߂�l:
	//	m_Radius:�~�̔��a
	//////////////////////////////////////////////////////////////////////////////
	double GetRadius();
};