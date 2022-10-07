#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "Enemy.h"
#include "Goal.h"
#include "Map.h"
#include "Item.h"
#include "../Title/Title.h"
#include "UI.h"
#include"GameData.h"
#include"Attack.h"
Game::Game() :Base(eType_Scene)
{
	//Base::Add(new Field());
	Base::Add(new Map());
	Base::Add(new Player(CVector2D(1280, 540), false));
	Base::Add(new Attack(CVector2D(1280, 560), false));
	Base::Add(new Enemy(CVector2D(2500, 900), false));
	//Base::Add(new Enemy(CVector2D(1280 + 256 * 2, 540), true));
	//Base::Add(new Enemy(CVector2D(1280 + 256 * 3, 540), true));
	Base::Add(new Goal(CVector2D(2048, 540)));
	Base::Add(new Item(CVector2D(2048, 940)));

	Base::Add(new UI());
	GameData::s_score = 0;
	GameData::s_time = 60 * 60 * 10;
}


Game::~Game()
{
	//全てのオブジェクトを破棄
	Base::KillAll();
	//タイトルシーンへ
	Base::Add(new Title());
}

void Game::Update()
{
	//ゴールがなければゲームシーン終了
	if (!Base::FindObject(eType_Goal)) {
		SetKill();
	}
	//プレイヤー死亡　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
	}
}
