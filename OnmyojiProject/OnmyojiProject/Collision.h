#pragma once

#include "BaseShape.h"
#include "RectShape.h"
#include "CircleShape.h"

class Collision
{

	bool RectPointAndCircle(const RectPosition& rect,const CirclePosition& circle);
	bool RectVertexAndCircle(const RectPosition& rect,const CirclePosition& circle);

public:
	bool CheckRectAndRect(const RectPosition& rect1, const RectPosition& rect2);
	bool CheckCircleAndCircle(const CirclePosition& circle1, const CirclePosition& circle2);
	bool CheckRectAndCircle(const RectPosition& rect, const CirclePosition& circle);
};