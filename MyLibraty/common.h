#pragma once

#include "DxLib.h"
#define SCREEN_HEIGHT_ASPECT 3	//��ʏc��
#define SCREEN_WIDTH_ASPECT 4	//��ʉ���
#define SCREEN_SIZE 200				//��ʃT�C�Y
#include "DebugSwitch.h"

#include <vector>

//�萔�̐錾
const int WINDOW_SIZE_HEIGHT = SCREEN_SIZE * SCREEN_HEIGHT_ASPECT;	//��ʃT�C�Y�c
const int WINDOW_SIZE_WIDTH = SCREEN_SIZE * SCREEN_WIDTH_ASPECT;		//��ʃT�C�Y��
const int SCREEN_HEIGHT = WINDOW_SIZE_HEIGHT;									//�Q�[����ʃT�C�Y�c
const int SCREEN_WIDTH = WINDOW_SIZE_WIDTH / 3 * 2;								//�Q�[����ʃT�C�Y��
const int WINDOW_HEIGHT = 600;															//�E�B���h�E�T�C�Y�c
const int WINDOW_WIDTH = 800;																//�E�B���h�E�T�C�Y��
const int SCREEN_OVER_LEFT = -100;														//��ʊO��`
const int SCREEN_OVER_RIGHT = SCREEN_WIDTH + 100;								//��ʊO��`
const int SCREEN_OVER_UP = - 100;														//��ʊO��`
const int SCREEN_OVER_DOWN = SCREEN_HEIGHT + 100;								//��ʊO��`
const int maxdot = 1;																			//�o��������h�b�g�̍ő吔
const int MAX_DROP_SPEED = 20;															//�������x�ő�l
const double PLAYER_SPEED = 5;															//�v���C���[�̑���

//�񋓑̂̐錾
enum GAME_MODE
{
	GAME_INIT,	//�Q�[��������
	GAME_MAIN,	//�Q�[�����C��
	END = 99		//�I��
};

//3�����x�N�g��
typedef struct THREE_DIMENSION_VECTOR
{
	double x;	//x���W
	double y;	//y���W
	double z;	//z���W
}THREE_DIMENSION_VECTOR;

//�ʒu
typedef struct POSITION
{
	THREE_DIMENSION_VECTOR m_Vector;	//�ʒu�x�N�g��
}POSITION;

//���x
typedef struct VELOCITY
{
	THREE_DIMENSION_VECTOR m_Vector;	//���x�x�N�g��
}VELOCITY;

//�����x
typedef struct ACCELARATION
{
	THREE_DIMENSION_VECTOR m_Vector;	//�����x�x�N�g��
}ACCELARATION;

//�ϒ����_
typedef struct VARIABLE_VERTEX
{
	std::vector<POSITION> m_VertexPosition;	//���_�̍��W�ʒu
}SQUAREVERTEX;


//�ϐ��̐錾
extern GAME_MODE GameMode;		//�Q�[�����[�h�w��p�ϐ