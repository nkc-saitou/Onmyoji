#pragma once

#include "BaseShape.h"
#include "RectShape.h"
#include "CircleShape.h"

class Collision
{
public:
	bool CheckRectAndRect(const RectShape& rect1, const RectShape& rect2);
	bool testRect(int top, int bottom, int left, int right, int top2, int bottom2, int left2, int right2);
	bool CheckCircleAndCircle(const CircleShape& circle1, const CircleShape& circle2);
	bool CheckRectAndCircle(const RectShape& rect, const CircleShape& circle);
};