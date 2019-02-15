#include <memory>

#include "DxLib.h"
#include "Input.h"
#include "Player.h"
#include "Collision.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�\��
	ChangeWindowMode(true);
	//SetGraphMode(1920, 1080, 32);//��ʃT�C�Y�w��
	SetGraphMode(1600, 900, 32);//��ʃT�C�Y�w��

	//DX���C�u�����̏���������
	if (DxLib_Init() == -1) return -1;	//�G���[���N������I��

	//�_�u���o�b�t�@�����O
	//�`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	RectPosition testPos;

	testPos.left = 300;
	testPos.top = 300;
	testPos.right = 500;
	testPos.bottom = 500;

	CirclePosition circleTestPos;

	circleTestPos.x = 700;
	circleTestPos.y = 500;
	circleTestPos.raddius = 100;

	std::unique_ptr<Player> player(new Player);
	std::unique_ptr<Collision> collision(new Collision);

	while (ProcessMessage() == 0)
	{
		DrawFormatString(0, 16, GetColor(255, 255, 255), "ThumbLX:%d ThumbLY:%d",
			Input::Instance()->AngleInputX(Pad_1), Input::Instance()->AngleInputY(Pad_1));

		player->Update();

		DrawBox(testPos.left, testPos.top, testPos.right, testPos.bottom, GetColor(255, 0, 0), TRUE);

		DrawCircle(circleTestPos.x, circleTestPos.y, circleTestPos.raddius, GetColor(255, 0, 0), TRUE);

		if(collision->CheckRectAndRect(player->rectPosition, testPos)) 
			DrawBox(300, 300, 500, 500, GetColor(255, 255, 0), TRUE);
		else DrawBox(300, 300, 500, 500, GetColor(255, 0, 0), TRUE);

		if(collision->CheckRectAndCircle(player->rectPosition,circleTestPos))  
			DrawCircle(circleTestPos.x, circleTestPos.y, circleTestPos.raddius, GetColor(255, 255, 0), TRUE);
		else DrawCircle(circleTestPos.x, circleTestPos.y, circleTestPos.raddius, GetColor(255, 0, 0), TRUE);

		Input::Instance()->InputMemory(); // Input���X�V
		ScreenFlip();	//����ʂ�\��ʂɃR�s�[
		ClearDrawScreen();	//����ʏ���
	}

	DxLib_End();

	return 0;
}