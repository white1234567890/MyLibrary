#pragma once
#include "BaseObjectClass.h"

class CircleClass:
	public BaseObjectClass
{
private:
	//メンバ変数
	double m_Radius;	//半径

public:
	//コンストラクタ
	CircleClass(void);

	//デストラクタ
	~CircleClass(void);

	//メンバ関数

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	円の半径を取得する
	//戻り値:
	//	m_Radius:円の半径
	//////////////////////////////////////////////////////////////////////////////
	double GetRadius();
};