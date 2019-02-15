#include "Collision.h"

bool Collision::CheckRectAndRect(const RectPosition& rect1, const RectPosition& rect2)
{
	if (rect1.right >= rect2.left && rect1.left <= rect2.right)
	{
		if (rect1.bottom >= rect2.top && rect1.top <= rect2.bottom)
		{
			return true;
		}
	}
	return false;
}


bool Collision::CheckCircleAndCircle(const CirclePosition& circle1, const CirclePosition& circle2)
{
	// sqrt()関数を使うと処理速度が低下するため、使わない方が良い
	float pow_x = (circle2.x - circle1.x) * (circle2.x - circle1.x);
	float pow_y = (circle2.y - circle1.y) * (circle2.y - circle1.y);

	float pow_raddius = 
		(circle1.raddius + circle2.raddius) *
		(circle1.raddius + circle2.raddius);

	// 三平方の定理
	if (pow_x + pow_y <= pow_raddius)
	{
		return true;
	}
	else return false;
}

bool Collision::CheckRectAndCircle(const RectPosition& rect, const CirclePosition& circle)
{
	// http://ftvoid.com/blog/post/300

	RectPointAndCircle(rect, circle);

	if (RectPointAndCircle(rect, circle) || RectVertexAndCircle(rect, circle))
	{
		return true;
	}

	return false;
}

bool Collision::RectPointAndCircle(const RectPosition& rect, const CirclePosition& circle)
{
	if ((circle.x > rect.left) && (circle.x < rect.right) &&
		(circle.y > rect.top - circle.raddius) && (circle.y < rect.bottom + circle.raddius))
	{
		return true;
	}
	else if ((circle.x > rect.left - circle.raddius) && (circle.x < rect.right + circle.raddius) &&
		(circle.y > rect.top) && (circle.y < rect.bottom))
	{
		return true;
	}
	else return false;
}

bool Collision::RectVertexAndCircle(const RectPosition& rect, const CirclePosition& circle)
{
	int rectLeftPow = (rect.left - circle.x) * (rect.left - circle.x);
	int rectRightPow = (rect.right - circle.x) * (rect.right - circle.x);
	int rectTopPow = (rect.top - circle.y) * (rect.top - circle.y);
	int rectBottomPow = (rect.bottom - circle.y) * (rect.bottom - circle.y);

	int raddiusPow = circle.raddius * circle.raddius;

	if (rectLeftPow + rectTopPow < raddiusPow || rectRightPow + rectTopPow < raddiusPow ||
		rectRightPow + rectBottomPow < raddiusPow || rectLeftPow + rectBottomPow < raddiusPow)
	{
		return true;
	}
	else return false;
}