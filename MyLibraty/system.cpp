#include "system.h"
#include <time.h>
#include <math.h>

//////////////////////////////////////////////////////////////////////////
//概略:
//	乱数を発生させる
//引数:
//	int max_of_randvalue:発生させたい乱数の最大値
//	int min_of_randvalue:発生させたい乱数の最小値
//戻り値:発生させた乱数
//////////////////////////////////////////////////////////////////////////
int GenerateRandValue(int max_of_randvalue , int min_of_randvalue)
{
	static unsigned int randvalue = 0;			//発生させた乱数値を保存しておくための変数
	static unsigned int randcount = 0;				//発生させる乱数値の規則性を乱すための変数
	
	//初期のシード値設定
	if(randvalue == 0)
	{
		srand((unsigned int)time(NULL));
	}
	//乱数を使用してシード値を再設定
	else
	{
		srand((unsigned int)(randvalue + randcount++));
	}

	//発生させた乱数を保存する
	randvalue = rand();

	if(min_of_randvalue >= 0)
	{
		return randvalue % ((max_of_randvalue + 1) - min_of_randvalue) + min_of_randvalue;
	}
	else
	{
		if(rand() % 2 == 0)
		{
			return randvalue % ((max_of_randvalue + 1) - min_of_randvalue) + min_of_randvalue;			
		}
		else
		{
			return -((int)randvalue % ((max_of_randvalue + 1) - min_of_randvalue) + min_of_randvalue);
		}
	}
}

