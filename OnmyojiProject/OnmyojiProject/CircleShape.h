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
CircleShape�N���X

�T�v�@�F�~�̌`����w�肷�邽�߂̃N���X
�g�����F�I�u�W�F�N�g�ɂ��ꂼ��p�������Ďg���B
�@�@�@�@�R���X�g���N�^�ł��A���A���a�����ꂼ��w�肷��K�v����
///////////////////////////////////////////
*/
class CircleShape : public BaseShape
{
	// ���A���A���a
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