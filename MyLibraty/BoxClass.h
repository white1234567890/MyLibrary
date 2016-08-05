#pragma once
#include "common.h"

class BoxClass
{
private:
	//メンバ変数

	bool m_Flag;	//フラグ
	POSITION m_Position;	//中心座標
	VELOCITY m_Velocity;	//速度
	ACCELARATION m_Accelaration;	//加速度
	VARIABLE_VERTEX m_Vertex;	//頂点
	double m_SemiLongAxis;	//半長軸の長さ
	double m_SemiShortAxis;	//半短軸の長さ
	THREE_DIMENSION_VECTOR m_SemiLongVector;	//半長軸ベクトル
	THREE_DIMENSION_VECTOR m_SemiShortVector;	//半短軸ベクトル

public:
	//コンストラクタ
	BoxClass(void);

	//デストラクタ
	~BoxClass(void);
};

