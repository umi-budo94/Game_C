#pragma once
#include "../Base/Base.h"

class Item :public Base {
private:
	//�摜�I�u�W�F�N�g
	CImage m_img;
public:
	Item(const CVector2D& pos);
	void Draw();
	void Collision(Base* b);
};