#include "common.h"
#include "DebugRoom.h"

//変数の実体化
GAME_MODE GameMode = GAME_INIT;

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	SetMainWindowText( "Laboratory" );//タイトル
	
	SetGraphMode(WINDOW_SIZE_WIDTH , WINDOW_SIZE_HEIGHT , 16);

	ChangeWindowMode(TRUE);//ウィンドウモードで起動

	SetWindowSize(WINDOW_WIDTH , WINDOW_HEIGHT);

	if(DxLib_Init() == -1) return -1;//DXライブラリの初期処理

	SetDrawScreen(DX_SCREEN_BACK);//描画先画面を裏へ

	//ゲームループ
	while(ProcessMessage() == 0 && GameMode != 99)
	{
		ClearDrawScreen();//画面の初期化

		if(GameMode == GAME_INIT)
		{
			DebugInit();
		}

#ifdef DEBUG
		DebugView();
#endif // DEBUG


		if(CheckHitKey(KEY_INPUT_ESCAPE))
		{
			GameMode = END;
		}
	
		ScreenFlip();//バックを表へ
	}

	DxLib_End();//DXライブラリ使用の終了処理

	return 0;//ソフトの終了
}
