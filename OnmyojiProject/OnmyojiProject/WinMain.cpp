#include <memory>

#include "DxLib.h"
#include "Input.h"
#include "Player.h"
#include "Collision.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウ表示
	ChangeWindowMode(true);
	//SetGraphMode(1920, 1080, 32);//画面サイズ指定
	SetGraphMode(1600, 900, 32);//画面サイズ指定

	//DXライブラリの初期化処理
	if (DxLib_Init() == -1) return -1;	//エラーが起きたら終了

	//ダブルバッファリング
	//描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	std::unique_ptr<Player> player(new Player);
	std::unique_ptr<Collision> collision(new Collision);

	while (ProcessMessage() == 0)
	{
		DrawFormatString(0, 16, GetColor(255, 255, 255), "ThumbLX:%d ThumbLY:%d",
			Input::Instance()->AngleInputX(Pad_1), Input::Instance()->AngleInputY(Pad_1));

		player->Update();

		DrawBox(300, 300, 500, 500, GetColor(255, 0, 0), TRUE);

		if (collision->testRect(
			player->GetTop(), player->GetBottom(), player->GetLeft(), player->GetRight(),
			300, 500, 300, 500))
		{
			DrawBox(300, 300, 500, 500, GetColor(255, 255, 0), TRUE);
		}
		else
		{
			DrawBox(300, 300, 500, 500, GetColor(255, 0, 0), TRUE);
		}

		Input::Instance()->InputMemory(); // Inputを更新
		ScreenFlip();	//裏画面を表画面にコピー
		ClearDrawScreen();	//裏画面消す
	}

	DxLib_End();

	return 0;
}