#pragma once

#include "RectShape.h"
#include "CircleShape.h"
#include "Singleton.h"

/*
///////////////////////////////////////////
Collision�N���X

�T�v�@�F�QD�p�̓����蔻�菈��
�g�����F�I�u�W�F�N�g�ɐݒ肳���Ă���͂��́uRectPosition�v�܂��́uCirclePosition�v��
�@�@�@�@�����ɗ^����B
///////////////////////////////////////////
*/

class Collision : public Singleton <Collision>
{
	// ��`�Ɖ~�`�̓����蔻��p http://ftvoid.com/blog/post/300

	// ���S�_�ƒ����`�̓����蔻��
	bool RectPointAndCircle(const RectPosition& rect,const CirclePosition& circle);
	// �p�ۂ̓����蔻��
	bool RectVertexAndCircle(const RectPosition& rect,const CirclePosition& circle);

public:
	// ��`�Ƌ�`
	bool CheckRectAndRect(const RectPosition& rect1, const RectPosition& rect2);
	// �~�`�Ɖ~�`
	bool CheckCircleAndCircle(const CirclePosition& circle1, const CirclePosition& circle2);
	// ��`�Ɖ~�`
	bool CheckRectAndCircle(const RectPosition& rect, const CirclePosition& circle);
	// ��`�Ɠ_
	bool CheckRectAndPoint(const RectPosition& rect, int x, int y);
};