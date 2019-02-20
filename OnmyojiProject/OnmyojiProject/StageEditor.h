#pragma once

#include "RectShape.h"
#include "Collision.h"
#include <memory>
#include <vector>

using namespace std;

class StageEditor
{
	//スクリーンサイズ
	const int screenScaleX = 1980;
	const int screenScaleY = 1080;

	// イメージのサイズ
	const int setGraphSize = 32;
	const int selectGraphSize = 128;

	// イメージ全体の分割数
	const int allDivision = 5;

	// 横の分割数
	const int divisionX = 5;

	// 縦の分割数
	const int divisionY = 1;

	int nowScreenSizeX;
	int nowScreenSizeY;

	// グラフィックハンドル
	int chipGh[5];

	RectPosition chipPosition;
	RectPosition selectPosition;

	int drawPosX;
	int drawPosY;

	int mousePosX = 0, mousePosY = 0;

	double mapX = screenScaleX / 64;
	double mapY = screenScaleY / 64;

	bool isOnCollision = false;

	vector<vector<int>> chipKindVec = vector<vector<int>>();
	vector<vector<RectPosition>> chipPositionVec = vector<vector<RectPosition>>();


	RectPosition SetChipPosData(int x, int y);

	void ManageChip();
	void SetMapChip();
	void ExportStage();
	void ChangeMapChip(int x, int y, int chipInde, RectPosition chipRectPos);
	void SetMapChipDraw();
	void SelectMapChipDraw();

	bool IsRectMouseOver(RectPosition rectPos);
	bool IsRectClick(RectPosition rectPos);
	bool IsRectEdge(int x, int y);

public:
	StageEditor();
	void Draw();
	void Update();
};