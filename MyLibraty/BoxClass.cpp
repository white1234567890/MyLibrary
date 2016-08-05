#include "BoxClass.h"

//////////////////////////////////////////////////////////////////////////////
//�R���X�g���N�^
//////////////////////////////////////////////////////////////////////////////
BoxClass::BoxClass(void)
{
	POSITION p;
	for(int i = 0 ; i < 4 ; i++)
	{
		m_Vertex.m_VertexPosition.push_back(p);
	}
}

//////////////////////////////////////////////////////////////////////////////
//�f�X�g���N�^
//////////////////////////////////////////////////////////////////////////////
BoxClass::~BoxClass(void)
{
	m_Vertex.m_VertexPosition.clear();
}

//////////////////////////////////////////////////////////////////////////////
//public�֐�
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//�T��:
//	��`�̒��S���W���擾����
//�߂�l:
//	m_Position:��`�̒��S���W
//////////////////////////////////////////////////////////////////////////////
POSITION BoxClass::GetPosition()
{
	return m_Position;
}

//////////////////////////////////////////////////////////////////////////////
//�T��:
//	��`��4�̒��_���擾����
//�߂�l:
//	m_Vertex:��`��4�̒��_
//////////////////////////////////////////////////////////////////////////////
VARIABLE_VERTEX BoxClass::GetVertex()
{
	return m_Vertex;
}

//////////////////////////////////////////////////////////////////////////////
//�T��:
//	��`�̔������̒������擾����
//�߂�l:
//	m_SemiLongAxis:��`�̔������̒���
//////////////////////////////////////////////////////////////////////////////
double BoxClass::GetSemiLongAxis()
{
	return m_SemiLongAxis;
}

//////////////////////////////////////////////////////////////////////////////
//�T��:
//	��`�̔��Z���̒������擾����
//�߂�l:
//	m_SemiShortAxis:��`�̔��Z���̒���
//////////////////////////////////////////////////////////////////////////////
double BoxClass::GetSemiShortAxis()
{
	return m_SemiShortAxis;
}

//////////////////////////////////////////////////////////////////////////////
//�T��:
//	��`�̔������̃x�N�g�����擾����
//�߂�l:
//	m_SemiLongVector:��`�̔������̃x�N�g��
//////////////////////////////////////////////////////////////////////////////
THREE_DIMENSION_VECTOR BoxClass::GetSemiLongVector()
{
	return m_SemiLongVector;
}

//////////////////////////////////////////////////////////////////////////////
//�T��:
//	��`�̔��Z���̃x�N�g�����擾����
//�߂�l:
//	m_SemiShortVector:��`�̔��Z���̃x�N�g��
//////////////////////////////////////////////////////////////////////////////
THREE_DIMENSION_VECTOR BoxClass::GetSemiShortVector()
{
	return m_SemiShortVector;
}