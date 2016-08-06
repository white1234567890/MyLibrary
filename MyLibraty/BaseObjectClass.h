#pragma once
#include "common.h"

class BaseObjectClass
{
protected:
	bool m_Flag;	//フラグ
	POSITION m_Position;	//中心座標
	VELOCITY m_Velocity;	//速度
	ACCELARATION m_Accelaration;	//加速度

public:
	BaseObjectClass(void);
	~BaseObjectClass(void);
	
	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	中心座標を取得する
	//戻り値:
	//　m_Position:中心座標
	//////////////////////////////////////////////////////////////////////////////
	POSITION GetPosition();

	virtual bool Initialize(POSITION* position , VELOCITY* velocity , ACCELARATION* accelaration , bool flag = false) = 0;
};

