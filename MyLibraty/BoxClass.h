#pragma once
#include "common.h"

class BoxClass
{
private:
	//�����o�ϐ�

	bool m_Flag;	//�t���O
	POSITION m_Position;	//���S���W
	VELOCITY m_Velocity;	//���x
	ACCELARATION m_Accelaration;	//�����x
	VARIABLE_VERTEX m_Vertex;	//���_
	double m_SemiLongAxis;	//�������̒���
	double m_SemiShortAxis;	//���Z���̒���
	THREE_DIMENSION_VECTOR m_SemiLongVector;	//�������x�N�g��
	THREE_DIMENSION_VECTOR m_SemiShortVector;	//���Z���x�N�g��

public:
	//�R���X�g���N�^
	BoxClass(void);

	//�f�X�g���N�^
	~BoxClass(void);
};

