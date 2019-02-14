#pragma once

/*
///////////////////////////////////////////
ShapeType列挙隊

概要　：Collisionの形状を列挙
//////////////////////////////////////////
*/
enum ShapeType
{
	shape_Rect = 0,
	shape_Circle,
	shapeTypeNum
};

/*
///////////////////////////////////////////
BaseShapeクラス

概要　：形状をもつクラスのベースクラス
使い方：円形、矩形の形状を指定するクラスは、このクラスを継承する
//////////////////////////////////////////
*/
class BaseShape 
{
public:
	virtual ShapeType GetShapeType() { return shape_Rect; };
};