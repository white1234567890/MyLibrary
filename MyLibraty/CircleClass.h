#pragma once
#include "common.h"


class CircleClass
{
private:
	//メンバ変数

	bool m_Flag;	//フラグ
	POSITION m_Position;	//中心座標
	VELOCITY m_Velocity;	//速度
	ACCELARATION m_Accelaration;	//加速度
	double m_Radius;	//半径

public:
	//コンストラクタ
	CircleClass(void);

	//デストラクタ
	~CircleClass(void);

	//メンバ関数

	POSITION GetPosition();
	double GetRadius();
};