#include "BoxClass.h"
#include "system.h"

//////////////////////////////////////////////////////////////////////////////
//コンストラクタ
//////////////////////////////////////////////////////////////////////////////
BoxClass::BoxClass(void)
{
	POSITION p;
	for(int i = 0 ; i < 4 ; i++)
	{
		m_Vertex.m_VertexPosition.push_back(p);
	}
}

//////////////////////////////////////////////////////////////////////////////
//デストラクタ
//////////////////////////////////////////////////////////////////////////////
BoxClass::~BoxClass(void)
{
	m_Vertex.m_VertexPosition.clear();
}

//////////////////////////////////////////////////////////////////////////////
//private関数
//////////////////////////////////////////////////////////////////////////////

bool BoxClass::Initialize()
{
	return true;
}

//////////////////////////////////////////////////////////////////////////////
//public関数
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//概略:
//	矩形の4つの頂点を取得する
//戻り値:
//	m_Vertex:矩形の4つの頂点
//////////////////////////////////////////////////////////////////////////////
VARIABLE_VERTEX BoxClass::GetVertex()
{
	return m_Vertex;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	矩形の半長軸の長さを取得する
//戻り値:
//	m_SemiLongAxis:矩形の半長軸の長さ
//////////////////////////////////////////////////////////////////////////////
double BoxClass::GetSemiLongAxis()
{
	return m_SemiLongAxis;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	矩形の半短軸の長さを取得する
//戻り値:
//	m_SemiShortAxis:矩形の半短軸の長さ
//////////////////////////////////////////////////////////////////////////////
double BoxClass::GetSemiShortAxis()
{
	return m_SemiShortAxis;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	矩形の半長軸のベクトルを取得する
//戻り値:
//	m_SemiLongVector:矩形の半長軸のベクトル
//////////////////////////////////////////////////////////////////////////////
THREE_DIMENSION_VECTOR BoxClass::GetSemiLongVector()
{
	return m_SemiLongVector;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	矩形の半短軸のベクトルを取得する
//戻り値:
//	m_SemiShortVector:矩形の半短軸のベクトル
//////////////////////////////////////////////////////////////////////////////
THREE_DIMENSION_VECTOR BoxClass::GetSemiShortVector()
{
	return m_SemiShortVector;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	矩形の4つの頂点を算出する
//////////////////////////////////////////////////////////////////////////////
void BoxClass::SetVertex()
{
	m_Vertex.m_VertexPosition[0].m_Vector.x = m_Position.m_Vector.x + m_SemiLongVector.x + m_SemiShortVector.x;
	m_Vertex.m_VertexPosition[0].m_Vector.y = m_Position.m_Vector.y + m_SemiLongVector.y + m_SemiShortVector.y;
	m_Vertex.m_VertexPosition[1].m_Vector.x = m_Position.m_Vector.x + m_SemiLongVector.x - m_SemiShortVector.x;
	m_Vertex.m_VertexPosition[1].m_Vector.y = m_Position.m_Vector.y + m_SemiLongVector.y - m_SemiShortVector.y;
	m_Vertex.m_VertexPosition[2].m_Vector.x = m_Position.m_Vector.x - m_SemiLongVector.x + m_SemiShortVector.x;
	m_Vertex.m_VertexPosition[2].m_Vector.y = m_Position.m_Vector.y - m_SemiLongVector.y + m_SemiShortVector.y;
	m_Vertex.m_VertexPosition[3].m_Vector.x = m_Position.m_Vector.x - m_SemiLongVector.x - m_SemiShortVector.x;
	m_Vertex.m_VertexPosition[3].m_Vector.y = m_Position.m_Vector.y - m_SemiLongVector.y - m_SemiShortVector.y;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	更新
//////////////////////////////////////////////////////////////////////////////
bool BoxClass::Update()
{
	MoveObject();
	SetVertex();
	AccelObject();
	return true;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	初期化
//引数:
//	*position:位置
//	*velocity:速度
//	*accelaration:加速度
//	*semi_long_vector:半長軸ベクトル
//	*semi_short_vector:半短軸ベクトル
//	flag:フラグ
//戻り値:
//	true:とりあえずtrueを返す
//////////////////////////////////////////////////////////////////////////////
bool BoxClass::Initialize(POSITION* position , VELOCITY* velocity , ACCELARATION* accelaration , THREE_DIMENSION_VECTOR* semi_long_vector , THREE_DIMENSION_VECTOR* semi_short_vector , bool flag)
{
	m_Position = *position;
	m_Velocity = *velocity;
	m_Accelaration = *accelaration;
	m_SemiLongVector = *semi_long_vector;
	m_SemiShortVector = *semi_short_vector;

	m_SemiLongAxis = GetLength_of_Vector(&m_SemiLongVector);
	m_SemiShortAxis = GetLength_of_Vector(&m_SemiShortVector);

	SetVertex();

	return true;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	描画
//////////////////////////////////////////////////////////////////////////////
void BoxClass::Render()
{
	DrawBox((int)m_Vertex.m_VertexPosition[0].m_Vector.x , (int)m_Vertex.m_VertexPosition[0].m_Vector.y ,
		(int)m_Vertex.m_VertexPosition[3].m_Vector.x , (int)m_Vertex.m_VertexPosition[3].m_Vector.y,
		0xffffff , true);
}