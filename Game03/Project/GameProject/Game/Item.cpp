#include "Item.h"
#include "GameData.h"

Item::Item(const CVector2D& pos) :Base(eType_Item)
{
	//画像複製
	m_img = COPY_RESOURCE("coin", CImage);
	//座標設定
	m_pos = pos;
	//表示サイズ設定
	m_img.SetSize(64, 128);
	//中心位置設定
	m_img.SetCenter(32, 128);
	//当たり判定用矩形
	m_rect = CRect(-32, -128, 32, 0);
	m_img.ChangeAnimation(0);
}

void Item::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	DrawRect();
}

void Item::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Player:
		if (Base::CollisionRect(this, b)) {
			GameData::s_score += 1;
			SetKill();
		}
	break;
	}
}

void Item::Update()
{
	m_img.UpdateAnimation();

	
}
