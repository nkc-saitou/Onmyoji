#pragma once

#include "RectShape.h"
#include "CircleShape.h"
#include "Singleton.h"

/*
///////////////////////////////////////////
Collisionクラス

概要　：２D用の当たり判定処理
使い方：オブジェクトに設定させてあるはずの「RectPosition」または「CirclePosition」を
　　　　引数に与える。
///////////////////////////////////////////
*/

class Collision : public Singleton <Collision>
{
	// 矩形と円形の当たり判定用 http://ftvoid.com/blog/post/300

	// 中心点と長方形の当たり判定
	bool RectPointAndCircle(const RectPosition& rect,const CirclePosition& circle);
	// 角丸の当たり判定
	bool RectVertexAndCircle(const RectPosition& rect,const CirclePosition& circle);

public:
	// 矩形と矩形
	bool CheckRectAndRect(const RectPosition& rect1, const RectPosition& rect2);
	// 円形と円形
	bool CheckCircleAndCircle(const CirclePosition& circle1, const CirclePosition& circle2);
	// 矩形と円形
	bool CheckRectAndCircle(const RectPosition& rect, const CirclePosition& circle);
	// 矩形と点
	bool CheckRectAndPoint(const RectPosition& rect, int x, int y);
};