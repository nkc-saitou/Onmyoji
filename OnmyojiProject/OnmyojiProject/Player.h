#pragma once

/*
///////////////////////////////////////////
Direction列挙隊

概要　：移動方向の状態を管理する
///////////////////////////////////////////
*/
enum Direction
{
	up = 0,
	down,
	left,
	right
};

/*
///////////////////////////////////////////
Playerクラス

概要　：プレイヤーの表示や、挙動を制御。
///////////////////////////////////////////
*/
class  Player
{
	// グラフィックハンドル
	int ghPlayer[12];

	// イメージのサイズ。縦横ともに64px
	const int graphSize = 64;

	// イメージ全体の分割数
	const int allDivision = 12;
	// 横の分割数
	const int divisionX = 3;
	// 縦の分割数
	const int divisionY = 4;

	// 移動スピード
	float speed = 3.0f;

	// 移動係数
	float move = 1.0f;

	// アナログスティックの回転度を取得
	int tempMoveX = 0 , tempMoveY = 0;

	// 横方向と縦方向のカウント数
	int xCount = 0, yCount = 0;

	//添え時用変数
	int ix = 0, iy = 0, result = 0;

	// 座標
	int x = 360, y = 200;

	// アナログパッドの回転角度がこの値以上になった場合、移動したとみなされる
	const int defaultValueAngle = 500;

	// 現在の方向
	Direction directionState = down;

public:

	Player();
	void Update();

private:

	void MoveGraphSet(); // 移動した際のイメージの変更処理
	void Draw(); // 表示処理
	void Move(); // 移動処理
};