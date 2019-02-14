#include "Collision.h"

bool Collision::CheckRectAndRect(const RectShape& rect1, const RectShape& rect2)
{
	if (rect1.GetRight() >= rect2.GetLeft() && rect1.GetLeft() <= rect2.GetRight())
	{
		if (rect1.GetBottom() >= rect2.GetTop() && rect1.GetTop() <= rect2.GetBottom())
		{
			return true;
		}
	}
	return false;
}

bool Collision::testRect(int top, int bottom, int left, int right, int top2, int bottom2, int left2, int right2)
{
	if (right >= left2 && left <= right2)
	{
		if (bottom >= top2 && top <= bottom2)
		{
			return true;
		}
	}
	return false;
}

bool Collision::CheckCircleAndCircle(const CircleShape& circle1, const CircleShape& circle2)
{
	float pow_x = (circle2.GetX() - circle1.GetX()) * (circle2.GetX() - circle1.GetX());
	float pow_y = (circle2.GetY() - circle1.GetY()) * (circle2.GetY() - circle1.GetY());

	float pow_raddius = 
		(circle1.GetRaddius() + circle2.GetRaddius()) *
		(circle1.GetRaddius() + circle2.GetRaddius());

	if (pow_x + pow_y <= pow_raddius)
	{
		return true;
	}
	else return false;
}

bool Collision::CheckRectAndCircle(const RectShape& rect, const CircleShape& circle)
{
	return false;
}