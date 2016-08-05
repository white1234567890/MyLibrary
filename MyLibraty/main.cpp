#include "common.h"

//�ϐ��̎��̉�
GAME_MODE GameMode = GAME_INIT;

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	SetMainWindowText( "Laboratory" );//�^�C�g��
	
	SetGraphMode(WINDOW_SIZE_WIDTH , WINDOW_SIZE_HEIGHT , 16);

	ChangeWindowMode(TRUE);//�E�B���h�E���[�h�ŋN��

	SetWindowSize(WINDOW_WIDTH , WINDOW_HEIGHT);

	if(DxLib_Init() == -1) return -1;//DX���C�u�����̏�������

	SetDrawScreen(DX_SCREEN_BACK);//�`����ʂ𗠂�

	//�Q�[�����[�v
	while(ProcessMessage() == 0 && GameMode != 99)
	{
		ClearDrawScreen();//��ʂ̏�����

		switch (GameMode)
		{
		case GAME_INIT:
			break;

		case GAME_MAIN:
			break;
		}

		if(CheckHitKey(KEY_INPUT_ESCAPE))
		{
			GameMode = END;
		}
	
		ScreenFlip();//�o�b�N��\��
	}

	DxLib_End();//DX���C�u�����g�p�̏I������

	return 0;//�\�t�g�̏I��
}