///////////////////////////////////////////////////////////////////////////
//概略:
//	円と円の当たり判定
//引数:
//	circle1:円の構造体へのポインタ1
//	circle2:円の構造体へのポインタ2
//戻り値:
//	true:当たった
//	false:当たっていない
///////////////////////////////////////////////////////////////////////////
bool CheckHitCircleandCircle(CircleClass *circle1 , CircleClass *circle2)
{
	POSITION Circle1Position = circle1->GetPosition();
	POSITION Circle2Position = circle2->GetPosition();
	double Circle1Radius = circle1->GetRadius();
	double Circle2Radius = circle2->GetRadius();

	//ピタゴラスの定理を利用して判定を行う
	if((Circle2Position.m_Vector.x - Circle1Position.m_Vector.x) * (Circle2Position.m_Vector.x - Circle1Position.m_Vector.x) +
		(Circle2Position.m_Vector.y - Circle1Position.m_Vector.y) * (Circle2Position.m_Vector.y - Circle1Position.m_Vector.y) +
		(Circle2Position.m_Vector.z - Circle1Position.m_Vector.z) * (Circle2Position.m_Vector.z - Circle1Position.m_Vector.z) <=
		(Circle2Radius + Circle1Radius) * (Circle2Radius + Circle1Radius));
	{
		return true;
	}

	return false;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	矩形と矩形のあたり判定
//引数:
//	BOX* box1:矩形の構造体へのポインタ1
//	BOX* box2:矩形の構造体へのポインタ2
//戻り値:	
//	int TRUE:当たった
//	NO_HIT:当たらなかった
//////////////////////////////////////////////////////////////////////////////
bool CheckHitBoxandBox(BoxClass *box1 , BoxClass *box2)
{
	POSITION Box1Position = box1->GetPosition();
	POSITION Box2Position = box2->GetPosition();
	VARIABLE_VERTEX Box1Vertex;
	VARIABLE_VERTEX Box2Vertex;
	for(int i = 0 ; i < 4 ; i++)
	{
		Box1Vertex.m_VertexPosition.push_back(Box1Position);
		Box2Vertex.m_VertexPosition.push_back(Box2Position);
	}
	Box1Vertex = box1->GetVertex();
	Box2Vertex = box2->GetVertex();
	THREE_DIMENSION_VECTOR Box1SemiLongVector = box1->GetSemiLongVector();
	THREE_DIMENSION_VECTOR Box2SemiLongVector = box2->GetSemiLongVector();
	THREE_DIMENSION_VECTOR Box1SemiShortVector = box1->GetSemiShortVector();
	THREE_DIMENSION_VECTOR Box2SemiShortVector = box2->GetSemiShortVector();

	//お互いが当たる可能性があるかを判定する
	if(abs(Box1Position.m_Vector.x - Box2Position.m_Vector.x) < box1->GetSemiLongAxis() + box2->GetSemiLongAxis() &&
		abs(Box1Position.m_Vector.y - Box2Position.m_Vector.y) < box1->GetSemiShortAxis() + box2->GetSemiLongAxis())
	{
		POSITION LocalVertex_of_Box1Looking_from_Box2;	//box2から見たbox1の頂点
		POSITION LocalVertex_of_Box2Looking_from_Box1;	//box1から見たbox2の頂点
		double length;	//距離

		//box2からbox1の頂点を見る場合
		 length = GetDistance(&Box1Position , &Box2Position);	//box1とbox2の距離

		//どの頂点が一番近いかを考える
		for(int i = 0 ; i < 4 ; i++)
		{
			if(length < GetDistance(&Box1Vertex.m_VertexPosition[i], &Box2Position))
			{
				//一番近い頂点のローカル座標を出す
				LocalVertex_of_Box1Looking_from_Box2.m_Vector.x = Box1Vertex.m_VertexPosition[i].m_Vector.x - Box2Position.m_Vector.x;	//x座標
				LocalVertex_of_Box1Looking_from_Box2.m_Vector.y = Box1Vertex.m_VertexPosition[i].m_Vector.y - Box2Position.m_Vector.y;	//y座標
				LocalVertex_of_Box1Looking_from_Box2.m_Vector.z = Box1Vertex.m_VertexPosition[i].m_Vector.z - Box2Position.m_Vector.z;	//z座標

				//lengthの更新
				length = GetDistance(&Box1Vertex.m_VertexPosition[i] , &Box2Position);
			}
			
			//switch (i)
			//{
			//case 1:
			//	if(length < GetDistance(&Box1Vertex.m_VertexPosition[0], &Box2Vertex.m_VertexPosition[0]))
			//	{
			//		//box1.vertex1の判定
			//		//box1.vertex1のローカル座標を出す
			//		LocalVertex_of_Box1Looking_from_Box2.x = Box1Vertex.vertex1.x - Box2Position.m_Vector.x;	//x座標
			//		LocalVertex_of_Box1Looking_from_Box2.y = Box1Vertex.vertex1.y - Box2Position.m_Vector.y;	//y座標

			//		//lengthの更新
			//		length = GetDistance(&Box1Vertex.vertex1 , &Box2Position.m_Vector);
			//	}
			//	break;

			//case 2:
			//	if(length < GetDistance(&Box1Vertex.vertex2 , &Box2Position.m_Vector))
			//	{
			//		//box1.vertex2の判定
			//		//box1.vertex2のローカル座標を出す
			//		LocalVertex_of_Box1Looking_from_Box2.x = Box1Vertex.vertex2.x - Box2Position.m_Vector.x;	//x座標
			//		LocalVertex_of_Box1Looking_from_Box2.y = Box1Vertex.vertex2.y - Box2Position.m_Vector.y;	//y座標

			//		//lengthの更新
			//		length = GetDistance(&Box1Vertex.vertex2 , &Box2Position.m_Vector);
			//	}
			//	break;

			//case 3:
			//	if(length < GetDistance(&Box1Vertex.vertex3 , &Box2Position.m_Vector))
			//	{
			//		//box1.vertex3の判定
			//		//box1.vertex3のローカル座標を出す
			//		LocalVertex_of_Box1Looking_from_Box2.x = Box1Vertex.vertex3.x - Box2Position.m_Vector.x;	//x座標
			//		LocalVertex_of_Box1Looking_from_Box2.y = Box1Vertex.vertex3.y - Box2Position.m_Vector.y;	//y座標

			//		//lengthの更新
			//		length = GetDistance(&Box1Vertex.vertex3 , &Box2Position.m_Vector);
			//	}
			//	break;

			//case 4:
			//	if(length < GetDistance(&Box1Vertex.vertex4 , &Box2Position.m_Vector))
			//	{
			//		//box1.vertex4の判定
			//		//box1.vertex4のローカル座標を出す
			//		LocalVertex_of_Box1Looking_from_Box2.x = Box1Vertex.vertex4.x - Box2Position.m_Vector.x;	//x座標
			//		LocalVertex_of_Box1Looking_from_Box2.y = Box1Vertex.vertex4.y - Box2Position.m_Vector.y;	//y座標

			//		//lengthの更新
			//		length = GetDistance(&Box1Vertex.vertex4 , &Box2Position.m_Vector);
			//	}
			//	break;
			//}
		}


		if(abs(LocalVertex_of_Box1Looking_from_Box2.m_Vector.x) > abs(LocalVertex_of_Box1Looking_from_Box2.m_Vector.y))
		{
			if(abs(LocalVertex_of_Box1Looking_from_Box2.m_Vector.x) < box2->GetSemiLongAxis() &&
				abs(LocalVertex_of_Box1Looking_from_Box2.m_Vector.y) < box2->GetSemiShortAxis())
			{
				Box1Vertex.m_VertexPosition.clear();
				Box2Vertex.m_VertexPosition.clear();
				return true;
			}
		}
		else
		{
			if(abs(LocalVertex_of_Box1Looking_from_Box2.m_Vector.x) < box2->GetSemiShortAxis() &&
				abs(LocalVertex_of_Box1Looking_from_Box2.m_Vector.y) < box2->GetSemiLongAxis())
			{
				Box1Vertex.m_VertexPosition.clear();
				Box2Vertex.m_VertexPosition.clear();
				return true;
			}
		}

		//box1からbox2の頂点を見る場合
		 length = GetDistance(&Box2Position , &Box1Position);	//box1とbox2の距離

		//どの頂点が一番近いかを考える
		for(int i = 1 ; i <= 4 ; i++)
		{
			if(length < GetDistance(&Box2Vertex.m_VertexPosition[i], &Box1Position))
			{
				//一番近い頂点のローカル座標を出す
				LocalVertex_of_Box2Looking_from_Box1.m_Vector.x = Box2Vertex.m_VertexPosition[i].m_Vector.x - Box1Position.m_Vector.x;	//x座標
				LocalVertex_of_Box2Looking_from_Box1.m_Vector.y = Box2Vertex.m_VertexPosition[i].m_Vector.y - Box1Position.m_Vector.y;	//y座標
				LocalVertex_of_Box2Looking_from_Box1.m_Vector.z = Box2Vertex.m_VertexPosition[i].m_Vector.z - Box1Position.m_Vector.z;	//z座標

				//lengthの更新
				length = GetDistance(&Box2Vertex.m_VertexPosition[i] , &Box1Position);
			}
			//switch (i)
			//{
			//case 1:
			//	if(length < GetDistance(&Box2Vertex.vertex1 , &Box1Position.m_Vector))
			//	{
			//		//box2.vertex1の判定
			//		//box2.vertex1のローカル座標を出す
			//		LocalVertex_of_Box2Looking_from_Box1.x = Box2Vertex.vertex1.x - Box1Position.m_Vector.x;	//x座標
			//		LocalVertex_of_Box2Looking_from_Box1.y = Box2Vertex.vertex1.y - Box1Position.m_Vector.y;	//y座標

			//		//lengthの更新
			//		length = GetDistance(&Box2Vertex.vertex1 , &Box1Position.m_Vector);
			//	}
			//	break;

			//case 2:
			//	if(length < GetDistance(&Box2Vertex.vertex2 , &Box1Position.m_Vector))
			//	{
			//		//box2.vertex2の判定
			//		//box2.vertex2のローカル座標を出す
			//		LocalVertex_of_Box2Looking_from_Box1.x = Box2Vertex.vertex2.x - Box1Position.m_Vector.x;	//x座標
			//		LocalVertex_of_Box2Looking_from_Box1.y = Box2Vertex.vertex2.y - Box1Position.m_Vector.y;	//y座標

			//		//lengthの更新
			//		length = GetDistance(&Box2Vertex.vertex2 , &Box1Position.m_Vector);
			//	}
			//	break;

			//case 3:
			//	if(length < GetDistance(&Box2Vertex.vertex3 , &Box1Position.m_Vector))
			//	{
			//		//box2.vertex3の判定
			//		//box2.vertex3のローカル座標を出す
			//		LocalVertex_of_Box2Looking_from_Box1.x = Box2Vertex.vertex3.x - Box1Position.m_Vector.x;	//x座標
			//		LocalVertex_of_Box2Looking_from_Box1.y = Box2Vertex.vertex3.y - Box1Position.m_Vector.y;	//y座標

			//		//lengthの更新
			//		length = GetDistance(&Box2Vertex.vertex3 , &Box1Position.m_Vector);
			//	}
			//	break;

			//case 4:
			//	if(length < GetDistance(&Box2Vertex.vertex4 , &Box1Position.m_Vector))
			//	{
			//		//box2.vertex4の判定
			//		//box2.vertex4のローカル座標を出す
			//		LocalVertex_of_Box2Looking_from_Box1.x = Box2Vertex.vertex4.x - Box1Position.m_Vector.x;	//x座標
			//		LocalVertex_of_Box2Looking_from_Box1.y = Box2Vertex.vertex4.y - Box1Position.m_Vector.y;	//y座標

			//		//lengthの更新
			//		length = GetDistance(&Box2Vertex.vertex4 , &Box1Position.m_Vector);
			//	}
			//	break;
			//}
		}


		if(abs(LocalVertex_of_Box2Looking_from_Box1.m_Vector.x) > abs(LocalVertex_of_Box2Looking_from_Box1.m_Vector.y))
		{
			if(abs(LocalVertex_of_Box2Looking_from_Box1.m_Vector.x) < box1->GetSemiLongAxis() &&
				abs(LocalVertex_of_Box2Looking_from_Box1.m_Vector.y) < box1->GetSemiShortAxis())
			{
				Box1Vertex.m_VertexPosition.clear();
				Box2Vertex.m_VertexPosition.clear();
				return true;
			}
		}
		else
		{
			if(abs(LocalVertex_of_Box2Looking_from_Box1.m_Vector.x) < box1->GetSemiShortAxis() &&
				abs(LocalVertex_of_Box2Looking_from_Box1.m_Vector.y) < box1->GetSemiLongAxis())
			{
				Box1Vertex.m_VertexPosition.clear();
				Box2Vertex.m_VertexPosition.clear();
				return true;
			}
		}

	}

	return false;
}

///////////////////////////////////////////////////////////////////////////
//概略:
//	円と矩形のあたり判定
//引数:
//	CIRCLE* circle1:円の構造体へのポインタ
//	BOX* box1:矩形の構造体へのポインタ
//戻り値:	
//	int TRUE:当たった
//	NO_HIT:当たらなかった
///////////////////////////////////////////////////////////////////////////
int CheckHitCircleandBox(CIRCLE *circle1 , BOX *box1)
{
	//お互いが当たる可能性があるかを判定する
	if(HitBoxandRangeContact(&circle1->m_position , &box1->m_position , circle1->m_radius + GetLength_of_Vector(box1->m_semi_long_vector.x , box1->m_semi_long_vector.y)))
	{
		POSITION LocalVertex_of_Box1Looking_from_Circle1;
		double length;

		//circle1からbox1の頂点を見る
		length = GetDistance(&circle1->m_position , &box1->m_position);

		//頂点と当たっているか確認する
		//一番近い頂点を調べる
		for(int i = 1 ; i <= 4 ; i++)
		{
			switch (i)
			{
			case 1:
				if(length < GetDistance(&box1->m_vertex.vertex1 , &circle1->m_position))
				{
					//box1.vertex1の判定
					//box1.vertex1のローカル座標を出す
					LocalVertex_of_Box1Looking_from_Circle1.x = box1->m_vertex.vertex1.x - circle1->m_position.x;	//x座標
					LocalVertex_of_Box1Looking_from_Circle1.y = box1->m_vertex.vertex1.y - circle1->m_position.y;	//y座標

					//lengthの更新
					length = GetDistance(&box1->m_vertex.vertex1 , &circle1->m_position);
				}
				break;

			case 2:
				if(length < GetDistance(&box1->m_vertex.vertex2 , &circle1->m_position))
				{
					//box1.vertex2の判定
					//box1.vertex2のローカル座標を出す
					LocalVertex_of_Box1Looking_from_Circle1.x = box1->m_vertex.vertex2.x - circle1->m_position.x;	//x座標
					LocalVertex_of_Box1Looking_from_Circle1.y = box1->m_vertex.vertex2.y - circle1->m_position.y;	//y座標

					//lengthの更新
					length = GetDistance(&box1->m_vertex.vertex2 , &circle1->m_position);
				}
				break;

			case 3:
				if(length < GetDistance(&box1->m_vertex.vertex3 , &circle1->m_position))
				{
					//box1.vertex3の判定
					//box1.vertex3のローカル座標を出す
					LocalVertex_of_Box1Looking_from_Circle1.x = box1->m_vertex.vertex3.x - circle1->m_position.x;	//x座標
					LocalVertex_of_Box1Looking_from_Circle1.y = box1->m_vertex.vertex3.y - circle1->m_position.y;	//y座標

					//lengthの更新
					length = GetDistance(&box1->m_vertex.vertex3 , &circle1->m_position);
				}
				break;

			case 4:
				if(length < GetDistance(&box1->m_vertex.vertex4 , &circle1->m_position))
				{
					//box1.vertex4の判定
					//box1.vertex4のローカル座標を出す
					LocalVertex_of_Box1Looking_from_Circle1.x = box1->m_vertex.vertex4.x - circle1->m_position.x;	//x座標
					LocalVertex_of_Box1Looking_from_Circle1.y = box1->m_vertex.vertex4.y - circle1->m_position.y;	//y座標

					//lengthの更新
					length = GetDistance(&box1->m_vertex.vertex4 , &circle1->m_position);
				}
				break;
			}
		}

		if(GetLength_of_Vector(LocalVertex_of_Box1Looking_from_Circle1.x , LocalVertex_of_Box1Looking_from_Circle1.y) < circle1->m_radius)
		{
			return TRUE;
		}

		//辺と当たっているか確認する
		//上下辺とのあたり判定を確認する
		if(circle1->m_position.x < box1->m_position.x + abs(box1->m_semi_long_vector.x + box1->m_semi_short_vector.x) && circle1->m_position.x > box1->m_position.x - abs(box1->m_semi_long_vector.x + box1->m_semi_short_vector.x))
		{
			if((circle1->m_position.y - box1->m_position.y) * (circle1->m_position.y - box1->m_position.y) < (circle1->m_radius + abs(box1->m_semi_long_vector.y + box1->m_semi_short_vector.y)) * (circle1->m_radius + abs(box1->m_semi_long_vector.y + box1->m_semi_short_vector.y)))
			{
				return TRUE;
			}
		}
		//左右辺とのあたり判定を確認する
		else if(circle1->m_position.y < box1->m_position.y + abs(box1->m_semi_long_vector.y + box1->m_semi_short_vector.y) && circle1->m_position.y > box1->m_position.y - abs(box1->m_semi_long_vector.y + box1->m_semi_short_vector.y))
		{
			if((circle1->m_position.x - box1->m_position.x) * (circle1->m_position.x - box1->m_position.x) < (circle1->m_radius + abs(box1->m_semi_long_vector.x + box1->m_semi_short_vector.x)) * (circle1->m_radius + abs(box1->m_semi_long_vector.x + box1->m_semi_short_vector.x)))
			{
				return TRUE;
			}
		}

		return NO_HIT;
	}

	return NO_HIT;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	2点間の距離を取る
//引数:
//	position1:点1の座標へのポインタ
//	position2:点2の座標へのポインタ
//戻り値:
//	2点間の距離
//////////////////////////////////////////////////////////////////////////////
double GetDistance(POSITION* position1 , POSITION* position2)
{
	return sqrt((position1->m_Vector.x - position2->m_Vector.x) * (position1->m_Vector.x - position2->m_Vector.x) +
		(position1->m_Vector.y - position2->m_Vector.y) * (position1->m_Vector.y - position2->m_Vector.y) +
		(position1->m_Vector.z - position2->m_Vector.z) * (position1->m_Vector.z - position2->m_Vector.z));
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	ベクトルの大きさを取る
//引数:
//	double x:ベクトルのx成分
//	double y:ベクトルのy成分
//戻り値:
//	ベクトルの大きさ(double型)
//////////////////////////////////////////////////////////////////////////////
double GetLength_of_Vector(double x , double y)
{
	return sqrt(x * x + y * y);
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	当たり判定を取る範囲を限定する
//引数:
//	POSITION* objact1:オブジェクト1の位置ベクトル
//	POSITION* object2:オブジェクト2の位置ベクトル
//	double range:限定する範囲の半径
//戻り値:
//	bool true:範囲内にいる
//	bool false:範囲内にいない
//////////////////////////////////////////////////////////////////////////////
bool HitBoxandRangeContact(POSITION* object1 , POSITION* object2 , double range)
{
	if(GetDistance(object1 , object2) > range)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	2次元ベクトルを回転させる
//引数:
//	double& x:ベクトルのx成分
//	double& y:ベクトルのy成分
//	double angle:回転させる角度(ラジアン)
//////////////////////////////////////////////////////////////////////////////
void RotateVector2(double& x ,double& y ,double angle)
{
	double TempX = x;	//一時的にx座標を入れるための変数
	double TempY = y;	//一時的にy座標を入れるための変数

	//行列計算
	x = TempX * cos(angle) - TempY * sin(angle);
	y = TempX * sin(angle) + TempY * cos(angle);
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	二次元ベクトルの角度を取る
//引数:
//	double x:ベクトルのx成分
//	double y:ベクトルのy成分
//戻り値:
//	double angle:ベクトルの角度
//////////////////////////////////////////////////////////////////////////////
double GetVector2Angle(double x , double y)
{
	return atan2(y , x);
}