#pragma once

#include "RectShape.h"
#include "Collision.h"
#include <memory>
#include <vector>

using namespace std;

class StageEditor
{
	//�X�N���[���T�C�Y
	const int screenScaleX = 1980;
	const int screenScaleY = 1080;

	// �C���[�W�̃T�C�Y
	const int setGraphSize = 32;
	const int selectGraphSize = 128;

	// �C���[�W�S�̂̕�����
	const int allDivision = 5;

	// ���̕�����
	const int divisionX = 5;

	// �c�̕�����
	const int divisionY = 1;

	int nowScreenSizeX;
	int nowScreenSizeY;

	// �O���t�B�b�N�n���h��
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