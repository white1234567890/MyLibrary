#include "system.h"
#include <time.h>
#include <math.h>

//////////////////////////////////////////////////////////////////////////
//�T��:
//	�����𔭐�������
//����:
//	int max_of_randvalue:�����������������̍ő�l
//	int min_of_randvalue:�����������������̍ŏ��l
//�߂�l:��������������
//////////////////////////////////////////////////////////////////////////
int GenerateRandValue(int max_of_randvalue , int min_of_randvalue)
{
	static unsigned int randvalue = 0;			//���������������l��ۑ����Ă������߂̕ϐ�
	static unsigned int randcount = 0;				//���������闐���l�̋K�����𗐂����߂̕ϐ�
	
	//�����̃V�[�h�l�ݒ�
	if(randvalue == 0)
	{
		srand((unsigned int)time(NULL));
	}
	//�������g�p���ăV�[�h�l���Đݒ�
	else
	{
		srand((unsigned int)(randvalue + randcount++));
	}

	//����������������ۑ�����
	randvalue = rand();

	if(min_of_randvalue >= 0)
	{
		return randvalue % ((max_of_randvalue + 1) - min_of_randvalue) + min_of_randvalue;
	}
	else
	{
		if(rand() % 2 == 0)
		{
			return randvalue % ((max_of_randvalue + 1) - min_of_randvalue) + min_of_randvalue;			
		}
		else
		{
			return -((int)randvalue % ((max_of_randvalue + 1) - min_of_randvalue) + min_of_randvalue);
		}
	}
}

///////////////////////////////////////////////////////////////////////////
//�T��:
//	�~�Ɖ~�̓����蔻��
//����:
//	circle1:�~�̍\����1
//	circle2:�~�̍\����2
//�߂�l:
//	true:��������
//	false:�������Ă��Ȃ�
///////////////////////////////////////////////////////////////////////////
bool CheckHitCircleandCircle(CircleClass *circle1 , CircleClass *circle2)
{
	POSITION Circle1Position = circle1->GetPosition();
	POSITION Circle2Position = circle2->GetPosition();
	double Circle1Radius = circle1->GetRadius();
	double Circle2Radius = circle2->GetRadius();

	//�s�^�S���X�̒藝�𗘗p���Ĕ�����s��
	if((Circle2Position.m_Vector.x - Circle1Position.m_Vector.x) * (Circle2Position.m_Vector.x - Circle1Position.m_Vector.x) +
		(Circle2Position.m_Vector.y - Circle1Position.m_Vector.y) * (Circle2Position.m_Vector.y - Circle1Position.m_Vector.y) +
		(Circle2Position.m_Vector.z - Circle1Position.m_Vector.z) * (Circle2Position.m_Vector.z - Circle1Position.m_Vector.z) <=
		(Circle2Radius + Circle1Radius) * (Circle2Radius + Circle1Radius));
	{
		return true;
	}

	return false;
}

