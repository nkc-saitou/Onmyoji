#pragma once

#include "BaseShape.h"

/*
///////////////////////////////////////////
RectShape�N���X

�T�v�@�F��`�̌`����w�肷�邽�߂̃N���X
�g�����F�I�u�W�F�N�g�ɂ��ꂼ��p�������Ďg���B
�@�@�@�@�R���X�g���N�^�ł��A���A���a�����ꂼ��w�肷��K�v����
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