#pragma once

/*
///////////////////////////////////////////
Direction�񋓑�

�T�v�@�F�ړ������̏�Ԃ��Ǘ�����
///////////////////////////////////////////
*/
enum Direction
{
	up = 0,
	down,
	left,
	right
};

/*
///////////////////////////////////////////
Player�N���X

�T�v�@�F�v���C���[�̕\����A�����𐧌�B
///////////////////////////////////////////
*/
class  Player
{
	// �O���t�B�b�N�n���h��
	int ghPlayer[12];

	// �C���[�W�̃T�C�Y�B�c���Ƃ���64px
	const int graphSize = 64;

	// �C���[�W�S�̂̕�����
	const int allDivision = 12;
	// ���̕�����
	const int divisionX = 3;
	// �c�̕�����
	const int divisionY = 4;

	// �ړ��X�s�[�h
	float speed = 3.0f;

	// �ړ��W��
	float move = 1.0f;

	// �A�i���O�X�e�B�b�N�̉�]�x���擾
	int tempMoveX = 0 , tempMoveY = 0;

	// �������Əc�����̃J�E���g��
	int xCount = 0, yCount = 0;

	//�Y�����p�ϐ�
	int ix = 0, iy = 0, result = 0;

	// ���W
	int x = 360, y = 200;

	// �A�i���O�p�b�h�̉�]�p�x�����̒l�ȏ�ɂȂ����ꍇ�A�ړ������Ƃ݂Ȃ����
	const int defaultValueAngle = 500;

	// ���݂̕���
	Direction directionState = down;

public:

	Player();
	void Update();

private:

	void MoveGraphSet(); // �ړ������ۂ̃C���[�W�̕ύX����
	void Draw(); // �\������
	void Move(); // �ړ�����
};