//////////////////////////////////////////////////////////////////////////////
//�T��:
//	��`�Ƌ�`�̂����蔻��
//����:
//	BOX* box1:��`�̍\���̂ւ̃|�C���^1
//	BOX* box2:��`�̍\���̂ւ̃|�C���^2
//�߂�l:	
//	int TRUE:��������
//	NO_HIT:������Ȃ�����
//////////////////////////////////////////////////////////////////////////////
int CheckHitBoxandBox(BOX *box1 , BOX *box2)
{
	//���݂���������\�������邩�𔻒肷��
	if(abs(box1->m_Position.m_Vector.x - box2->m_Position.m_Vector.x) < box1->m_SemiLongAxis + box1->m_SemiLongAxis &&
		abs(box1->m_Position.m_Vector.y - box2->m_Position.m_Vector.y) < box1->m_SemiLongAxis + box2->m_SemiLongAxis)
	{
		POSITION LocalVertex_of_Box1Looking_from_Box2;	//box2���猩��box1�̒��_
		POSITION LocalVertex_of_Box2Looking_from_Box1;	//box1���猩��box2�̒��_
		double length;	//����

		//box2����box1�̒��_������ꍇ
		 length = GetDistance(&box1->m_Position , &box2->m_Position);	//box1��box2�̋���

		//�ǂ̒��_����ԋ߂������l����
		for(int i = 1 ; i <= 4 ; i++)
		{
			switch (i)
			{
			case 1:
				if(length < GetDistance(&box1->m_Vertex.m_VertexPosition[0], &box2->m_Vertex.m_VertexPosition[0]))
				{
					//box1.vertex1�̔���
					//box1.vertex1�̃��[�J�����W���o��
					LocalVertex_of_Box1Looking_from_Box2.x = box1->m_vertex.vertex1.x - box2->m_position.x;	//x���W
					LocalVertex_of_Box1Looking_from_Box2.y = box1->m_vertex.vertex1.y - box2->m_position.y;	//y���W

					//length�̍X�V
					length = GetDistance(&box1->m_vertex.vertex1 , &box2->m_position);
				}
				break;

			case 2:
				if(length < GetDistance(&box1->m_vertex.vertex2 , &box2->m_position))
				{
					//box1.vertex2�̔���
					//box1.vertex2�̃��[�J�����W���o��
					LocalVertex_of_Box1Looking_from_Box2.x = box1->m_vertex.vertex2.x - box2->m_position.x;	//x���W
					LocalVertex_of_Box1Looking_from_Box2.y = box1->m_vertex.vertex2.y - box2->m_position.y;	//y���W

					//length�̍X�V
					length = GetDistance(&box1->m_vertex.vertex2 , &box2->m_position);
				}
				break;

			case 3:
				if(length < GetDistance(&box1->m_vertex.vertex3 , &box2->m_position))
				{
					//box1.vertex3�̔���
					//box1.vertex3�̃��[�J�����W���o��
					LocalVertex_of_Box1Looking_from_Box2.x = box1->m_vertex.vertex3.x - box2->m_position.x;	//x���W
					LocalVertex_of_Box1Looking_from_Box2.y = box1->m_vertex.vertex3.y - box2->m_position.y;	//y���W

					//length�̍X�V
					length = GetDistance(&box1->m_vertex.vertex3 , &box2->m_position);
				}
				break;

			case 4:
				if(length < GetDistance(&box1->m_vertex.vertex4 , &box2->m_position))
				{
					//box1.vertex4�̔���
					//box1.vertex4�̃��[�J�����W���o��
					LocalVertex_of_Box1Looking_from_Box2.x = box1->m_vertex.vertex4.x - box2->m_position.x;	//x���W
					LocalVertex_of_Box1Looking_from_Box2.y = box1->m_vertex.vertex4.y - box2->m_position.y;	//y���W

					//length�̍X�V
					length = GetDistance(&box1->m_vertex.vertex4 , &box2->m_position);
				}
				break;
			}
		}


		if(abs(LocalVertex_of_Box1Looking_from_Box2.x) > abs(LocalVertex_of_Box1Looking_from_Box2.y))
		{
			if(abs(LocalVertex_of_Box1Looking_from_Box2.x) < box2->m_SemiLongAxis && abs(LocalVertex_of_Box1Looking_from_Box2.y) < box2->m_semi_minor_axis)
			{
				return TRUE;
			}
		}
		else
		{
			if(abs(LocalVertex_of_Box1Looking_from_Box2.x) < box2->m_semi_minor_axis && abs(LocalVertex_of_Box1Looking_from_Box2.y) < box2->m_SemiLongAxis)
			{
				return TRUE;
			}
		}

		//box1����box2�̒��_������ꍇ
		 length = GetDistance(&box2->m_position , &box1->m_position);	//box1��box2�̋���

		//�ǂ̒��_����ԋ߂������l����
		for(int i = 1 ; i <= 4 ; i++)
		{
			switch (i)
			{
			case 1:
				if(length < GetDistance(&box2->m_vertex.vertex1 , &box1->m_position))
				{
					//box2.vertex1�̔���
					//box2.vertex1�̃��[�J�����W���o��
					LocalVertex_of_Box2Looking_from_Box1.x = box2->m_vertex.vertex1.x - box1->m_position.x;	//x���W
					LocalVertex_of_Box2Looking_from_Box1.y = box2->m_vertex.vertex1.y - box1->m_position.y;	//y���W

					//length�̍X�V
					length = GetDistance(&box2->m_vertex.vertex1 , &box1->m_position);
				}
				break;

			case 2:
				if(length < GetDistance(&box2->m_vertex.vertex2 , &box1->m_position))
				{
					//box2.vertex2�̔���
					//box2.vertex2�̃��[�J�����W���o��
					LocalVertex_of_Box2Looking_from_Box1.x = box2->m_vertex.vertex2.x - box1->m_position.x;	//x���W
					LocalVertex_of_Box2Looking_from_Box1.y = box2->m_vertex.vertex2.y - box1->m_position.y;	//y���W

					//length�̍X�V
					length = GetDistance(&box2->m_vertex.vertex2 , &box1->m_position);
				}
				break;

			case 3:
				if(length < GetDistance(&box2->m_vertex.vertex3 , &box1->m_position))
				{
					//box2.vertex3�̔���
					//box2.vertex3�̃��[�J�����W���o��
					LocalVertex_of_Box2Looking_from_Box1.x = box2->m_vertex.vertex3.x - box1->m_position.x;	//x���W
					LocalVertex_of_Box2Looking_from_Box1.y = box2->m_vertex.vertex3.y - box1->m_position.y;	//y���W

					//length�̍X�V
					length = GetDistance(&box2->m_vertex.vertex3 , &box1->m_position);
				}
				break;

			case 4:
				if(length < GetDistance(&box2->m_vertex.vertex4 , &box1->m_position))
				{
					//box2.vertex4�̔���
					//box2.vertex4�̃��[�J�����W���o��
					LocalVertex_of_Box2Looking_from_Box1.x = box2->m_vertex.vertex4.x - box1->m_position.x;	//x���W
					LocalVertex_of_Box2Looking_from_Box1.y = box2->m_vertex.vertex4.y - box1->m_position.y;	//y���W

					//length�̍X�V
					length = GetDistance(&box2->m_vertex.vertex4 , &box1->m_position);
				}
				break;
			}
		}


		if(abs(LocalVertex_of_Box2Looking_from_Box1.x) > abs(LocalVertex_of_Box2Looking_from_Box1.y))
		{
			if(abs(LocalVertex_of_Box2Looking_from_Box1.x) < box1->m_SemiLongAxis && abs(LocalVertex_of_Box2Looking_from_Box1.y) < box1->m_semi_minor_axis)
			{
				return TRUE;
			}
		}
		else
		{
			if(abs(LocalVertex_of_Box2Looking_from_Box1.x) < box1->m_semi_minor_axis && abs(LocalVertex_of_Box2Looking_from_Box1.y) < box1->m_SemiLongAxis)
			{
				return TRUE;
			}
		}

	}

	return NO_HIT;
}

