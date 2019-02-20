#pragma once

#include "RectShape.h"
#include "Collision.h"
#include <memory>
#include <vector>

using namespace std;

struct ChipPosition
{
	int drawPosX;
	int drawPosY;
};

class StageEditor
{
	//�X�N���[���T�C�Y
	const int screenScaleX = 1920;
	const int screenScaleY = 1080;

	// �C���[�W�̃T�C�Y
	const int mapChipGraphSize = 32;
	const int selectMapChipGraphSize = 128;

	// �C���[�W�S�̂̕�����
	const int allDivision = 7;

	// ���̕�����
	const int divisionX = 7;

	// �c�̕�����
	const int divisionY = 1;

	// �}�b�v�G�f�B�^�S�̂̔z�u�n�_
	const int mapEditorPosX = screenScaleX / 3;
	const int mapEditorPosY = screenScaleY / 3;

	// �}�b�v�`�b�v�̉摜�z��̓Y��
	int chipIndex = 0;

	// �}�b�v�`�b�v�̃O���t�B�b�N�n���h��
	int chipGh[7];

	// �}�E�X�ʒu�̎擾
	int mousePosX, mousePosY;

	// �}�b�v�`�b�v���c���ɂ��ꂼ��z�u���鐔
	double mapNumX = screenScaleX / 64;
	double mapNumY = screenScaleY / 64;

	RectPosition selectPosition;

	vector<vector<int>> chipKindIndex = vector<vector<int>>();
	vector<vector<RectPosition>> chipRectPosVec = vector<vector<RectPosition>>();
	vector<vector<ChipPosition>> chipPosVec = vector<vector<ChipPosition>>();

	vector<RectPosition> selectChipRectPosVec = vector<RectPosition>();
	vector<ChipPosition> selectChipPosVec = vector<ChipPosition>();


	RectPosition GetChipVertexPos(int x, int y);
	ChipPosition GetChipCenterPos(int x, int y);

	void SetMapChipPlacePos();
	void SetSelectMapChipPlacePos();
	void ExportStage();
	void ChangeMapChip(int x, int y, int chipInde, RectPosition chipRectPos);
	void MapChipDraw();
	void SelectMapChipDraw();

	bool IsRectMouseOver(RectPosition chipRectPos);
	bool IsRectClick(RectPosition chipRectPos);
	bool IsRectEdge(int x, int y);

public:
	StageEditor();
	void Draw();
	void Update();
};