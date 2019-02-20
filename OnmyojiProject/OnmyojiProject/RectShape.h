#pragma once

/*
///////////////////////////////////////////
RectPosition�\����

�T�v�@�F��`�I�u�W�F�N�g�̊e���W���L������
�g�����F�����蔻������s����ۂ̈����Ƃ��ė^����
///////////////////////////////////////////
*/
struct RectPosition
{
	int top;
	int bottom;
	int left;
	int right;
};

/*
///////////////////////////////////////////
RectShape�N���X

�T�v�@�F��`�̌`����w�肷�邽�߂̃N���X
�g�����F�I�u�W�F�N�g�ɂ��ꂼ��p�������Ďg���B
�@�@�@�@�R���X�g���N�^�ł��A���A���a�����ꂼ��w�肷��K�v����
///////////////////////////////////////////
*/
class RectShape
{
public:
	RectPosition rectPosition;

	// �\���̂̒l���X�V
	void SetValue(double *top, double *bottom, double *left, double *right)
	{
		this->rectPosition.top = *top;
		this->rectPosition.bottom = *bottom;
		this->rectPosition.left = *left;
		this->rectPosition.right = *right;
	}

	// �Q�b�^�[
	double GetTop()	   const { return rectPosition.top; }
	double GetBottom() const { return rectPosition.bottom; }
	double GetLeft()   const { return rectPosition.left; }
	double GetRight()  const { return rectPosition.right; }

};