///////////////////////////////////////////////////////////////////////////
//�T��:
//	�~�Ƌ�`�̂����蔻��
//����:
//	CIRCLE* circle1:�~�̍\���̂ւ̃|�C���^
//	BOX* box1:��`�̍\���̂ւ̃|�C���^
//�߂�l:	
//	int TRUE:��������
//	NO_HIT:������Ȃ�����
///////////////////////////////////////////////////////////////////////////
int CheckHitCircleandBox(CIRCLE *circle1 , BOX *box1)
{
	//���݂���������\�������邩�𔻒肷��
	if(HitBoxandRangeContact(&circle1->m_position , &box1->m_position , circle1->m_radius + GetLength_of_Vector(box1->m_semi_long_vector.x , box1->m_semi_long_vector.y)))
	{
		POSITION LocalVertex_of_Box1Looking_from_Circle1;
		double length;

		//circle1����box1�̒��_������
		length = GetDistance(&circle1->m_position , &box1->m_position);

		//���_�Ɠ������Ă��邩�m�F����
		//��ԋ߂����_�𒲂ׂ�
		for(int i = 1 ; i <= 4 ; i++)
		{
			switch (i)
			{
			case 1:
				if(length < GetDistance(&box1->m_vertex.vertex1 , &circle1->m_position))
				{
					//box1.vertex1�̔���
					//box1.vertex1�̃��[�J�����W���o��
					LocalVertex_of_Box1Looking_from_Circle1.x = box1->m_vertex.vertex1.x - circle1->m_position.x;	//x���W
					LocalVertex_of_Box1Looking_from_Circle1.y = box1->m_vertex.vertex1.y - circle1->m_position.y;	//y���W

					//length�̍X�V
					length = GetDistance(&box1->m_vertex.vertex1 , &circle1->m_position);
				}
				break;

			case 2:
				if(length < GetDistance(&box1->m_vertex.vertex2 , &circle1->m_position))
				{
					//box1.vertex2�̔���
					//box1.vertex2�̃��[�J�����W���o��
					LocalVertex_of_Box1Looking_from_Circle1.x = box1->m_vertex.vertex2.x - circle1->m_position.x;	//x���W
					LocalVertex_of_Box1Looking_from_Circle1.y = box1->m_vertex.vertex2.y - circle1->m_position.y;	//y���W

					//length�̍X�V
					length = GetDistance(&box1->m_vertex.vertex2 , &circle1->m_position);
				}
				break;

			case 3:
				if(length < GetDistance(&box1->m_vertex.vertex3 , &circle1->m_position))
				{
					//box1.vertex3�̔���
					//box1.vertex3�̃��[�J�����W���o��
					LocalVertex_of_Box1Looking_from_Circle1.x = box1->m_vertex.vertex3.x - circle1->m_position.x;	//x���W
					LocalVertex_of_Box1Looking_from_Circle1.y = box1->m_vertex.vertex3.y - circle1->m_position.y;	//y���W

					//length�̍X�V
					length = GetDistance(&box1->m_vertex.vertex3 , &circle1->m_position);
				}
				break;

			case 4:
				if(length < GetDistance(&box1->m_vertex.vertex4 , &circle1->m_position))
				{
					//box1.vertex4�̔���
					//box1.vertex4�̃��[�J�����W���o��
					LocalVertex_of_Box1Looking_from_Circle1.x = box1->m_vertex.vertex4.x - circle1->m_position.x;	//x���W
					LocalVertex_of_Box1Looking_from_Circle1.y = box1->m_vertex.vertex4.y - circle1->m_position.y;	//y���W

					//length�̍X�V
					length = GetDistance(&box1->m_vertex.vertex4 , &circle1->m_position);
				}
				break;
			}
		}

		if(GetLength_of_Vector(LocalVertex_of_Box1Looking_from_Circle1.x , LocalVertex_of_Box1Looking_from_Circle1.y) < circle1->m_radius)
		{
			return TRUE;
		}

		//�ӂƓ������Ă��邩�m�F����
		//�㉺�ӂƂ̂����蔻����m�F����
		if(circle1->m_position.x < box1->m_position.x + abs(box1->m_semi_long_vector.x + box1->m_semi_short_vector.x) && circle1->m_position.x > box1->m_position.x - abs(box1->m_semi_long_vector.x + box1->m_semi_short_vector.x))
		{
			if((circle1->m_position.y - box1->m_position.y) * (circle1->m_position.y - box1->m_position.y) < (circle1->m_radius + abs(box1->m_semi_long_vector.y + box1->m_semi_short_vector.y)) * (circle1->m_radius + abs(box1->m_semi_long_vector.y + box1->m_semi_short_vector.y)))
			{
				return TRUE;
			}
		}
		//���E�ӂƂ̂����蔻����m�F����
		else if(circle1->m_position.y < box1->m_position.y + abs(box1->m_semi_long_vector.y + box1->m_semi_short_vector.y) && circle1->m_position.y > box1->m_position.y - abs(box1->m_semi_long_vector.y + box1->m_semi_short_vector.y))
		{
			if((circle1->m_position.x - box1->m_position.x) * (circle1->m_position.x - box1->m_position.x) < (circle1->m_radius + abs(box1->m_semi_long_vector.x + box1->m_semi_short_vector.x)) * (circle1->m_radius + abs(box1->m_semi_long_vector.x + box1->m_semi_short_vector.x)))
			{
				return TRUE;
			}
		}

		return NO_HIT;
	}

	return NO_HIT;
}

