#include <memory>

#include "DxLib.h"
#include "Input.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウ表示
	ChangeWindowMode(true);

	//DXライブラリの初期化処理
	if (DxLib_Init() == -1) return -1;	//エラーが起きたら終了

	//ダブルバッファリング
	//描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0)
	{
		Input::Instance()->InputMemory(); // Inputを更新

		ScreenFlip();	//裏画面を表画面にコピー
		ClearDrawScreen();	//裏画面消す
	}

	DxLib_End();

	return 0;
}