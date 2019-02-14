#pragma once

#include "BaseShape.h"

/*
///////////////////////////////////////////
RectShapeクラス

概要　：矩形の形状を指定するためのクラス
使い方：オブジェクトにそれぞれ継承させて使う。
　　　　コンストラクタでｘ、ｙ、半径をそれぞれ指定する必要あり
///////////////////////////////////////////
*/
class RectShape : public BaseShape 
{
protected:

	double shape_top, shape_bottom, shape_left, shape_right;

public:

	RectShape() {};

	ShapeType GetShapeType() override { return shape_Rect; }

	void SetValue(double *top, double *bottom, double *left, double *right)
	{
		this->shape_top		= *top;
		this->shape_bottom	= *bottom;
		this->shape_left	= *left;
		this->shape_right	= *right;
	}

	double GetTop()	   const { return shape_top; }
	double GetBottom() const { return shape_bottom; }
	double GetLeft()   const { return shape_left; }
	double GetRight()  const { return shape_right; }

};