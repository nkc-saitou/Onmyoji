#include <memory>

#include "DxLib.h"
#include "Input.h"
#include "Player.h"

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

	std::unique_ptr<Player> player(new Player);


	while (ProcessMessage() == 0)
	{

		DrawFormatString(0, 16, GetColor(255, 255, 255), "ThumbLX:%d ThumbLY:%d",
			Input::Instance()->AngleInputX(Pad_1), Input::Instance()->AngleInputY(Pad_1));

		player->Update();

		Input::Instance()->InputMemory(); // Input���X�V
		ScreenFlip();	//����ʂ�\��ʂɃR�s�[
		ClearDrawScreen();	//����ʏ���
	}

	DxLib_End();

	return 0;
}