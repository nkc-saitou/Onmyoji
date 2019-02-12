#include <memory>

#include "DxLib.h"
#include "Input.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�\��
	ChangeWindowMode(true);

	//DX���C�u�����̏���������
	if (DxLib_Init() == -1) return -1;	//�G���[���N������I��

	//�_�u���o�b�t�@�����O
	//�`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0)
	{
		Input::Instance()->InputMemory(); // Input���X�V

		ScreenFlip();	//����ʂ�\��ʂɃR�s�[
		ClearDrawScreen();	//����ʏ���
	}

	DxLib_End();

	return 0;
}