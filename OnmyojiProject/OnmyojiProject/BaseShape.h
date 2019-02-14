#pragma once

/*
///////////////////////////////////////////
ShapeType�񋓑�

�T�v�@�FCollision�̌`����
//////////////////////////////////////////
*/
enum ShapeType
{
	shape_Rect = 0,
	shape_Circle,
	shapeTypeNum
};

/*
///////////////////////////////////////////
BaseShape�N���X

�T�v�@�F�`������N���X�̃x�[�X�N���X
�g�����F�~�`�A��`�̌`����w�肷��N���X�́A���̃N���X���p������
//////////////////////////////////////////
*/
class BaseShape 
{
public:
	virtual ShapeType GetShapeType() { return shape_Rect; };
};