#pragma once

#include "DxLib.h"
#define SCREEN_HEIGHT_ASPECT 3	//画面縦比
#define SCREEN_WIDTH_ASPECT 4	//画面横比
#define SCREEN_SIZE 200				//画面サイズ
#include "DebugSwitch.h"

#include <vector>

//定数の宣言
const int WINDOW_SIZE_HEIGHT = SCREEN_SIZE * SCREEN_HEIGHT_ASPECT;	//画面サイズ縦
const int WINDOW_SIZE_WIDTH = SCREEN_SIZE * SCREEN_WIDTH_ASPECT;		//画面サイズ横
const int SCREEN_HEIGHT = WINDOW_SIZE_HEIGHT;									//ゲーム画面サイズ縦
const int SCREEN_WIDTH = WINDOW_SIZE_WIDTH / 3 * 2;								//ゲーム画面サイズ横
const int WINDOW_HEIGHT = 600;															//ウィンドウサイズ縦
const int WINDOW_WIDTH = 800;																//ウィンドウサイズ横
const int SCREEN_OVER_LEFT = -100;														//画面外定義
const int SCREEN_OVER_RIGHT = SCREEN_WIDTH + 100;								//画面外定義
const int SCREEN_OVER_UP = - 100;														//画面外定義
const int SCREEN_OVER_DOWN = SCREEN_HEIGHT + 100;								//画面外定義
const int maxdot = 1;																			//出現させるドットの最大数
const int MAX_DROP_SPEED = 20;															//落下速度最大値
const double PLAYER_SPEED = 5;															//プレイヤーの速さ

//列挙体の宣言
enum GAME_MODE
{
	GAME_INIT,	//ゲーム初期化
	GAME_MAIN,	//ゲームメイン
	END = 99		//終了
};

//3次元ベクトル
typedef struct THREE_DIMENSION_VECTOR
{
	double x;	//x座標
	double y;	//y座標
	double z;	//z座標
}THREE_DIMENSION_VECTOR;

//位置
typedef struct POSITION
{
	THREE_DIMENSION_VECTOR m_Vector;	//位置ベクトル
}POSITION;

//速度
typedef struct VELOCITY
{
	THREE_DIMENSION_VECTOR m_Vector;	//速度ベクトル
}VELOCITY;

//加速度
typedef struct ACCELARATION
{
	THREE_DIMENSION_VECTOR m_Vector;	//加速度ベクトル
}ACCELARATION;

//可変長頂点
typedef struct VARIABLE_VERTEX
{
	std::vector<POSITION> m_VertexPosition;	//頂点の座標位置
}SQUAREVERTEX;


//変数の宣言
extern GAME_MODE GameMode;		//ゲームモード指定用変数