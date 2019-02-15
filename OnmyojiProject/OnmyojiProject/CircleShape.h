#pragma once

#include "BaseShape.h"

struct CirclePosition
{
	int x;
	int y;
	int raddius;
};


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

	CirclePosition circlePosition;

	CircleShape() {};

	ShapeType GetShapeType() { return shape_Circle; }

	void SetValue(double *x, double *y, double *raddius)
	{
		this->shape_x = *x;
		this->shape_y = *y;
		this->shape_raddius = *raddius;

		this->circlePosition.x = *x;
		this->circlePosition.y = *y;
		this->circlePosition.raddius = *raddius;
	}

	float GetX() const { return shape_x; }
	float GetY() const { return shape_y; }
	float GetRaddius() const { return shape_raddius; }
};