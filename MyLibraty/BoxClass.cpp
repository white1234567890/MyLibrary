#include "BoxClass.h"
#include "system.h"

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
//private�֐�
//////////////////////////////////////////////////////////////////////////////

bool BoxClass::Initialize()
{
	return true;
}

//////////////////////////////////////////////////////////////////////////////
//public�֐�
//////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////
//�T��:
//	��`��4�̒��_���Z�o����
//////////////////////////////////////////////////////////////////////////////
void BoxClass::SetVertex()
{
	m_Vertex.m_VertexPosition[0].m_Vector.x = m_Position.m_Vector.x + m_SemiLongVector.x + m_SemiShortVector.x;
	m_Vertex.m_VertexPosition[0].m_Vector.y = m_Position.m_Vector.y + m_SemiLongVector.y + m_SemiShortVector.y;
	m_Vertex.m_VertexPosition[1].m_Vector.x = m_Position.m_Vector.x + m_SemiLongVector.x - m_SemiShortVector.x;
	m_Vertex.m_VertexPosition[1].m_Vector.y = m_Position.m_Vector.y + m_SemiLongVector.y - m_SemiShortVector.y;
	m_Vertex.m_VertexPosition[2].m_Vector.x = m_Position.m_Vector.x - m_SemiLongVector.x + m_SemiShortVector.x;
	m_Vertex.m_VertexPosition[2].m_Vector.y = m_Position.m_Vector.y - m_SemiLongVector.y + m_SemiShortVector.y;
	m_Vertex.m_VertexPosition[3].m_Vector.x = m_Position.m_Vector.x - m_SemiLongVector.x - m_SemiShortVector.x;
	m_Vertex.m_VertexPosition[3].m_Vector.y = m_Position.m_Vector.y - m_SemiLongVector.y - m_SemiShortVector.y;
}

//////////////////////////////////////////////////////////////////////////////
//�T��:
//	�X�V
//////////////////////////////////////////////////////////////////////////////
bool BoxClass::Update()
{
	MoveObject();
	SetVertex();
	AccelObject();
	return true;
}

//////////////////////////////////////////////////////////////////////////////
//�T��:
//	������
//����:
//	*position:�ʒu
//	*velocity:���x
//	*accelaration:�����x
//	*semi_long_vector:�������x�N�g��
//	*semi_short_vector:���Z���x�N�g��
//	flag:�t���O
//�߂�l:
//	true:�Ƃ肠����true��Ԃ�
//////////////////////////////////////////////////////////////////////////////
bool BoxClass::Initialize(POSITION* position , VELOCITY* velocity , ACCELARATION* accelaration , THREE_DIMENSION_VECTOR* semi_long_vector , THREE_DIMENSION_VECTOR* semi_short_vector , bool flag)
{
	m_Position = *position;
	m_Velocity = *velocity;
	m_Accelaration = *accelaration;
	m_SemiLongVector = *semi_long_vector;
	m_SemiShortVector = *semi_short_vector;

	m_SemiLongAxis = GetLength_of_Vector(&m_SemiLongVector);
	m_SemiShortAxis = GetLength_of_Vector(&m_SemiShortVector);

	SetVertex();

	return true;
}

//////////////////////////////////////////////////////////////////////////////
//�T��:
//	�`��
//////////////////////////////////////////////////////////////////////////////
void BoxClass::Render()
{
	DrawBox((int)m_Vertex.m_VertexPosition[0].m_Vector.x , (int)m_Vertex.m_VertexPosition[0].m_Vector.y ,
		(int)m_Vertex.m_VertexPosition[3].m_Vector.x , (int)m_Vertex.m_VertexPosition[3].m_Vector.y,
		0xffffff , true);
}