#pragma once

/*
///////////////////////////////////////////
RectPosition構造体

概要　：矩形オブジェクトの各座標を記憶する
使い方：当たり判定を実行する際の引数として与える
///////////////////////////////////////////
*/
struct RectPosition
{
	int top;
	int bottom;
	int left;
	int right;
};

/*
///////////////////////////////////////////
RectShapeクラス

概要　：矩形の形状を指定するためのクラス
使い方：オブジェクトにそれぞれ継承させて使う。
　　　　コンストラクタでｘ、ｙ、半径をそれぞれ指定する必要あり
///////////////////////////////////////////
*/
class RectShape
{
public:
	RectPosition rectPosition;

	// 構造体の値を更新
	void SetValue(double *top, double *bottom, double *left, double *right)
	{
		this->rectPosition.top = *top;
		this->rectPosition.bottom = *bottom;
		this->rectPosition.left = *left;
		this->rectPosition.right = *right;
	}

	// ゲッター
	double GetTop()	   const { return rectPosition.top; }
	double GetBottom() const { return rectPosition.bottom; }
	double GetLeft()   const { return rectPosition.left; }
	double GetRight()  const { return rectPosition.right; }

};