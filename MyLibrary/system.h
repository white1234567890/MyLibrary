#pragma once
#include "common.h"
#include "CircleClass.h"
#include "BoxClass.h"

//列挙体の宣言
typedef enum HIT
{
	NO_HIT,//当たっていない
	RIGHT_HIT,//右に当たっている
	UPPER_RIGHT_HIT,//右上に当たっている
	TOP_HIT,//上に当たっている
	UPPER_LEFT_HIT,//左上に当たっている
	LEFT_HIT,//左に当たっている
	LOWER_LEFT_HIT,//左下に当たっている
	BOTTOM_HIT,//下に当たっている
	LOWER_RIGHT_HIT//右下に当たっている
};

//関数の宣言

///////////////////////////////////////////////////////////////////////////
//概略:
//	乱数を発生させる
//引数:
//	int max_of_randvalue:発生させたい乱数の最大値
//	int min_of_randvalue:発生させたい乱数の最小値
//戻り値:発生させた乱数
///////////////////////////////////////////////////////////////////////////
int GenerateRandValue(int max_of_randvalue , int min_of_randvalue);

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
bool CheckHitCircleandCircle(CircleClass *circle1 , CircleClass *circle2);

//////////////////////////////////////////////////////////////////////////////
//概略:
//	矩形と矩形のあたり判定
//引数:
//	box1:矩形の構造体へのポインタ1
//	box2:矩形の構造体へのポインタ2
//戻り値:	
//	int TRUE:当たった
//	NO_HIT:当たらなかった
//////////////////////////////////////////////////////////////////////////////
bool CheckHitBoxandBox(BoxClass *box1 , BoxClass *box2);

///////////////////////////////////////////////////////////////////////////
//概略:
//	円と矩形のあたり判定
//引数:
//	circle1:円の構造体へのポインタ
//	box1:矩形の構造体へのポインタ
//戻り値:	
//	true:当たった
//	false:当たらなかった
//////////////////////////////////////////////////////////////////////////////
bool CheckHitCircleandBox(CircleClass *circle1 , BoxClass *box1);

//////////////////////////////////////////////////////////////////////////////
//概略:
//	2点間の距離を取る
//引数:
//	POSITION* position1:点1の座標へのポインタ
//	POSITION* position2:点2の座標へのポインタ
//戻り値:
//	2点間の距離(double型)
//////////////////////////////////////////////////////////////////////////////
double GetDistance(POSITION* position1 , POSITION* position2);

//////////////////////////////////////////////////////////////////////////////
//概略:
//	内積計算
//引数:
//	*vector1:ベクトル1
//	*vector2:ベクトル2
//戻り値:
//	内積した値
//////////////////////////////////////////////////////////////////////////////
double InnerProduct(THREE_DIMENSION_VECTOR *vector1 , THREE_DIMENSION_VECTOR *vector2);

//////////////////////////////////////////////////////////////////////////////
//概略:
//	外積計算
//引数:
//	*vector1:ベクトル1
//	*vector2:ベクトル2
//戻り値:
//	外積した値
//////////////////////////////////////////////////////////////////////////////
THREE_DIMENSION_VECTOR CrossProduct(THREE_DIMENSION_VECTOR *vector1 , THREE_DIMENSION_VECTOR *vector2);

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
bool HitBoxandRangeContact(POSITION* object1 , POSITION* object2 , double range);

//////////////////////////////////////////////////////////////////////////////
//概略:
//	2次元ベクトルを回転させる
//引数:
//	double& x:ベクトルのx成分
//	double& y:ベクトルのy成分
//	double angle:回転させる角度(ラジアン)
//////////////////////////////////////////////////////////////////////////////
THREE_DIMENSION_VECTOR RotateVector2(double x ,double y ,double angle);


//////////////////////////////////////////////////////////////////////////////
//概略:
//	二次元ベクトルの角度を取る
//引数:
//	double x:ベクトルのx成分
//	double y:ベクトルのy成分
//戻り値:
//	double angle:ベクトルの角度
//////////////////////////////////////////////////////////////////////////////
double GetVector2Angle(double x , double y);

double InterSectionTime(POSITION* Position_of_Object1 , VELOCITY* Velocity_of_Object1 , POSITION* Position_of_Object2 , VELOCITY* Velocity_of_Object2);

template<typename T>
void ReleaseVector(std::vector<T> &obj)
{
	std::vector<T> NullVector;
	obj.swap(NullVector);
}

double Convert_to_RelativeCoordinates_from_AbusoluteCoordinatesX(double value);

double Convert_to_RelativeCoordinates_from_AbusoluteCoordinatesY(double value);