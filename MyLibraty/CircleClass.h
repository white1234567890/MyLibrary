#pragma once
#include "common.h"


class CircleClass
{
private:
	//�����o�ϐ�

	bool m_Flag;	//�t���O
	POSITION m_Position;	//���S���W
	VELOCITY m_Velocity;	//���x
	ACCELARATION m_Accelaration;	//�����x
	double m_Radius;	//���a

public:
	//�R���X�g���N�^
	CircleClass(void);

	//�f�X�g���N�^
	~CircleClass(void);

	//�����o�֐�

	POSITION GetPosition();
	double GetRadius();
};