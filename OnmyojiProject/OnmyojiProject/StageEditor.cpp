#include "StageEditor.h"
#include "DxLib.h"
#include "Input.h"



StageEditor::StageEditor()
{
	// 画像読み込み
	LoadDivGraph("TestMapChip2.png", allDivision, divisionX, divisionY, selectGraphSize, selectGraphSize, chipGh);

	// 現在のスクリーンサイズを取得
	GetDrawScreenSize(&nowScreenSizeX, &nowScreenSizeY);

	SetMapChip();
}

bool StageEditor::IsRectEdge(int x, int y)
{
	if (y == 0 || y == mapY - 1 || x == 0 || x == mapX - 1) return true;
	else return false;
}

void StageEditor::ManageChip()
{

}

RectPosition StageEditor::SetChipPosData(int x, int y)
{
	chipPosition.top = ((nowScreenSizeY / 3) + (setGraphSize * y)) -  (32 / 2);
	chipPosition.left = ((nowScreenSizeX / 3) + (setGraphSize * x)) - (32 / 2);
	chipPosition.bottom = chipPosition.top + 32;
	chipPosition.right = chipPosition.left + 32;



	return chipPosition;
}

void StageEditor::SetMapChip()
{
	vector<int> tempChipKind = vector<int>();
	vector<RectPosition> tempRectPos = vector<RectPosition>();

	// 配列の中身を初期化
	for (int i = 0; i < mapY; ++i)
	{
		for (int j = 0; j < mapX; ++j)
		{
			tempRectPos.push_back(SetChipPosData(j, i));

			if (IsRectEdge(j, i)) tempChipKind.push_back(1);
			else tempChipKind.push_back(0);
		}

		chipKindVec.push_back(tempChipKind);
		chipPositionVec.push_back(tempRectPos);

		tempChipKind.clear();
		tempRectPos.clear();
	}
}

void StageEditor::ExportStage()
{

}

void StageEditor::ChangeMapChip(int x, int y, int chipInde, RectPosition chipRectPos)
{
	// マウスの位置を取得
	GetMousePoint(&mousePosX, &mousePosY);

	if (Collision::Instance()->CheckRectAndPoint(chipRectPos, mousePosX, mousePosY))
	{

		//DrawFormatString(100, 100, GetColor(255, 255, 255), "top:%d left:%d bottom:%d right:%d mouseX:%d mouseY:%d", chipRectPos.top, chipRectPos.left, chipRectPos.bottom, chipRectPos.right, mousePosX, mousePosY);
		if (Input::Instance()->Button(MOUSE_INPUT_LEFT))
		{
			chipKindVec[x][y] = chipInde;
		}
	}
}

bool StageEditor::IsRectClick(RectPosition rectPos)
{
	return false;
}

bool StageEditor::IsRectMouseOver(RectPosition rectPos)
{
	return false;
}

void StageEditor::SetMapChipDraw()
{
	for (int i = 0; i < mapY; i++)
	{
		for (int j = 0; j < mapX; ++j)
		{
			drawPosX = (nowScreenSizeX / 3) + (setGraphSize * j);
			drawPosY = (nowScreenSizeY / 3) + (setGraphSize * i);

			DrawRotaGraph(drawPosX, drawPosY, 0.25, 0.0, chipGh[chipKindVec[i][j]], TRUE);

			//DrawFormatString(100, 100, GetColor(255, 255, 255), "top:%d left:%d bottom:%d right:%d mouseX:%d mouseY:%d",
			//	chipPositionVec[1][1].top, chipPositionVec[1][1].left, chipPositionVec[1][1].bottom, chipPositionVec[1][1].right, mousePosX, mousePosY);

			//DrawBox(chipPositionVec[i][j].left, chipPositionVec[i][j].top, chipPositionVec[i][j].right, chipPositionVec[i][j].bottom, GetColor(255, 255, 0), TRUE);

			if (IsRectEdge(j, i) == false) ChangeMapChip(i, j, 3, chipPositionVec[i][j]);

		}
	}
}

void StageEditor::SelectMapChipDraw()
{

}

void StageEditor::Draw()
{
	SetMapChipDraw();
}

void StageEditor::Update()
{


	Draw();
}