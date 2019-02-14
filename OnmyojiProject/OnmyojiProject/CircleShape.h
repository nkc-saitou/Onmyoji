#pragma once

#include "BaseShape.h"

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

	// ���ꂼ��̒l���i�j�̒l�ŏ�����
	// http://kowaimononantenai.blogspot.com/2012/10/c.html
	CircleShape(float x, float y, float raddius) :
		shape_x(x), shape_y(y), shape_raddius(raddius) {}

	ShapeType GetShapeType() { return shape_Circle; }

	float GetX() const { return shape_x; }
	float GetY() const { return shape_y; }
	float GetRaddius() const { return shape_raddius; }
};