//////////////////////////////////////////////////////////////////////////////
//�T��:
//	2�_�Ԃ̋��������
//����:
//	POSITION* position1:�_1�̍��W�ւ̃|�C���^
//	POSITION* position2:�_2�̍��W�ւ̃|�C���^
//�߂�l:
//	2�_�Ԃ̋���(double�^)
//////////////////////////////////////////////////////////////////////////////
double GetDistance(POSITION* position1 , POSITION* position2)
{
	return sqrt((position1->x - position2->x) * (position1->x - position2->x) + (position1->y - position2->y) * (position1->y - position2->y));
}

//////////////////////////////////////////////////////////////////////////////
//�T��:
//	�x�N�g���̑傫�������
//����:
//	double x:�x�N�g����x����
//	double y:�x�N�g����y����
//�߂�l:
//	�x�N�g���̑傫��(double�^)
//////////////////////////////////////////////////////////////////////////////
double GetLength_of_Vector(double x , double y)
{
	return sqrt(x * x + y * y);
}

//////////////////////////////////////////////////////////////////////////////
//�T��:
//	�����蔻������͈͂����肷��
//����:
//	POSITION* objact1:�I�u�W�F�N�g1�̈ʒu�x�N�g��
//	POSITION* object2:�I�u�W�F�N�g2�̈ʒu�x�N�g��
//	double range:���肷��͈͂̔��a
//�߂�l:
//	bool true:�͈͓��ɂ���
//	bool false:�͈͓��ɂ��Ȃ�
//////////////////////////////////////////////////////////////////////////////
bool HitBoxandRangeContact(POSITION* object1 , POSITION* object2 , double range)
{
	if(GetDistance(object1 , object2) > range)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//////////////////////////////////////////////////////////////////////////////
//�T��:
//	2�����x�N�g������]������
//����:
//	double& x:�x�N�g����x����
//	double& y:�x�N�g����y����
//	double angle:��]������p�x(���W�A��)
//////////////////////////////////////////////////////////////////////////////
void RotateVector2(double& x ,double& y ,double angle)
{
	double TempX = x;	//�ꎞ�I��x���W�����邽�߂̕ϐ�
	double TempY = y;	//�ꎞ�I��y���W�����邽�߂̕ϐ�

	//�s��v�Z
	x = TempX * cos(angle) - TempY * sin(angle);
	y = TempX * sin(angle) + TempY * cos(angle);
}

//////////////////////////////////////////////////////////////////////////////
//�T��:
//	�񎟌��x�N�g���̊p�x�����
//����:
//	double x:�x�N�g����x����
//	double y:�x�N�g����y����
//�߂�l:
//	double angle:�x�N�g���̊p�x
//////////////////////////////////////////////////////////////////////////////
double GetVector2Angle(double x , double y)
{
	return atan2(y , x);
}