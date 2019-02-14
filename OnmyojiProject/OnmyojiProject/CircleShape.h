#pragma once

#include "BaseShape.h"

/*
///////////////////////////////////////////
CircleShapeクラス

概要　：円の形状を指定するためのクラス
使い方：オブジェクトにそれぞれ継承させて使う。
　　　　コンストラクタでｘ、ｙ、半径をそれぞれ指定する必要あり
///////////////////////////////////////////
*/
class CircleShape : public BaseShape
{
	// ｘ、ｙ、半径
	float shape_x, shape_y, shape_raddius;

public:

	// それぞれの値を（）の値で初期化
	// http://kowaimononantenai.blogspot.com/2012/10/c.html
	CircleShape(float x, float y, float raddius) :
		shape_x(x), shape_y(y), shape_raddius(raddius) {}

	ShapeType GetShapeType() { return shape_Circle; }

	float GetX() const { return shape_x; }
	float GetY() const { return shape_y; }
	float GetRaddius() const { return shape_raddius; }
};