#include "BaseObjectClass.h"

//////////////////////////////////////////////////////////////////////////////
//コンストラクタ
//////////////////////////////////////////////////////////////////////////////
BaseObjectClass::BaseObjectClass(void)
{
}

//////////////////////////////////////////////////////////////////////////////
//デストラクタ
//////////////////////////////////////////////////////////////////////////////
BaseObjectClass::~BaseObjectClass(void)
{
}

//////////////////////////////////////////////////////////////////////////////
//protected関数
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//概略:
//	物体を移動させる
//////////////////////////////////////////////////////////////////////////////
void BaseObjectClass::MoveObject()
{
	m_Position.m_Vector += m_Velocity.m_Vector;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	物体を移動させる（重力を加算する）
//////////////////////////////////////////////////////////////////////////////
void BaseObjectClass::MoveObject(bool grounded_flag)
{
	m_Position.m_Vector += m_Velocity.m_Vector + m_GravityVelocity;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	物体を加速させる
//////////////////////////////////////////////////////////////////////////////
void BaseObjectClass::AccelObject()
{
	m_Velocity.m_Vector += m_Accelaration.m_Vector;
}

//////////////////////////////////////////////////////////////////////////////
//public関数
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//概略:
//	中心座標を取得する
//戻り値:
//　m_Position:中心座標
//////////////////////////////////////////////////////////////////////////////
POSITION BaseObjectClass::GetPosition()
{
	return m_Position;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	速度を取得する
//戻り値:
//	m_Velocity:速度
//////////////////////////////////////////////////////////////////////////////
VELOCITY BaseObjectClass::GetVelocity()
{
	return m_Velocity;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	加速度を取得する
//戻り値:
//	m_Accelaration:加速度
//////////////////////////////////////////////////////////////////////////////
ACCELARATION BaseObjectClass::GetAccelaration()
{
	return m_Accelaration;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	フラグを取得する
//戻り値
//	m_Flag:フラグ
//////////////////////////////////////////////////////////////////////////////
bool BaseObjectClass::GetFlag()
{
	return m_Flag;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	中心座標を代入する
//引数:
//	*position:位置
//////////////////////////////////////////////////////////////////////////////
void BaseObjectClass::SetPosition(POSITION* position)
{
	m_Position = *position;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	速度を代入する
//引数:
//	*velocity:速度
//////////////////////////////////////////////////////////////////////////////
void BaseObjectClass::SetVelocity(VELOCITY* velocity)
{
	m_Velocity = *velocity;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	加速度を代入する
//引数:
//	*accelaration:加速度
//////////////////////////////////////////////////////////////////////////////
void BaseObjectClass::SetAccelaration(ACCELARATION* accelaration)
{
	m_Accelaration = *accelaration;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	フラグを代入する
//引数:
//	flag:フラグ
//////////////////////////////////////////////////////////////////////////////
void BaseObjectClass::SetFlag(bool flag)
{
	m_Flag = flag;
}
//////////////////////////////////////////////////////////////////////////////
//概略:
//	更新（純粋仮想関数）
//////////////////////////////////////////////////////////////////////////////
bool BaseObjectClass::Update()
{
	return true;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	初期化（純粋仮想関数）
//////////////////////////////////////////////////////////////////////////////
bool BaseObjectClass::Initialize()
{
	return true;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	描画（純粋仮想関数）
//////////////////////////////////////////////////////////////////////////////
void BaseObjectClass::Render()
{
}